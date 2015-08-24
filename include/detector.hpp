#pragma once

#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

class Detector {
public:
    ~Detector(){};
    virtual int count() = 0;
    virtual void draw() = 0;
    virtual bool init(cv::Mat &src) = 0;
};

cv::Ptr<Detector> createDetector ( const std::string &impl_name );