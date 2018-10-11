#include <jni.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;
String face_cascade_name = "/storage/sdcard/Download/haarcascade_frontalface_alt-1.xml"; //this path will have to be the phone path
CascadeClassifier face_cascade;
extern "C"
{
    void JNICALL Java_com_example_yohan_testcv_MainActivity_ctranslate(JNIEnv *env, jobject instance,
                                                                               jlong matAddress)
    {
        Mat &frame = *(Mat *) matAddress;
        face_cascade.load((face_cascade_name));
        if( !face_cascade.load( face_cascade_name ) )
        {
            printf("--(!)Error loading face cascade\n");
            Point p1(0,0);
            Point p2(200,200);
            rectangle(frame, p1, p2, Scalar(255, 0, 255), 4, 8, 0);
        }
        else
            {
            std::vector<Rect> faces;
            Mat frame_gray;
            cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
            equalizeHist(frame_gray, frame_gray);
            face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE,
                                          Size(30, 30));
            for (size_t i = 0; i < faces.size(); i++)
            {
                Point p1(faces[i].x, faces[i].y);
                Point p2(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
                rectangle(frame, p1, p2, Scalar(255, 0, 255), 4, 8, 0);


            }
        }
    }



}