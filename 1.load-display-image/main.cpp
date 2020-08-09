/* 
Author: domi-lab

Function:
- Load image from image file (.jpg, .png ...)
- Display image on screen
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

    Mat image = imread("../../data/test.png"); // Read the image file

    if (image.empty()) // Check for failure
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    String windowName = "Test"; //Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, image); // Show our image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); //destroy the created window

    return 0;
}