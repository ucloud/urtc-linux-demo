#ifndef _UMEETING_MSGHANDLER_H_
#define _UMEETING_MSGHANDLER_H_
#include <string>
#include "RTCDefine.h"
#include "RTCEngineBase.h"

class URTCMsgHandler : public MsgHandler{
public:
    URTCMsgHandler(RTCEngineBase* rtcengine) ;
    virtual ~URTCMsgHandler() ;

    void setUserId(std::string& roomid) ;
    void setRoomId(std::string& userid) ;

	void onMessage(int eventid, std::string jsonmsg);

private :
    void onJoinRoomHandler(std::string& jsonmsg) ;
    void onLeaveRoomHandler(std::string& jsonmsg) ;

    void onPublishStreamHandler(std::string& jsonmsg) ;
    void onUnPublishStreamHandler(std::string& jsonmsg) ;

    void onFileDataBeginHandler(std::string& jsonmsg) ;
    void onFileDataEndHandler(std::string& jsonmsg) ;
    void onFileListEndHandler(std::string& jsonmsg) ;

private:
    RTCEngineBase* mRtcengine ;
    std::string mRoomId ;
    std::string mUserId ;
};
#endif

