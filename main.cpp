#include "URTCConfig.h"
#include "RTCEngineFactory.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "URTCMsgHandler.h"
#include "msgqueue.h"
#include "URTCCustomAudioSink.h"
#include <iostream>

URTCMsgHandler* g_msghandler = nullptr ;
int main(int argc, char **argv)
{
	std::string cmd = "" ;
	std::string roomid = "ai_room";
	std::string userid = "ai_teacher";
	std::string rtspurl = "" ;
	int classmode = 2  ; 
	
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
		std::cout <<"input rtspurl "<< rtspurl <<std::endl ;
	}
	
	RTCEngineBase* urtcengine = RTCEngineFactory::createRtcEngine(RTC_CHANNELTYPE_UCLOUD);
	URTCCustomAudioSink* audiosink = new URTCCustomAudioSink ;
	if (urtcengine)
	{
		g_msghandler = new URTCMsgHandler(urtcengine) ;
		MsgQueue::getInstance()->regEventHandler("", g_msghandler);
		MsgQueue::getInstance()->startMsgQue() ;
       	        
		if(rtspurl.length() >0) {
			std::cout << "rtsp input " <<rtspurl.data() << std::endl ;
			classmode = 3 ;
			urtcengine->InitRTCEngine("log", roomid.data(),0, classmode) ;
			urtcengine->EnableRtspSource(1, true, rtspurl.data());
			urtcengine->EnableRtspSource(2, true, rtspurl.data());
		}else {
			urtcengine->InitRTCEngine("log", roomid.data(),0, classmode) ;
			urtcengine->EnableRtspSource(1, false, "");
		}

		g_msghandler->setUserId(roomid) ;
       	g_msghandler->setRoomId(userid) ;
	
		tRTCAuthInfo auth;
		auth.mAppid = URTCConfig::getInstance()->getAppId();
		auth.mRoomid = roomid;
		auth.mUserid = userid ;
		std::vector<std::string> files ;
		files.push_back("../resource/test.mp4") ;
		int ret = urtcengine->AddFileList(files, true);
		urtcengine->JoinRoom(auth);	
		while (true)
		{
			std::cout << "please input cmd : send(send message)" << std::endl ;
			std::getline(std::cin, cmd);
			if (cmd.length() > 0) {
				if (cmd == "send") {
					std::string msgid = "123";
					std::string msgdata = "helloworld";
					urtcengine->sendMessage(msgid, msgdata) ;
				}else if (cmd == "leave")
				{
					urtcengine->LeaveRoom(roomid) ;
				}else if (cmd == "join")
				{
					tRTCAuthInfo auth;
					auth.mAppid = URTCConfig::getInstance()->getAppId();
					auth.mRoomid = roomid;
					auth.mUserid = userid ;
					urtcengine->JoinRoom(auth);	
				}else if (cmd == "publish")
				{
					tRTCStreamInfo info;
					info.mEnableVideo = true;
					info.mEnableAudio = false;
					info.mEnableData = false;
					info.mStreamMtype = UCLOUD_RTC_MEDIATYPE_SCREEN;
					info.mUserid = userid;
					urtcengine->PublishStream(info) ;
				}else if (cmd == "unpublish")
				{
					tRTCStreamInfo info;
					info.mStreamMtype = UCLOUD_RTC_MEDIATYPE_SCREEN ;
					info.mUserid = userid;
			        urtcengine->UnPublishStream(info) ;
				}
				
			}
			usleep(1000*1000) ;
		}
	}
    return 0;
}