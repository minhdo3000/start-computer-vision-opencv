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
    Scalar green = cv::Scalar(23, 187, 76);
    Scalar red = cv::Scalar(0, 0, 230);
    Scalar amber = cv::Scalar(0, 120, 255);
    Scalar black = cv::Scalar(0, 0, 0);

    cv::Mat image = cv::imread("../../data/aloeL.jpg");
    resize(image, image, Size(1280, 720));

    if (image.empty()) // Check for failure
    {
        cout << "Could not create image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    Mat overlay = image.clone();

    // draw red line connecting two points: (100;100) and (200;100), thickness is 3
    cv::line(overlay, cv::Point(100, 100), cv::Point(200, 100), red, 3);
    cv::line(overlay, cv::Point(100, 250), cv::Point(200, 250), amber, 3);
    cv::line(overlay, cv::Point(100, 400), cv::Point(200, 400), green, 3);

    // draw red circle, which has center at Point(300;100) and radius is 50, thickness is 3
    cv::circle(overlay, cv::Point(300, 100), 50, red, 3);
    cv::circle(overlay, cv::Point(300, 250), 50, amber, 3);
    cv::circle(overlay, cv::Point(300, 400), 50, green, 3);

    // draw red circle, which has center at Point(450;100) and radius is 50, thickness is -1
    cv::circle(overlay, cv::Point(450, 100), 50, red, -1);
    cv::circle(overlay, cv::Point(450, 250), 50, amber, -1);
    cv::circle(overlay, cv::Point(450, 400), 50, green, -1);

    // draw red rectangular, which starts at Point(550,50) and dimension 200 x 100px
    cv::rectangle(overlay, cv::Rect(550, 50, 200, 100), red, 3);
    cv::rectangle(overlay, cv::Rect(550, 200, 200, 100), amber, 3);
    cv::rectangle(overlay, cv::Rect(550, 350, 200, 100), green, 3);

    // draw red rectangular, which starts at Point(800,50) and dimension 200 x 100px, thickness is -1
    cv::rectangle(overlay, cv::Rect(800, 50, 200, 100), red, -1);
    cv::rectangle(overlay, cv::Rect(800, 200, 200, 100), amber, -1);
    cv::rectangle(overlay, cv::Rect(800, 350, 200, 100), green, -1);

    double angle = 90;
    double startAngle = 90;
    double endAngle = 270;

    // draw elip, which has center at Point(1100;100), small axis is 50 and large axis is 80, thickness is 3
    cv::ellipse(overlay, cv::Point(1100, 100), cv::Size(25, 40), angle, startAngle, endAngle, red, 3);
    cv::ellipse(overlay, cv::Point(1100, 250), cv::Size(25, 40), angle, startAngle, endAngle, amber, 3);
    cv::ellipse(overlay, cv::Point(1100, 400), cv::Size(25, 40), angle, startAngle, endAngle, green, 3);

    // draw elip, which has center at Point(1100;100), small axis is 50 and large axis is 80, thickness is -1
    cv::ellipse(overlay, cv::Point(1200, 100), cv::Size(25, 40), angle, startAngle, endAngle, red, -1);
    cv::ellipse(overlay, cv::Point(1200, 250), cv::Size(25, 40), angle, startAngle, endAngle, amber, -1);
    cv::ellipse(overlay, cv::Point(1200, 400), cv::Size(25, 40), angle, startAngle, endAngle, green, -1);

    // draw text on image
    cv::putText(overlay, "FONT_HERSHEY_PLAIN", cv::Point(50, 500), cv::FONT_HERSHEY_PLAIN, 1, red, 2);
    cv::putText(overlay, "FONT_HERSHEY_PLAIN", cv::Point(50, 550), cv::FONT_HERSHEY_PLAIN, 1, amber, 2);
    cv::putText(overlay, "FONT_HERSHEY_PLAIN", cv::Point(50, 600), cv::FONT_HERSHEY_PLAIN, 1, green, 2);

    cv::putText(overlay, "FONT_HERSHEY_SIMPLEX", cv::Point(250, 500), cv::FONT_HERSHEY_SIMPLEX, 1, red, 2);
    cv::putText(overlay, "FONT_HERSHEY_SIMPLEX", cv::Point(250, 550), cv::FONT_HERSHEY_SIMPLEX, 1, amber, 2);
    cv::putText(overlay, "FONT_HERSHEY_SIMPLEX", cv::Point(250, 600), cv::FONT_HERSHEY_SIMPLEX, 1, green, 2);

    cv::putText(overlay, "FONT_ITALIC", cv::Point(700, 500), cv::FONT_ITALIC, 1, red, 2);
    cv::putText(overlay, "FONT_ITALIC", cv::Point(700, 550), cv::FONT_ITALIC, 1, amber, 2);
    cv::putText(overlay, "FONT_ITALIC", cv::Point(700, 600), cv::FONT_ITALIC, 1, green, 2);

    float opacity = 0.59;
    addWeighted(overlay, opacity, image, 1 - opacity, 0, image);

    bool isSuccess = imwrite("../out_draw_transparent_shapes_text.png", image); //write the image to a file as JPEG
    //bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG
    if (isSuccess == false)
    {
        cout << "Failed to save the image" << endl;
        cin.get(); //wait for a key press
        return -1;
    }

    String windowName = "draw transparent shape & text"; //Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, image); // Show our image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); //destroy the created window

    return 0;
}
