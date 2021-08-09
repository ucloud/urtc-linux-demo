#ifndef _UMEETING_URTCCUSTOMEAUDIOSINK_H_
#define _UMEETING_URTCCUSTOMEAUDIOSINK_H_

#include "UCloudRtcEngine.h"
#include "RTCDefine.h"
#include "RTCEventDefine.h"
#include <string>
#include <list>


class URTCCustomAudioSink : public UCloudRtcAudioFrameCallback {
public:
	URTCCustomAudioSink();
	virtual ~URTCCustomAudioSink() {}
	virtual void onLocalAudioFrame(tUCloudRtcAudioFrame* audioframe)  ;
	virtual void onRemoteMixAudioFrame(tUCloudRtcAudioFrame* audioframe)  ;
	virtual void onRemotePeerAudioFrame(tUCloudRtcAudioFrame* audioframe) ;

};

#endif
