#pragma once

#include <ctype.h>

#include <algorithm>  // for copy
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>  // for ostream_iterator
#include <opencv2/features2d.hpp>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "constants.h"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/tracking.hpp"
typedef unsigned char uchar;
using cv::KeyPoint;
using cv::Point2f;

void detectFeatures(cv::Mat&, std::vector<Point2f>&);
void trackFeatures(const cv::Mat& baseImg, const cv::Mat& nextImg,
                   std::vector<cv::Point2f>& basePoints,
                   std::vector<Point2f>& nextPts, std::vector<uchar>& status);
void estimatePose(const std::vector<cv::Point2f>&,
                  const std::vector<cv::Point2f>&, cv::Mat&, cv::Mat&,
                  cv::Mat&);
