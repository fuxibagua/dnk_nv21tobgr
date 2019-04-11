
#ifndef __AW_CODEC_H__
#define __AW_CODEC_H__

#include "videodev2.h"
#include "types.h"

#define MAX_AW_W	(4096)
#define MAX_AW_H	(2160)

enum {
	DK_CODEC_UNKNOW = 0,
	DK_CODEC_MPEG4,
	DK_CODEC_H264,
	DK_CODEC_MJPEG,
};

enum {
	DK_PIXEL_YV12 = 0,
	DK_PIXEL_NV12 = 1,
	DK_PIXEL_BGR_888 = 2,
	DK_PIXEL_RGB_888 = 3,
	DK_PIXEL_BGRA_8888 = 4,
	DK_PIXEL_RGBA_8888 = 5,
};

typedef struct {
	int format;
	int width;
	int height;
	uint8_t *extra;
	int extra_sz;
} vdec_fmt_t;

typedef struct {
	int format;
	int src_width;
	int src_height;
	int width;
	int height;
	int frame_rate;
	int bit_rate;
	int key_interval;
} venc_fmt_t;

AW_API void *aw_vdec_open(vdec_fmt_t *fmt);

AW_API int aw_vdec_packet(void *ctx, const void *data, int length);

AW_API void *aw_vdec_decode(void *ctx);

AW_API void aw_pic_release(void *ctx, void *frame);

AW_API void aw_vdec_close(void *ctx);

AW_API void *aw_pic_Y(void *frame);

AW_API int aw_pic_width(void *frame);

AW_API int aw_pic_height(void *frame);

AW_API int aw_pic_format(void);

AW_API void *aw_venc_open(venc_fmt_t *fmt);

AW_API void aw_venc_close(void *enc);

AW_API int aw_venc_encode(void *enc, struct v4l2_buffer *buf, uint8_t *data, int length);

AW_API int aw_venc_header(void *enc, uint8_t *data);

AW_API void aw_venc_force(void *enc);

AW_API int aw_convert(void *s, int sf, void *d, int df, int w, int h);

AW_API int aw_rotation(void *s, int sf, int w, int h, void *d, int df, int rotation);

AW_API int aw_scale(void *s, int sf, int sw, int sh, void *d, int df, int dw, int dh);

AW_API int aw_jpeg_encode(void *yuv, int fmt, int w, int h, int quality, void *jpeg, int size);

#endif
