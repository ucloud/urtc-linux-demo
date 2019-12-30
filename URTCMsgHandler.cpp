#include "URTCMsgHandler.h"
#include "RTCEventDefine.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"  
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "URTCConfig.h"


URTCMsgHandler::URTCMsgHandler(RTCEngineBase* rtcengine)  {
    mRtcengine = rtcengine ;
    mRoomId = "" ;
    mUserId = "" ;
}

URTCMsgHandler::~URTCMsgHandler() 
{

}

void URTCMsgHandler::setUserId(std::string& userid) 
{
    mUserId = userid ;
}

void URTCMsgHandler::setRoomId(std::string& roomid) 
{
    mRoomId = roomid ;
}

void URTCMsgHandler::onMessage(int eventid, std::string jsonmsg) 
{
    switch (eventid)
    {
    case URTC_EVENT_MSG_JOINROOM_RSP:
        onJoinRoomHandler(jsonmsg) ;
        break;
    case URTC_EVENT_MSG_LEAVEROOM_RSP :
        onLeaveRoomHandler(jsonmsg) ;
        break;
    case URTC_EVENT_MSG_LOCALPUBLISH_RSP:
        onPublishStreamHandler(jsonmsg) ;
        break;
    case URTC_EVENT_MSG_LOCALUNPUBLISH_RSP :
        onUnPublishStreamHandler(jsonmsg) ;
        break;
    case URTC_EVENT_MSG_AI_TEACHER_FILE_BEGIN:
        onFileDataBeginHandler(jsonmsg) ;
        break;
    case URTC_EVENT_MSG_AI_TEACHER_FILE_END :
        onFileDataEndHandler(jsonmsg) ;
        break;
    case URTC_EVENT_MSG_AI_TEACHER_FILE_LIST_END :
        onFileListEndHandler(jsonmsg) ;
        break;
    
    default:
        break;
    }
}

void URTCMsgHandler::onJoinRoomHandler(std::string& jsonmsg) 
{
    tRTCStreamInfo info;
    info.mEnableVideo = true;
    info.mEnableAudio = true;
    info.mEnableData = false;
    info.mStreamMtype = UCLOUD_RTC_MEDIATYPE_VIDEO;
    info.mUserid = mUserId;
    mRtcengine->PublishStream(info) ;
}

void URTCMsgHandler::onLeaveRoomHandler(std::string& jsonmsg) 
{

}

void URTCMsgHandler::onPublishStreamHandler(std::string& jsonmsg) 
{

}

void URTCMsgHandler::onUnPublishStreamHandler(std::string& jsonmsg) 
{

}

void URTCMsgHandler::onFileDataBeginHandler(std::string& jsonmsg) 
{

}

void URTCMsgHandler::onFileDataEndHandler(std::string& jsonmsg) 
{

}

void URTCMsgHandler::onFileListEndHandler(std::string& jsonmsg) 
{
    if (mRtcengine)
    {
        tRTCStreamInfo info;
        info.mStreamMtype = UCLOUD_RTC_MEDIATYPE_VIDEO;
        info.mUserid = "";
        mRtcengine->UnPublishStream(info) ;
    }
    
}


