#include <opencv2/opencv.hpp>
#include "../include/loadData.h"
#include "../include/features.h"

cv::Point2f loadGroundTruth(const std::string &pose) {
    float x, y;
    std::istringstream parser(pose);

    for (int i = 0; i < 12; i++) {
        parser >> y;
        if (i == 3) x = y;
    }
    return cv::Point2f(x+300, y+100);
}
