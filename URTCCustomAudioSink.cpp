#include "URTCCustomAudioSink.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

URTCCustomAudioSink::URTCCustomAudioSink()
{

}

void URTCCustomAudioSink::onLocalAudioFrame(tUCloudRtcAudioFrame* audioframe)  
{

}

void URTCCustomAudioSink::onRemoteMixAudioFrame(tUCloudRtcAudioFrame* audioframe)  
{
	//8khz 1channels 16bit 10ms data
	// printf(" URTCCustomAudioSink::onRemoteMixAudioFrame(tUCloudRtcAudioFrame* audioframe) \n") ;
	// printf(" audioframe simplerate = %d && audioframe channels = %d && audioframe simples = %d \n", audioframe->mSimpleRate, audioframe->mChannels, audioframe->mNumSimples) ;
}

void URTCCustomAudioSink::onRemotePeerAudioFrame(tUCloudRtcAudioFrame* audioframe) 
{
	//
	//printf(" URTCCustomAudioSink::onRemotePeerAudioFrame(tUCloudRtcAudioFrame* audioframe) \n") ;
}



