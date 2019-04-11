//
// Created by zzq on 19-4-3.
//

#include "include/rkcodecjni.h"
#include <jni.h>
#include "include/aw_codec.h"
jbyte* nv12;
extern "C" JNIEXPORT void JNICALL Java_com_dnak_rkcodec_Rkcodec_convert(JNIEnv *env, jobject, jbyteArray src, jint format, jbyteArray dir, jint df, jint w, jint h){

    jbyte *srcb = env->GetByteArrayElements(src, NULL);
    jbyte *dirb = env->GetByteArrayElements(dir,NULL);
//
    int length = env->GetArrayLength(src);
    int framesize = w*h;
//    jbyte *nv12 = reinterpret_cast<jbyte *>(env->NewByteArray(sizeof(srcb)));
//    jbyte* nv12 = new jbyte[length];
    if(nv12==0){
        nv12 = new jbyte[length];
    }
    memcpy(nv12,srcb,framesize);

    for(int i=0;i<framesize/2;i +=2){
        nv12[framesize+i-1] = srcb[i+framesize];
    }
    for(int i =0;i<framesize/2;i +=2){
        nv12[framesize+i] = srcb[i+framesize-1];
    }
    aw_convert(nv12,format,dirb,df,w,h);

    env->ReleaseByteArrayElements(src,srcb,0);
    env->ReleaseByteArrayElements(dir,dirb,0);
};