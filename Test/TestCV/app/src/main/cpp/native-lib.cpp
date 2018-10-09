#include <jni.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;
String face_cascade_name = "/home/yohan/opencv/opencv-3.0.0-alpha/data/haarcascades/haarcascade_frontalface_alt.xml"; //this path will have to be the phone path
CascadeClassifier face_cascade;
extern "C"
{
    void JNICALL Java_com_example_yohan_testcv_MainActivity_ctranslate(JNIEnv *env, jobject instance,
                                                                               jlong matAddress)
    {
        Mat &frame = *(Mat *) matAddress;
        if( !face_cascade.load( face_cascade_name ) )
        printf("--(!)Error loading face cascade\n");
        std::vector<Rect> faces;
        Mat frame_gray;
        cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
        equalizeHist( frame_gray, frame_gray );


    }
}