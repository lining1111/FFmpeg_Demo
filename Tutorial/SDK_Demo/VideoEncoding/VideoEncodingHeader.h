#pragma once
#ifndef _VIDEO_ENCODING_HEADER_
#define _VIDEO_ENCODING_HEADER_

extern "C"
{
	#include "libavutil/opt.h"
	#include "libavcodec/avcodec.h"
	#include "libavutil/channel_layout.h"
	#include "libavutil/common.h"
	#include "libavutil/imgutils.h"
	#include "libavutil/mathematics.h"
	#include "libavutil/samplefmt.h"
}


/*************************************************
	Struct:			CodecCtx
	Description:	FFMpeg�������������
*************************************************/
typedef struct
{
	AVCodec			*codec;		//ָ��������ʵ��
	AVFrame			*frame;		//�������֮��/����֮ǰ����������
	AVCodecContext	*c;			//������������ģ�������������һЩ��������
	AVPacket		pkt;		//�������ṹ������������������
} CodecCtx;

#endif