#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;
void detectAndDisplay( Mat frame );
String face_cascade_name = "/home/yohan/opencv/opencv-3.0.0-alpha/data/haarcascades/haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
String window_name = "Capture - Face detection";
int main( void )
{
    VideoCapture capture;
    Mat frame;
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n"); return -1; };
    capture.open( -1 );
    if ( ! capture.isOpened() ) { printf("--(!)Error opening video capture\n"); return -1; }
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
            break;
        }
        detectAndDisplay( frame );
        char c = (char)waitKey(10);
        if( c == 27 ) { break; }
    }
    return 0;
}
void detectAndDisplay( Mat frame )
{
    std::vector<Rect> faces;
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point p1( faces[i].x , faces[i].y );
        Point p2(faces[i].x+faces[i].width,faces[i].y+faces[i].height);
        rectangle( frame, p1, p2, Scalar( 255, 0, 255 ), 4, 8, 0 );
        Mat faceROI = frame_gray( faces[i] );

    }
    cout<<frame;
    imshow( window_name, frame );
}
