#ifndef _UCLOUD_RTC_SDKENGINE_COMMONDEFINE_H_
#define _UCLOUD_RTC_SDKENGINE_COMMONDEFINE_H_

#ifdef _WEBRTC_WIN

#ifdef _EXPORT
#define _EXPORT_API __declspec(dllexport)
#define _EXPORT_API_C extern "C" __declspec(dllexport)
#else
#define _EXPORT_API __declspec(dllimport)
#define _EXPORT_API_C  extern "C" __declspec(dllimport)
#endif

#else
#include <stdint.h>
#define _EXPORT_API __attribute__((visibility ("default")))
#define _EXPORT_API_C extern "C"
#endif

#define  C_API extern "C"
#define MAX_DEVICE_ID_LENGTH 128 
#define MAX_WINDOWS_TILE_LEN 256 

typedef struct {
	char mDeviceName[MAX_DEVICE_ID_LENGTH];
	char mDeviceId[MAX_DEVICE_ID_LENGTH];
}tUCloudRtcDeviceInfo;

typedef struct {
	bool mVideoEnable;
	bool mAudioEnable;
}tUCloudRtcMediaConfig;

typedef struct
{
	long mScreenIndex;
	int  mXpos;
	int mYpos;
	int mWidth;
	int mHeight;
}tUCloudRtcScreenPargram;

typedef enum {
	UCLOUD_RTC_DESKTOPTYPE_SCREEN = 1,
	UCLOUD_RTC_DESKTOPTYPE_WINDOW
}eUCloudRtcDesktopType;

typedef struct
{
	eUCloudRtcDesktopType mType;
	int mDesktopId;
	char mDesktopTitle[MAX_WINDOWS_TILE_LEN];
}tUCloudRtcDeskTopInfo;

typedef enum {
	UCLOUD_RTC_TRACKTYPE_AUDIO = 1,
	UCLOUD_RTC_TRACKTYPE_VIDEO 
}eUCloudRtcTrackType;

typedef enum {
	UCLOUD_RTC_MEDIATYPE_NONE = 0,
	UCLOUD_RTC_MEDIATYPE_VIDEO ,
	UCLOUD_RTC_MEDIATYPE_SCREEN 
}eUCloudRtcMeidaType;

typedef struct {
	const char* mUserId;
	const char* mStreamId;
	bool mEnableVideo;
	bool mEnableAudio;
	bool mEnableData;
	eUCloudRtcMeidaType mStreamMtype;
}tUCloudRtcStreamInfo;

typedef struct {
	const char* mUserId;
	const char* mStreamId;
	bool mMute;
	eUCloudRtcMeidaType mStreamMtype;
}tUCloudRtcMuteSt;

typedef enum {
	UCLOUD_RTC_RECORDPROFILE_SD = 1, //640*360
	UCLOUD_RTC_RECORDPROFILE_HD, //1280*720
	UCLOUD_RTC_RECORDPROFILE_HDPLUS, //1920*1080
}eUCloudRtcRecordProfile;

typedef enum {
	UCLOUD_RTC_RECORDTYPE_AUDIOONLY = 1, 
	UCLOUD_RTC_RECORDTYPE_AUDIOVIDEO
}eUCloudRtcRecordType;

typedef enum {
	UCLOUD_RTC_WATERMARKPOS_LEFTTOP = 1,
	UCLOUD_RTC_WATERMARKPOS_LEFTBOTTOM,
	UCLOUD_RTC_WATERMARKPOS_RIGHTTOP,
	UCLOUD_RTC_WATERMARKPOS_RIGHTBOTTOM
}eUCloudRtcWaterMarkPos;

typedef enum {
	UCLOUD_RTC_WATERMARK_TYPE_NONE = 0 ,
	UCLOUD_RTC_WATERMARK_TYPE_TIME ,
	UCLOUD_RTC_WATERMARK_TYPE_PIC,
	UCLOUD_RTC_WATERMARK_TYPE_TEXT,
}eUCloudRtcWaterMarkType;

typedef enum {
	UCLOUD_RTC_RELAYMODE_AUTO = 1,
	UCLOUD_RTC_RELAYMODE_MANAUL ,
}eUCloudRtcRelayMode;

typedef enum {
	UCLOUD_RTC_RENDER_MODE_DEFAULT = 0, //default full
	UCLOUD_RTC_RENDER_MODE_FIT, 
	UCLOUD_RTC_RENDER_MODE_FILL, 
} eUCloudRtcRenderMode;

