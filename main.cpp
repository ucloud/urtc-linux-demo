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
	std::string rtspurl = "" ;
	
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
	if(argc>=4) 
	{
		rtspurl = argv[3];
		std::cout <<"input rtsp url "<< rtspurl <<std::endl ;
	}
	
	RTCEngineBase* urtcengine = RTCEngineFactory::createRtcEngine(RTC_CHANNELTYPE_UCLOUD);
	if (urtcengine)
	{
		g_msghandler = new URTCMsgHandler(urtcengine) ;
		MsgQueue::getInstance()->regEventHandler("", g_msghandler);
		MsgQueue::getInstance()->startMsgQue() ;
        	urtcengine->InitRTCEngine("/data/log", 0);
		urtcengine->EnableRtspSource(1, true, rtspurl) ;
		g_msghandler->setUserId(roomid) ;
        	g_msghandler->setRoomId(userid) ;


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


