
/* 
Author: domi-lab

Function:
- Load video file (.mp4, .avi ...)
- Display image on screen
- Save video file
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    VideoCapture cap("../../data/vtest.avi"); //Open the default video file

    if (cap.isOpened() == false) // if not success, exit program
    {
        cout << "Cannot open the video camera" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));   //get the width of frames of the video
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT)); //get the height of frames of the video

    Size frame_size(frame_width, frame_height);
    int frames_per_second = 10;

    VideoWriter oVideoWriter("../out_vtest.avi", VideoWriter::fourcc('D', 'I', 'V', 'X'),
                             frames_per_second, frame_size, true); //Create and initialize the VideoWriter object

    if (oVideoWriter.isOpened() == false) //If the VideoWriter object is not initialized successfully, exit the program

    {
        cout << "Cannot save the video to a file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    string window_name = "my video";
    namedWindow(window_name); //create a window called "My Camera Feed"

    while (true)
    {
        Mat frame;
        bool isSuccess = cap.read(frame); // read a new frame from the video camera

        //Breaking the while loop if frames cannot be read from the camera
        if (isSuccess == false)
        {
            cout << "Find the end of the video" << endl;
            cin.get(); //Wait for any key press
            break;
        }

        oVideoWriter.write(frame); //write the video frame to the file

        imshow(window_name, frame); //show the frame in the created window

        //Wait for for 15 milliseconds until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If any other key is pressed, continue the loop
        //If any key is not pressed within 10 milliseconds, continue the loop
        if (waitKey(15) == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
    }

    oVideoWriter.release(); //close the video file

    return 0;
}