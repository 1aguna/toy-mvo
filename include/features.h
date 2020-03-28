#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"

#include <iostream>
#include <ctype.h>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator
#include <vector>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>

#include "../include/constants.h"
typedef unsigned char uchar;
using cv::Point2f;
using cv::KeyPoint;

void detectFeatures(cv::Mat&, std::vector<Point2f>&);
void trackFeatures(cv::Mat baseImg,
                   cv::Mat nextImg,
                   std::vector<cv::Point2f>& basePoints,
                   std::vector<Point2f>& nextPts,
                   std::vector<uchar>& status);
void estimatePose(const std::vector<cv::Point2f>&,
                  const std::vector<cv::Point2f>&,
                  cv::Mat&,
                  cv::Mat&,
                  cv::Mat&);
