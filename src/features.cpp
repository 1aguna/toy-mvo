#include "../include/features.h"

using cv::KeyPoint;
using cv::Point2f;

void detectFeatures(cv::Mat& frame, std::vector<Point2f>& pts) {
  /**
   * Detects features in current frame
   * Params:
   *      pts: Empty vector for detected features
   *      frame: Matrix representing the current image frame
   * */
  std::vector<KeyPoint> keypts;
  bool suppression = true;
  int thresh = 15;
  cv::FAST(frame, keypts, thresh,
           suppression);               // detect features and put into keypts
  cv::KeyPoint::convert(keypts, pts);  // converts keypts to vector of Points2f
}

void trackFeatures(const cv::Mat& baseImg, const cv::Mat& nextImg,
                   std::vector<cv::Point2f>& basePts,
                   std::vector<Point2f>& nextPts, std::vector<uchar>& status) {
  /**
   * Tracks features between a pair of frames
   * Params:
   *      baseImg: frame at time T
   *      nextImg: frame at time T + 1
   *      basePts: The points corresponding to baseImgwinSize
   *      nextPts: The points corresponding to nextImg
   *      status:  An empty vector that LKT algorithm will fill with statuses
   * */
  std::vector<float> err;
  auto winSize = cv::Size(21, 21);  // init the window size for viewing

  // Determine the criteria for LKT algorithm to terminate
  cv::TermCriteria criteria = cv::TermCriteria(
      cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.03);

  // Track features across frames at T and T + 1
  cv::calcOpticalFlowPyrLK(baseImg, nextImg, basePts, nextPts, status, err,
                           winSize, 3, criteria);
  // getting rid of pts that LKT didn't work on and pts that went out of frame
  int correctionIndex = 0;

  for (int i = 0; i < status.size(); i++) {
    Point2f pt = nextPts[i - correctionIndex];

    // If its the first frame or the point went out of bounds
    // then delete those points
    bool belowZero = (pt.x < 0 || pt.y < 0);
    bool xTooFar = abs(nextPts[i].x - basePts[i].x) > 200;
    bool yTooFar = abs(nextPts[i].y - basePts[i].y) > 200;

    if (status[i] == 0 || belowZero) {
      if (belowZero || xTooFar || yTooFar) {
        status[i] = 0;
      }
      basePts.erase(basePts.begin() + i - correctionIndex);
      nextPts.erase(nextPts.begin() + i - correctionIndex);
      correctionIndex++;
    }
  }
}

void estimatePose(const std::vector<cv::Point2f>& p1,
                  const std::vector<cv::Point2f>& p2, cv::Mat& mask, cv::Mat& r,
                  cv::Mat& t) {
  /**
   * Estimates the change in position from T to T+1
   * Params:
   *      p1: features at time T
   *      p2: features at time T + 1
   *      mask: Empty matrix. 0 for outliers, else 1
   *      r: Empty matrix to store rotation matrix
   *      t: Empty matrix to store translation matrix
   * */

  // calibration from dataset
  cv::Point2d principal_point = cv::Point2d(607.1928, 185.2157);
  double focal_length = 718.8560;

  cv::Mat E = cv::findEssentialMat(p1, p2, focal_length, principal_point,
                                   cv::RANSAC, 0.99, 1.0, mask);
  cv::recoverPose(E, p1, p2, r, t, focal_length, principal_point, mask);
}
