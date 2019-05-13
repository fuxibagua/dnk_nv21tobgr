package com.seeta.sdk;

public class PoseEstimation {

    static {
        System.loadLibrary("libpose");
    }
    private long nativeObj;

    private native long construct(String model);

    private native float[] poseEstimate(long nativeObj,int width,int height,int channels,byte[] data,int[] seetaRect);

    private native void release(long nativeObj);

    public PoseEstimation(String model){
       nativeObj = construct(model);
    }

    public float[] poseEstimate(SeetaImageData imageData,SeetaRect seetaRect){
        return poseEstimate(nativeObj,imageData.width,imageData.height,imageData.channels,imageData.data,new int[]{seetaRect.x,seetaRect.y,seetaRect.width,seetaRect.height});
    }

    public void release(){
        release(nativeObj);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        release();
    }
}
