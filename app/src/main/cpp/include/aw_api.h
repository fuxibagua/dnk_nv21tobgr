#ifndef __AW_API_H__
#define __AW_API_H__

#include "types.h"
#include <pthread.h>

enum {
    /* flip source image horizontally (around the vertical axis) */
    AW_FLIP_H    = 0x01,
    /* flip source image vertically (around the horizontal axis)*/
    AW_FLIP_V    = 0x02,
    /* rotate source image 90 degrees clockwise */
    AW_ROT_90    = 0x04,
    /* rotate source image 180 degrees */
    AW_ROT_180   = 0x03,
    /* rotate source image 270 degrees clockwise */
    AW_ROT_270   = 0x07,
    /* don't use.*/
    AW_RESERVED  = 0x08,
};

class AwRenderApi {
public:
	AW_API AwRenderApi();
	AW_API ~AwRenderApi();

	AW_API int start(int w, int h);
	AW_API void stop(void);
	AW_API void NV12(void *yuv);
	AW_API void YV12(void *yuv);
	AW_API void rect(int x, int y, int w, int h);

	AW_API void visible(int val);
	AW_API void layer(int val);

	AW_API void transform(int val);

private:
	void *m_osd;

	int m_sw, m_sh; //YUV图像宽高

	int m_dx; //显示 x坐标
	int m_dy; //显示 y坐标
	int m_dw; //宽
	int m_dh; //高

	int m_init;
	int m_visible;
	int m_layer;

	pthread_mutex_t m_mutex;
};

#endif
