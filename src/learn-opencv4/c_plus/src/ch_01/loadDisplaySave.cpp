#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void onMouse( int event, int x, int y, int flags, void* param)
{
    cv::Mat *im= reinterpret_cast<cv::Mat*>(param);
    switch (event) { // dispatch the event
        case cv::EVENT_LBUTTONDOWN: // left mouse button down event
// display pixel value at (x,y)
            std::cout << "at (" << x << "," << y << ") value is: " <<
                      static_cast<int>(im->at<uchar>(cv::Point(x,y))) << std::endl;
            break;
    }
}

int main() {
    cv::Mat image; // create an empty image
    cout << "This image is " << image.rows << " x " << image.cols << endl;

    image = cv::imread("mehmet.jpg", cv::IMREAD_GRAYSCALE); // read an input image

    cout << "This image has: " << image.channels() << " channels" << endl;

    // define the window (optional)
//    cv::namedWindow("Original Image");
    // show the image
    cv::imshow("Original Image", image);

    cv::setMouseCallback("Original Image", onMouse, reinterpret_cast<void*>(&image));

    cv::Mat result;
    cv::flip(image, result, 1);
    cv::imshow("Flip Image", result);



    cv::circle(image,              // destination image
               cv::Point(155,110), // center coordinate
               65,                 // radius
               0,                  // color (here black)
               3);                 // thickness

    cv::putText(image,                   // destination image
                "This is mehmet.",        // text
                cv::Point(40,200),       // text position
                cv::FONT_HERSHEY_PLAIN,  // font type
                2.0,                     // font scale
                255,                     // text color (here white)
                2);                      // text thickness

    cv::imshow("Drawing on an Image", image); // show the image



    cv::waitKey(0); // 0 to indefinitely wait for a key pressed // specifying a positive value will wait for // the given amount of msec

    cv::imwrite("output.bmp", result); // save result

    return 0;
}