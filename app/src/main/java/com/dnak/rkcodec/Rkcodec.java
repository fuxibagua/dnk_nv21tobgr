package com.dnak.rkcodec;

public class Rkcodec {

    public native void convert(byte[] yuv,int sf,byte[] bgr,int df,int w,int h);
}
