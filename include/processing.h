#pragma once
#include "constants.h"
#include "features.h"
#include "loadData.h"

void displayFeatures(cv::Mat&, cv::Mat&, cv::Mat&);
void displayTrajectory(cv::Mat&, cv::Mat&, cv::Point2f&);
void sequenceFrames();
double getScale(int frameCnt);