#include <jni.h>
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;

extern "C"
{
    void JNICALL Java_com_example_yohan_testcv_MainActivity_ctranslate(JNIEnv *env, jobject instance,
                                                                               jlong matAddress)
    {
        Mat &frame = *(Mat *) matAddress;

        

    }
}