#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main() {

    // define an image window
    cv::namedWindow("Image");

    // read the image
    cv::Mat image = cv::imread("puppy.bmp");

    // read the logo
    cv::Mat logo = cv::imread("smalllogo.png");

    // define image ROI at image bottom-right
    cv::Mat imageROI(image,
                     cv::Rect(image.cols - logo.cols, //ROI coordinates
                              image.rows - logo.rows,
                              logo.cols, logo.rows));// ROI size

    // insert logo
    logo.copyTo(imageROI);

    cv::imshow("Image", image); // show the image
    cv::waitKey(0); // wait for a key pressed

    // re-read the original image
    image = cv::imread("puppy.bmp");

    // define image ROI at image bottom-right
    imageROI = image(cv::Rect(image.cols - logo.cols, image.rows - logo.rows,
                              logo.cols, logo.rows));
    // or using ranges:
    // imageROI= image(cv::Range(image.rows-logo.rows,image.rows), 
    //                 cv::Range(image.cols-logo.cols,image.cols));

    // use the logo as a mask (must be gray-level)
    cv::Mat mask(logo);

    // insert by copying only at locations of non-zero mask
    logo.copyTo(imageROI, mask);

    cv::imshow("Image", image); // show the image
    cv::waitKey(0); // wait for a key pressed

    return 0;
}