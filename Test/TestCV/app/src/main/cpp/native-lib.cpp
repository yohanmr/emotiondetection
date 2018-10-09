#include <jni.h>
#include <string>
#include "opencv2/opencv.hpp"
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_yohan_testcv_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
