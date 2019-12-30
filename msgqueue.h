#ifndef PPSERVER_CPP_MSGQUEUE_H_
#define PPSERVER_CPP_MSGQUEUE_H_

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <map>

#include "RTCDefine.h"
//静态类
class MsgQueue {
public :
    static MsgQueue* getInstance() ;
    static void deleteInstance() ;

	void startMsgQue();
	void stopMsgQue();

    void addAsyncEvent(MsgEvent* woker) ;
    void excuteWorker() ;

	void regEventHandler(std::string id, MsgHandler* handler);
	void unRegEventHandler(std::string id);
protected:
	MsgQueue() ;
    virtual ~MsgQueue() ;
	MsgEvent* getNextEvent() ;
	void clearMsgQue();
	void stopMsgQueInner();
private:
    static MsgQueue* _instance ;
	std::queue<MsgEvent*> _msgque;
	MsgHandler* _msghandler;
	std::thread  _workexcuter;
	static std::mutex _sInitmutex;
	std::mutex  _quemutex;
	std::mutex _startmutex;
	std::condition_variable_any _startcond;
    bool _isStopQue ;
    bool _init ;
};

#endif