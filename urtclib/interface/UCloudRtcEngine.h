// interfalce desc
#ifndef _UCLOUD_RTC_ENGINE_SDK_H_
#define _UCLOUD_RTC_ENGINE_SDK_H_

#include "UCloudRtcComDefine.h"

class _EXPORT_API  UCloudRtcEventListener
{
public:
	virtual ~UCloudRtcEventListener() {}
	virtual void onServerDisconnect() {}
	//rtc engine
	virtual void onJoinRoom(int code, const char* msg, const char* uid, const char* roomid) {}
	virtual void onLeaveRoom(int code, const char* msg, const char* uid, const char* roomid) {}

	virtual void onRejoining(const char* uid, const char* roomid) {}
	virtual void onReJoinRoom(const char* uid, const char* roomid) {}

	virtual void onLocalPublish(const int code, const char* msg, tUCloudRtcStreamInfo& info) {}
	virtual void onLocalUnPublish(const int code, const char* msg, tUCloudRtcStreamInfo& info) {}

	virtual void onRemoteUserJoin(const char* uid) {}
	virtual void onRemoteUserLeave(const char* uid,int reson) {}

	virtual void onRemotePublish(tUCloudRtcStreamInfo& info) {}
	virtual void onRemoteUnPublish(tUCloudRtcStreamInfo& info) {}

	virtual void onSubscribeResult(const int code, const char* msg, tUCloudRtcStreamInfo& info) {}
	virtual void onUnSubscribeResult(const int code, const char* msg, tUCloudRtcStreamInfo& info) {}

	virtual void onLocalStreamMuteRsp(const int code, const char* msg,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute) {}
	virtual void onRemoteStreamMuteRsp(const int code, const char* msg, const char* uid,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute) {}
	virtual void onRemoteTrackNotify(const char* uid,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute) {}

	virtual void onStartRecord(const int code, const char* msg, tUCloudRtcRecordInfo& info) {}
	virtual void onStopRecord(const int code, const char* msg, const char* recordid) {}

	virtual void onSendRTCStats(tUCloudRtcStreamStats& rtstats) {}
	virtual void onRemoteRTCStats(tUCloudRtcStreamStats rtstats) {}
	virtual void onRemoteAudioLevel(const char* uid, int volume) {}

	virtual void onUpNetworkState(tUCloudRtcUpNetworkSt& rtcst) {}

	virtual void onLocalAudioLevel(int volume) {}
	virtual void onKickoff(int code) {}
	virtual void onWarning(int warn) {}
	virtual void onError(int error) {}

	//for AI class
	virtual void onFileOpenError(const char* filename, int code) {}
	virtual void onFileDataBegin(const char* filename) {}
	virtual void onFileDataEnd(const char* filename) {}
	virtual void onFileListEnd(const char* filename) {}

	virtual void onSendMsgResult(int code , const char* msg, const char* msgid, const char* msgdata){}
	virtual void onUserMsgNotify(const char* msgfrom, const char* msgdata){}
};

class _EXPORT_API UCloudRtcEngine
{
public:
	static UCloudRtcEngine *sharedInstance();
	static UCloudRtcEngine *sharedInstance(tUCloudRtcInitContext& initcontext);
	static void destroy();
	static const char *getSdkVersion();
	virtual void setLogLevel(eUCloudRtcLogLevel level) = 0;
	virtual int setChannelType(eUCloudRtcChannelType roomtype) = 0;
	virtual void regRtcEventListener(UCloudRtcEventListener* listener) = 0;

	virtual int setSdkMode(eUCloudRtcSdkMode mode) = 0;
	virtual int setStreamRole(eUCloudRtcUserStreamRole role) = 0;
	virtual void setTokenSecKey(const char* seckey) = 0;
	virtual int setAutoPublishSubscribe(bool autoPub, bool autoSub) = 0;
	virtual int setAudioOnlyMode(bool audioOnly) = 0;
	virtual int setVideoCodec(eUCloudRtcVideoCodec codec) = 0;

	virtual int enableExtendRtspVideocapture(eUCloudRtcMeidaType type, bool enable, const char* rtspurl) = 0;
	virtual int enableExtendVideocapture(bool enable) = 0;
	virtual int enableExtendVideocaptureAsScreen(bool enable) = 0;
	virtual int enableExtendAudiocapture(bool enable) = 0;
	virtual int enableCameraAsScreen(bool enable, eUCloudRtcScreenProfile profile, tUCloudRtcDeviceInfo& info) = 0;
	
