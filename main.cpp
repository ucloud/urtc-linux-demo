#include "URTCConfig.h"
#include "RTCEngineFactory.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "URTCMsgHandler.h"
#include "msgqueue.h"
#include <iostream>

URTCMsgHandler* g_msghandler = nullptr ;

int main(int argc, char **argv)
{
	std::string roomid = "airoom" ;
	std::string userid = "ai_teacher" ;
	std::string cmd = "" ;
	
	if(argc>=2) 
	{
		roomid = argv[1];
		std::cout <<"input roomid "<< roomid <<std::endl ;
	}

	if(argc>=3) 
	{
		userid = argv[2];
		std::cout <<"input userid "<< userid <<std::endl ;
	}

	
	RTCEngineBase* urtcengine = RTCEngineFactory::createRtcEngine(RTC_CHANNELTYPE_UCLOUD);
	if (urtcengine)
	{
		g_msghandler = new URTCMsgHandler(urtcengine) ;
		MsgQueue::getInstance()->regEventHandler("", g_msghandler);
		MsgQueue::getInstance()->startMsgQue() ;
        urtcengine->InitRTCEngine(nullptr);

		g_msghandler->setUserId(roomid) ;
        g_msghandler->setRoomId(userid) ;

		std::vector<std::string> files ;
		files.push_back("./resource/test.mp4") ;
		int ret = urtcengine->AddFileList(files, false);

		tRTCAuthInfo auth;
		auth.mAppid = URTCConfig::getInstance()->getAppId();
		auth.mRoomid = roomid;
		auth.mUserid = userid ;
		urtcengine->JoinRoom(auth);	
		while (true)
		{
			usleep(1000*1000) ;
		}
	}
    return 0;
}


