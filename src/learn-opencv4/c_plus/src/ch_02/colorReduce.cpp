//
// Created by mehmet on 9/16/19.
//
#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

void colorReduce(cv::Mat image, int div = 64) {
    int nl = image.rows;
    int nc = image.cols * image.channels();
    uchar div2 = div >> 1; // div2 = div/2

    for (int j = 0; j < nl; j++) {
        uchar *data = image.ptr<uchar>(j);
        for (int i = 0; i < nc; ++i) {
            *data++ = *data / div * div + div2;
        }
    }
}

int main() {
    cv::Mat img;

    img = cv::imread("boldt.jpg");

    colorReduce(img);

    cv::namedWindow("Image");
    cv::imshow("Image", img);
    cv::waitKey();

    cout << "Done!" << endl;

    return 0;
}
