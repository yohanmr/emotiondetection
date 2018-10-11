package com.example.yohan.testcv;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceView;
import android.widget.TextView;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.objdetect.CascadeClassifier;



public class MainActivity extends AppCompatActivity implements CameraBridgeViewBase.CvCameraViewListener2 {
    Mat mRGBa;
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    private static final String TAG="MainActivity";
    JavaCameraView javaCameraView;
    BaseLoaderCallback mLoaderCallBack = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status)
        {
            switch (status)
            {
                case BaseLoaderCallback.SUCCESS:
                {
                    javaCameraView.enableView();
                    break;
                }
                default:
                {
                    super.onManagerConnected(status);
                    break;
                }
            }
            super.onManagerConnected(status);
        }
    };
    static
    {
        if(OpenCVLoader.initDebug())
        {
            Log.d(TAG, "Opencv Success");
        }
        else
        {
            Log.d(TAG,"Failure");
        }
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        javaCameraView = (JavaCameraView)findViewById(R.id.java_camera_view);
        javaCameraView.setVisibility(SurfaceView.VISIBLE);
        javaCameraView.setCvCameraViewListener(this);
        // Example of a call to a native method

    }
    @Override
    protected void onPause()
    {
        super.onPause();
        if(javaCameraView!= null)
            javaCameraView.disableView();
    }
    @Override
    protected void onDestroy()
    {
        super.onDestroy();
        if(javaCameraView!=null)
            javaCameraView.disableView();
    }
    @Override
    protected void onResume()
    {
        super.onResume();
        if(OpenCVLoader.initDebug())
        {
            Log.d(TAG, "Opencv Success");
            mLoaderCallBack.onManagerConnected(LoaderCallbackInterface.SUCCESS);
        }
        else
        {
            Log.d(TAG,"Failure");
            OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_3_0_0,this,mLoaderCallBack);
        }
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native void ctranslate(long matAddress);

    @Override
    public void onCameraViewStarted(int width, int height) {
        mRGBa = new Mat(height,width,CvType.CV_8UC4);

    }

    @Override
    public void onCameraViewStopped() {
        mRGBa.release();

    }

    @Override
    public Mat onCameraFrame(CameraBridgeViewBase.CvCameraViewFrame inputFrame) {
        mRGBa = inputFrame.rgba();
        ctranslate(mRGBa.getNativeObjAddr());
        return mRGBa;
    }

}