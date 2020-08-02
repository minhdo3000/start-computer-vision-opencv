/* 
Author: domi-lab

Function:
- Load video file (.mp4, .avi ...)
- Display image on screen
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{

    VideoCapture cap("../vtest.avi"); //open the video file for reading

    if (cap.isOpened() == false) // if not success, exit program
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    double fps = cap.get(CAP_PROP_FPS); //get the frames rate of the video
    cout << "Frames per seconds : " << fps << endl;

    String window_name = "output";

    namedWindow(window_name, WINDOW_NORMAL); //create a window

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video

        if (bSuccess == false) //Breaking the while loop at the end of the video
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        imshow(window_name, frame); //show the frame in the created window

        //wait for for 15 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(15) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}