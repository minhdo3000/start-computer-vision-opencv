/* 
Author: domi-lab

Function:

- Read image
- Detect mouse click and move
- Display image and draw coordinators on screen
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Scalar green = cv::Scalar(23, 187, 76);
Scalar red = cv::Scalar(0, 0, 230);
Scalar amber = cv::Scalar(0, 120, 255);
Scalar black = cv::Scalar(0, 0, 0);
Mat img;

void CallBackFunc(int event, int x, int y, int flags, void *userdata)
{

     if (event == EVENT_LBUTTONDOWN)
     {
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          cv::circle(img, cv::Point(x, y), 2, red, -1);
     }
     else if (event == EVENT_RBUTTONDOWN)
     {
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          cv::circle(img, cv::Point(x, y), 2, green, -1);
     }
     else if (event == EVENT_MBUTTONDOWN)
     {
          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          cv::circle(img, cv::Point(x, y), 2, amber, -1);
     }
     else if (event == EVENT_MOUSEMOVE)
     {
          cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
     }
     imshow("My Window", img);
}

int main(int argc, char **argv)
{
     // Read image from file
     img = imread("../../data/test.png");

     //if fail to read the image
     if (img.empty())
     {
          cout << "Error loading the image" << endl;
          return -1;
     }

     //Create a window
     namedWindow("My Window", 1);

     //set the callback function for any mouse event

     setMouseCallback("My Window", CallBackFunc, &img);

     waitKey(0);

     return 0;
}
