#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include "detector.hpp"

using namespace  cv;

static const char* keys =
{
    "{ |  image   |         |  Source image }"
    "{ |  method  |  Hough  |  A method to work with }"
};

/** @function main */
int main(int argc, char** argv)
{
    cv::CommandLineParser parser( argc, argv, keys );
    // Parse and validate input parameters
    std::string image_file = parser.get<std::string>( "image" );
    std::string method = parser.get<std::string>( "method" );
    Mat src;    

    /// Read the image
    src = imread( image_file );
    if( !src.data )
        return -1;

    Detector* detector = createDetector(method);
    std::cout<<detector;
    if(!detector->init(src))
    std::cout<<"ok1\n";
    else std::cout<<"not ok1\n";
    int count = detector->count();
    std::cout<<"ok2\n";
    detector->draw();
    std::cout<<"ok3\n";

    return 0;
}