#include <iostream>
#include "../include/processing.h"
//  - Capture images: It, It+1
//  - Undistort the above images.
//  - Use FAST algorithm to detect features in It
//      - and track those features to It+1
//      - A new detection is triggered if the number of
//      features drop below a certain threshold.
//  - Use Nister’s 5-point alogirthm with RANSAC to compute the essential matrix.
//  - Estimate R,t
//  - from the essential matrix that was computed in the previous step.
//  - Take scale information from some external source (like a speedometer),
//    and concatenate the translation vectors, and rotation matrices.

// KITTI Images are already undistorted
// USE FAST ALG to detect features

int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    for(int i = 0; i < 10; i++) {
//        std::cout << i << " ";
//    }
//    return 0;
    sequenceFrames();
}
