#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>

#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include "constants.h"
//class Loader {
//private:
//    std::string filename;
//    std::string pose;
//    std::string prevPose;
//    std::ifstream poses;
//
//    char tmp[100]{}; // init char of 0
//    int idx = 0;
//
//    void storeString() {
//        if (!TEST) {
//            sprintf(tmp, "../data/dataset/sequences/%02d/image_0/%06d.png", SEQUENCE_NUM, idx);
//            filename = tmp;
//        } else {
//            sprintf(tmp, "../tmp/images/%02d/image_0/%06d.png", SEQUENCE_NUM, idx);
//            filename = tmp;
//        }
//    }
//
//public:
//    explicit Loader(int idx_) : idx{idx_} {
//        sprintf(tmp, "../dataset/poses/%02d.txt", SEQUENCE_NUM);
//        poses = std::ifstream(tmp);
//        if (poses.is_open()) {
//            std::getline(poses, pose);
//        }
//        storeString();
//    };
//
//    std::vector<std::string> operator*() const {
//        return {prevPose, pose, filename};
//    }
//
//    Loader &operator++() {
//        idx++;
//        prevPose = pose;
//        if (poses.is_open()) std::getline(poses, pose);
//        if (DEBUG) std::cout << pose << std::endl;
//        storeString();
//    }
//
//    bool operator!=(const Loader &other) {
//        return other.idx != idx;
//    }
//};

void loadKitti(const std::pair<std::string, std::string> &cur, cv::Mat &out, int type);
cv::Point2f loadGroundTruth(const std::string &pose);
void sequence();