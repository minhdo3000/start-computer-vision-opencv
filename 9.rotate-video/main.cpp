
/* 
Author: domi-lab

Function:
- Load video file (.mp4, .avi ...)
- Display image on screen
- Drag button to rotate frame
*/

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    // open the video file for reading
    VideoCapture cap("../../data/vtest.avi");

    // if not success, exit program
    if (!cap.isOpened())
    {
        cout << "Cannot open the video file" << endl;
        return -1;
    }

    const char *pz_original_window_name = "Original Video";
    namedWindow(pz_original_window_name, CV_WINDOW_AUTOSIZE);

    const char *pz_rotating_window_name = "Rotated Video";
    namedWindow(pz_rotating_window_name, CV_WINDOW_AUTOSIZE);

    int iAngle = 180;
    createTrackbar("Angle", pz_rotating_window_name, &iAngle, 360);

    while (true)
    {
        Mat original_frame;

        bool bSuccess = cap.read(original_frame); // read a new frame from video

        //if not success, break loop
        if (!bSuccess)
        {
            cout << "Cannot read the frame from video file" << endl;
            break;
        }

        imshow(pz_original_window_name, original_frame);

        Mat mat_rotation = getRotationMatrix2D(Point(original_frame.cols / 2, original_frame.rows / 2), (iAngle - 180), 1); //get the affine transformation matrix

        // Rotate the image
        Mat rotated_frame;
        warpAffine(original_frame, rotated_frame, mat_rotation, original_frame.size());

        imshow(pz_rotating_window_name, rotated_frame);

        if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }

    return 0;
}