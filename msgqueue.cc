#include "msgqueue.h"
#include <iostream>

std::mutex MsgQueue::_sInitmutex;

MsgQueue* MsgQueue::_instance;

MsgQueue::MsgQueue() {
    _isStopQue = true ;
    _init = false ;
}

MsgQueue::~MsgQueue() {

}

MsgQueue* MsgQueue::getInstance() {
	std::unique_lock<std::mutex> initlock(_sInitmutex);
	
    if(_instance) {
        return _instance ;
    }
    _instance = new MsgQueue;
	if (_instance)
	{
		_instance->_init = true;
		return _instance;
	}
	
    return NULL ;
}

void MsgQueue::deleteInstance() {
	_sInitmutex.lock();
    if(_instance) {
		if (!_instance->_isStopQue)
		{
			_instance->stopMsgQueInner();
			_sInitmutex.unlock();
			_instance->_workexcuter.join(); 
		}
		else {
			_sInitmutex.unlock();
		}
		_instance->_init = false;
		delete _instance;
	}
	else {
		_sInitmutex.unlock();
	}
	_instance = NULL;
}

void MsgQueue::addAsyncEvent(MsgEvent* woker) {
	std::unique_lock<std::mutex> initlock(_sInitmutex);
	if (!_isStopQue && _init && woker)
	{
		std::unique_lock<std::mutex> lock(_quemutex);
		
		_msgque.push(woker);
	}
}

void MsgQueue::excuteWorker() {
	_startmutex.lock();
	_startcond.notify_all();
	_startmutex.unlock();

    while(true) {
		_sInitmutex.lock();
		if (!_isStopQue)
		{
			MsgEvent* event = getNextEvent();
			if (event)
			{
				int32_t eventid = event->_eventid;
				std::string msg = event->_msgcontent;

				if (_msghandler)
				{
					_msghandler->onMessage(eventid, msg);
				}
				delete event;
				event = NULL;
			}
		}
		else {
			_sInitmutex.unlock();
			break;
		}
		_sInitmutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

	clearMsgQue();
}

void MsgQueue::regEventHandler(std::string id, MsgHandler* handler) {
	std::unique_lock<std::mutex> initlock(_sInitmutex);
	_msghandler = handler ;
}

void MsgQueue::unRegEventHandler(std::string id) {
	std::unique_lock<std::mutex> initlock(_sInitmutex);
	_msghandler = nullptr ;
}

void MsgQueue::startMsgQue() {
	std::unique_lock<std::mutex> initlock(_sInitmutex);
	if (_init)
	{
		std::unique_lock<std::mutex> lock(_startmutex);
		if (_isStopQue)
		{
			_workexcuter = std::thread(std::bind(&MsgQueue::excuteWorker, this), "msgque");
			_startcond.wait(_startmutex);
			_isStopQue = false;
		}
	}
}

void MsgQueue::stopMsgQue() {
	_sInitmutex.lock();
	stopMsgQueInner();
	_sInitmutex.unlock();
	_workexcuter.join();
}

MsgEvent* MsgQueue::getNextEvent() {
	MsgEvent* worker = NULL;
	if (!_isStopQue && _init)
	{
		std::unique_lock<std::mutex> lock(_quemutex);
		if (_msgque.size()>0)
		{
			worker = _msgque.front();
			_msgque.pop();
		}

	}
    
	return worker;
}

void MsgQueue::clearMsgQue() {
	size_t i = 0 ;
	for (; i<_msgque.size(); i++)
	{
		MsgEvent* event = _msgque.front();
		delete event;
		event = NULL;
		_msgque.pop();
	}
}

void MsgQueue::stopMsgQueInner() {
	_isStopQue = true;
}

