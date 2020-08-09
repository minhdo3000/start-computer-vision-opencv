/* 
Author: domi-lab

Function:
- Reduce half of image size by removing a pixel between two other ones.
- Copy RGB pixels from a image to another one
*/

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    string full_path = "../../data/test.png";
    Mat input_img = imread(full_path);
    resize(input_img, input_img, Size(640, 480));
    Size output_size = Size(input_img.cols / 2, input_img.rows / 2);

    Mat output1(output_size, CV_8UC3);
    Mat output2(output_size, CV_8UC3);
    Mat output3(output_size, CV_8UC3);
    Mat output4(output_size, CV_8UC3);

    int row2 = 0, col2 = 0;
    for (int row = 0; row < input_img.rows; row = row + 2) // image width
    {
        for (int col = 0; col < input_img.cols; col = col + 2) // image height
        {
            output1.at<Vec3b>(row2, col2) = input_img.at<Vec3b>(row, col);
            output2.at<Vec3b>(row2, col2) = input_img.at<Vec3b>(row + 1, col);
            output3.at<Vec3b>(row2, col2) = input_img.at<Vec3b>(row, col + 1);
            output4.at<Vec3b>(row2, col2) = input_img.at<Vec3b>(row + 1, col + 1);
            col2++;
        }
        row2++;
        col2 = 0;
    }
    imshow("output1", output1);
    imshow("output2", output2);
    imshow("output3", output3);
    imshow("output4", output4);
    imshow("original image", input_img);
    waitKey(0);
    return 0;
}
