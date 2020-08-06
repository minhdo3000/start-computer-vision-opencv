/* 
Author: domi-lab

Function:
- Create black image
- Draw basic shapes and text
- Display image on screen
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

    // Create black image with dimension 1280 x 720 pixels
    cv::Mat image = cv::Mat(Size(1280, 720), CV_8UC3);
    image = cv::Scalar(0, 0, 0);

    if (image.empty()) // Check for failure
    {
        cout << "Could not create image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    // Draw red dot at point(50;100)
    image.at<cv::Vec3b>(Point(50, 100)) = cv::Vec3b(0, 0, 255);

    // draw red line connecting two points: (100;100) and (200;100), thickness is 1
    cv::line(image, cv::Point(100, 100), cv::Point(200, 100), cv::Scalar(0, 0, 255), 1);

    // draw red circle, which has center at Point(300;100) and radius is 50, thickness is 1
    cv::circle(image, cv::Point(300, 100), 50, cv::Scalar(0, 0, 255), 1);

    // draw red circle, which has center at Point(450;100) and radius is 50, thickness is -1
    cv::circle(image, cv::Point(450, 100), 50, cv::Scalar(0, 0, 255), -1);

    // draw red rectangular, which starts at Point(550,50) and dimension 200 x 100px
    cv::rectangle(image, cv::Rect(550, 50, 200, 100), cv::Scalar(0, 0, 255), 1);

    // draw red rectangular, which starts at Point(800,50) and dimension 200 x 100px, thickness is -1
    cv::rectangle(image, cv::Rect(800, 50, 200, 100), cv::Scalar(0, 0, 255), -1);

    double angle = 90;
    double startAngle = 90;
    double endAngle = 270;

    // draw elip, which has center at Point(1100;100), small axis is 50 and large axis is 80, bold is 1
    cv::ellipse(image, cv::Point(1100, 100), cv::Size(25, 40), angle, startAngle, endAngle, cv::Scalar(0, 0, 255), 1);

    // draw elip, which has center at Point(1100;100), small axis is 50 and large axis is 80, bold is -1
    cv::ellipse(image, cv::Point(1200, 100), cv::Size(25, 40), angle, startAngle, endAngle, cv::Scalar(0, 0, 255), -1);

    // draw text on image
    cv::putText(image, "FONT_HERSHEY_PLAIN", cv::Point(0, 200), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(image, "FONT_HERSHEY_SCRIPT_COMPLEX", cv::Point(0, 250), cv::FONT_HERSHEY_SCRIPT_COMPLEX, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(image, "FONT_HERSHEY_SCRIPT_SIMPLEX", cv::Point(0, 300), cv::FONT_HERSHEY_SCRIPT_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(image, "FONT_HERSHEY_SIMPLEX", cv::Point(0, 350), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(image, "FONT_HERSHEY_TRIPLEX", cv::Point(0, 400), cv::FONT_HERSHEY_TRIPLEX, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(image, "FONT_ITALIC", cv::Point(0, 450), cv::FONT_ITALIC, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(image, "FONT_HERSHEY_COMPLEX", cv::Point(0, 500), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(image, "FONT_HERSHEY_COMPLEX_SMALL", cv::Point(0, 550), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(image, "FONT_HERSHEY_DUPLEX", cv::Point(0, 600), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 0, 0), 2);

    bool isSuccess = imwrite("../out_draw_shapes_text.png", image); //write the image to a file as JPEG
    //bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG
    if (isSuccess == false)
    {
        cout << "Failed to save the image" << endl;
        cin.get(); //wait for a key press
        return -1;
    }

    String windowName = "draw basic shape & text"; //Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, image); // Show our image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); //destroy the created window

    return 0;
}