typedef enum {
	UCLOUD_RTC_RENDER_TYPE_GDI = 1,
	UCLOUD_RTC_RENDER_TYPE_D3D ,
	UCLOUD_RTC_RENDER_TYPE_EXTEND ,
} eUCloudRtcRenderType;

typedef enum {
	UCLOUD_RTC_LOG_LEVEL_DEBUG = 0,
	UCLOUD_RTC_LOG_LEVEL_INFO,
	UCLOUD_RTC_LOG_LEVEL_WARN,
	UCLOUD_RTC_LOG_LEVEL_ERROR,
	UCLOUD_RTC_LOG_LEVEL_NONE,
} eUCloudRtcLogLevel;


typedef enum {
	UCLOUD_RTC_VIDEO_PROFILE_NONE = -1, 
	UCLOUD_RTC_VIDEO_PROFILE_320_180 = 1,
	UCLOUD_RTC_VIDEO_PROFILE_320_240 = 2,
	UCLOUD_RTC_VIDEO_PROFILE_640_360 = 3,
	UCLOUD_RTC_VIDEO_PROFILE_640_480 = 4,
	UCLOUD_RTC_VIDEO_PROFILE_1280_720 = 5,
	UCLOUD_RTC_VIDEO_PROFILE_1920_1080 = 6,
} eUCloudRtcVideoProfile;

typedef enum {
	UCLOUD_RTC_SCREEN_PROFILE_LOW = 1,
	UCLOUD_RTC_SCREEN_PROFILE_MIDDLE ,
	UCLOUD_RTC_SCREEN_PROFILE_HIGH ,
	UCLOUD_RTC_SCREEN_PROFILE_HIGH_PLUS ,
}eUCloudRtcScreenProfile;

typedef enum {
	UCLOUD_RTC_CHANNEL_TYPE_COMMUNICATION = 0,
	UCLOUD_RTC_CHANNEL_TYPE_BROADCAST
}eUCloudRtcChannelType;

typedef enum {
	UCLOUD_RTC_USER_STREAM_ROLE_PUB = 0, 
	UCLOUD_RTC_USER_STREAM_ROLE_SUB,
	UCLOUD_RTC_USER_STREAM_ROLE_BOTH
} eUCloudRtcUserStreamRole;

typedef enum {
	UCLOUD_RTC_SDK_MODE_NORMAL = 0, 
	UCLOUD_RTC_SDK_MODE_TRIVAL
} eUCloudRtcSdkMode;

typedef enum {
	UCLOUD_RTC_CODEC_VP8 = 1, //default
	UCLOUD_RTC_CODEC_H264
} eUCloudRtcVideoCodec;

typedef enum {
	UCLOUD_RTC_CODEC_OPUS = 1, //default
} eUCloudRtcAudioCodec;

typedef enum {
	UCLOUD_RTC_VIDEO_FRAME_TYPE_I420 = 1,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_I422 ,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_RGB24,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_RGBA,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_ARGB,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_NATIVE
}eUCloudRtcVideoFrameType;

typedef struct {
	const char* mUid;
	eUCloudRtcMeidaType mMediaType;
}tUCloudRtcRelayStream;

typedef enum {
	UCLOUD_RTC_MIX_LAYOUT_NONE,
	UCLOUD_RTC_MIX_LAYOUT_FLOW,	  
	UCLOUD_RTC_MIX_LAYOUT_TEACH,	  
	UCLOUD_RTC_MIX_LAYOUT_CUSTOM,    
	UCLOUD_RTC_MIX_LAYOUT_SPEAKERMODE, 
	UCLOUD_RTC_MIX_LAYOUT_MULTIAUTO, 
	UCLOUD_RTC_MIX_LAYOUT_SINGEVIDEO_AUDIOMIXER, 
}eUCloudRtcMixLayout;

typedef enum 
{
	UCLOUD_RTC_SERVER_GET_FROM_UTECH = 1,
	UCLOUD_RTC_SERVER_GET_FROM_USER_GATEWAY,
	UCLOUD_RTC_SERVER_GET_FROM_USER_DIRECT
}eUCloudRtcServerGetFrom;

typedef enum 
{
	UCLOUD_RTC_CLASS_TYPE_NORMAL = 1,
	UCLOUD_RTC_CLASS_TYPE_AI ,
	UCLOUD_RTC_CLASS_TYPE_RTSP
}eUCloudRtcClassType;