	virtual void regAudioFrameCallback(UCloudRtcAudioFrameCallback* callback) = 0;
	virtual void regEncodedFrameCallback(UCloudRtcExtendVideoDecoder* callback)  = 0 ;

	virtual int startAudioMixing(const char* filepath, bool replace, bool loop,float musicvol) = 0;
	virtual int stopAudioMixing() = 0;
	
	//for AI class
	virtual int addMp4File(tUCloudRtcFileName* filelist, int listsize, bool cleanup) = 0;

	//for private 
	virtual int setServerGetFrom(eUCloudRtcServerGetFrom from) = 0;
	virtual int setServerUrl(const char* serverurl) = 0;

	virtual int joinChannel(tUCloudRtcAuth& auth) = 0;
	virtual int leaveChannel() = 0;

	virtual int sendMessage(const char* msgid, const char* msgdata) = 0;

	virtual int getDesktopNums() = 0;
	virtual int getDesktopInfo(int pos, tUCloudRtcDeskTopInfo& info) = 0;
	virtual int getWindowNums() = 0;
	virtual int getWindowInfo(int pos, tUCloudRtcDeskTopInfo& info) = 0;
	virtual int setUseDesktopCapture(eUCloudRtcDesktopType desktoptype) = 0;
	virtual void setDesktopProfile(eUCloudRtcScreenProfile profile) = 0;
	virtual void setCaptureScreenPagrams(tUCloudRtcScreenPargram& pgram) = 0;

	virtual void pushVideoFrameData(eUCloudRtcMeidaType mediatype, tUCloudRtcVideoFrame* frame) = 0 ;
	virtual void pushAudioFrameData(tUCloudRtcAudioFrame* frame) = 0 ;

	virtual int muteCamBeforeJoin(bool mute) = 0;
	virtual int muteMicBeforeJoin(bool mute) = 0;
	virtual void setVideoProfile(eUCloudRtcVideoProfile profile) = 0;
	virtual void setVideoProfile(eUCloudRtcVideoProfile profile, tUCloudRtcVideoConfig& videoconfig) = 0;
	virtual int switchCamera(tUCloudRtcDeviceInfo& info) = 0;
	virtual int publish(eUCloudRtcMeidaType type, bool hasvideo, bool hasaudio) = 0; 
	virtual int unPublish(eUCloudRtcMeidaType type) = 0;
	virtual int startPreview(tUCloudRtcVideoCanvas& view) = 0;
	virtual int stopPreview(tUCloudRtcVideoCanvas& view) = 0;
	virtual int muteLocalMic(bool mute) = 0;
	virtual int muteLocalVideo(bool mute, eUCloudRtcMeidaType streamtype) = 0;

	virtual int subscribe(tUCloudRtcStreamInfo& info) = 0;
	virtual int unSubscribe(tUCloudRtcStreamInfo& info) = 0;
	virtual int startRemoteView(tUCloudRtcVideoCanvas& view) = 0;
	virtual int stopRemoteView(tUCloudRtcVideoCanvas& view) = 0;
	virtual int muteRemoteAudio(tUCloudRtcMuteSt& info, bool mute) = 0;
	virtual int muteRemoteVideo(tUCloudRtcMuteSt& info, bool mute) = 0;
	virtual int enableAllAudioPlay(bool enable) = 0;
	
	virtual int enableAudioRecord(bool enable) = 0;
	virtual int enableAudioPlay(const char* uid, bool enable) = 0;

	virtual int startRecord(tUCloudRtcRecordConfig& recordconfig) = 0;
	virtual int stopRecord() = 0;

	virtual int configLocalCameraPublish(bool enable) = 0;
	virtual bool isLocalCameraPublishEnabled() = 0;
	virtual int configLocalScreenPublish(bool enable) = 0;
	virtual bool isLocalScreenPublishEnabled() = 0;
	virtual int configLocalAudioPublish(bool enable) = 0;
	virtual bool isLocalAudioPublishEnabled() = 0;

	virtual bool isAutoPublish() = 0;
	virtual bool isAutoSubscribe() = 0;
	virtual bool isAudioOnly() = 0;

protected:
	virtual ~UCloudRtcEngine() {}
};

#endif
