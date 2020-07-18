#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <utility>

#include "constants.h"

void loadKitti(const std::pair<std::string, std::string>& cur, cv::Mat& out,
               int type);
cv::Point2f loadGroundTruth(const std::string& pose);
void sequence();