typedef struct {
	const char* mMainviewuid;
	const char* mBucket;
	const char* mBucketRegion;
	eUCloudRtcRecordProfile mProfile;
	eUCloudRtcRecordType mRecordType;
	eUCloudRtcWaterMarkPos mWatermarkPos;
	eUCloudRtcMeidaType mMainviewmediatype;
	eUCloudRtcWaterMarkType mWaterMarkType ;
	const char* mWaterMarkUrl ;
	bool mIsAverage ;
	eUCloudRtcMixLayout mMixerTemplateType ;
	tUCloudRtcRelayStream* mRecordUserList = nullptr ;
	int mRecordUserListSize ;
}tUCloudRtcRecordConfig;

// render view
typedef struct
{
	void* mVideoView;
	const char* mUserId;
	const char* mStreamId;
	eUCloudRtcMeidaType mStreamMtype;
	eUCloudRtcRenderMode mRenderMode;
	eUCloudRtcRenderType mRenderType;
	eUCloudRtcVideoFrameType mVideoFrameType; //when extend render this decide callback frametype
}tUCloudRtcVideoCanvas;

typedef struct
{
	const char* mAppId;
	const char* mRoomId;
	const char* mUserId;
	const char* mUserToken;
	const char* mServerUrl;
}tUCloudRtcAuth;

typedef struct {
	int mDelayMs ;
	const char* mUserId;
	const char* mStreamId;
	int mStreamMtype;
	int mTracktype; // 1 audio 2 video
	int mAudioBitrate = 0;     // audio bitrate,unit:bps
	int mVideoBitrate = 0;
	int mVideoWidth = 0;     // video width
	int mVideoHeight = 0;     // video height
	int mVideoFrameRate = 0;     // video frames per secon
	float mPacketLostRate = 0.0f;
}tUCloudRtcStreamStats;

typedef struct {
	const char* mUserId;
	const char* mStreamId;
	int mStreamMtype;
	int mAvailSendBw = 0;     // unit:bps
	int mRetranBw = 0; // unit:bps
	int mBufferDelayMs = 0 ; // unit:ms
	int mRealEnBw = 0 ;  // unit:bps
}tUCloudRtcUpNetworkSt;

typedef struct {
	const char* mRecordId;
	const char* mFileName;
	const char* mRegion;
	const char* mBucket;
	const char* mRoomid;
}tUCloudRtcRecordInfo;


typedef struct {
	const char* mUserId;
	const char* mStreamId;
	void* mAudioData;
	int mBytePerSimple;
	int mSimpleRate;
	int mChannels;
	int mNumSimples;
	int mRealDataSize ;
	int mDataType ;
}tUCloudRtcAudioFrame;

typedef struct {
	unsigned char* mDataBuf;
	unsigned int mDataSize ; //only for encoded data
	int mWidth;
	int mHeight;
	int mFrameType ; // 0 keyframe 1 not keyframe
	int64_t mTimeStampms ;
	eUCloudRtcVideoFrameType mVideoType;
}tUCloudRtcVideoFrame;

typedef struct {
	char* mFileName;
}tUCloudRtcFileName;

typedef struct {
	const char* mFilePath ;
	const char* mFileName ;
	eUCloudRtcClassType mClassType ;
	eUCloudRtcLogLevel mLogLevel ;
}tUCloudRtcInitContext;

typedef struct {
	int mWidth;
	int mHeight;
	int mFrameRate;
	int mMinBitrate ;
	int mMaxBitrate ;
}tUCloudRtcVideoConfig;

class  _EXPORT_API UCloudRtcAudioFrameCallback
{
public:
	virtual ~UCloudRtcAudioFrameCallback() {}
	virtual void onLocalAudioFrame(tUCloudRtcAudioFrame* audioframe) {}
	virtual void onRemoteMixAudioFrame(tUCloudRtcAudioFrame* audioframe) {}
	virtual void onRemotePeerAudioFrame(tUCloudRtcAudioFrame* audioframe){} ;
};

class _EXPORT_API UCloudRtcVideoFrameObserver 
{
public:
	virtual ~UCloudRtcVideoFrameObserver() {}
	virtual  void onCaptureFrame(unsigned char* videoframe, int buflen) = 0;
};

class _EXPORT_API UCloudRtcExtendVideoRender
{
public:
	virtual ~UCloudRtcExtendVideoRender() {}
	virtual  void onRemoteFrame(const tUCloudRtcVideoFrame* videoframe) = 0;
};

class _EXPORT_API UCloudRtcExtendVideoDecoder
{
public:
	virtual ~UCloudRtcExtendVideoDecoder() {}
	virtual  void onRemoteEncodedFrame(const char* uid, eUCloudRtcMeidaType mtype, const tUCloudRtcVideoFrame* videoframe) = 0;
};

#endif

