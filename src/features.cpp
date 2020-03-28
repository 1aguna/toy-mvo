#include "../include/features.h"

using cv::Point2f;
using cv::KeyPoint;

void detectFeatures(cv::Mat& frame, std::vector<Point2f>& pts) {
    /**
     * Detects features using the FAST algorithm for corner detection
     * Params:
     *      frame: input frame to detect features on
     * Return:
     *      points: vector of points containing detected features
     * */
    std::vector<KeyPoint> keypts;
    bool suppression = true;
    int thresh = 20;
    cv::FAST(frame, keypts, thresh, suppression); // detect features and put into keypts
    cv::KeyPoint::convert(keypts, pts); // converts keypts to vector of Points2f
}

void trackFeatures( cv::Mat baseImg,
                    cv::Mat nextImg,
                    std::vector<cv::Point2f>& basePts,
                    std::vector<Point2f>& nextPts,
                    std::vector<uchar>& status) {
    /**
     * Tracks features between a pair of frames
     * Params:
     *      baseImg: frame at time T
     *      nextImg: frame at time T + 1
     *      basePts: The points corresponding to baseImg
     *      nextPts: The points corresponding to nextImg
     *      status:  An empty vector that LKT algorithm will fill with statuses
     * */
    std::vector<float> err;
    auto winSize = cv::Size(21,21); // init the window size for viewing

    // Determine the criteria for LKT algorithm to terminate
    cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.03);

    // Track features across frames at T and T + 1
    cv::calcOpticalFlowPyrLK(baseImg, nextImg, basePts, nextPts, status,err , winSize, 3, criteria);

    //getting rid of pts that LKT didn't work on and pts that went out of frame
    int correctionIndex = 0;
    for(int i = 0; i < status.size(); i++) {
        Point2f pt = nextPts[i - correctionIndex];

        // If its the first frame or the point went out of bounds
        // then delete those points
        bool belowZero = (pt.x < 0 || pt.y < 0);
        if (status[i] == 0 || belowZero)	{
            if (belowZero) {
                status[i] = 0;
            }
            basePts.erase(basePts.begin() + i - correctionIndex);
            nextPts.erase(nextPts.begin() + i - correctionIndex);
            correctionIndex++;
        }
    }
}

void estimatePose(const std::vector<cv::Point2f>& p1,
                  const std::vector<cv::Point2f>& p2,
                  cv::Mat& mask,
                  cv::Mat& r,
                  cv::Mat& t) {


    // // calibration from dataset
    cv::Point2d principal_point = cv::Point2d(607.1928, 185.2157);
    double focal_length = 718.8560;

    cv::Mat E = cv::findEssentialMat(p2, p1, focal_length, principal_point,
                            cv::RANSAC, 0.999, 1.0, mask);
    cv::recoverPose(E, p2, p1, r, t, focal_length, principal_point, mask);

}