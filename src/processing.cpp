//
// Created by laguna on 3/26/20.
//
#include <fstream>
#include "../include/processing.h"
#include "../include/features.h"

typedef unsigned char uchar;

void displayFeatures(cv::Mat& img, std::vector<cv::Point2f>& pts_t0, std::vector<cv::Point2f>& pts_t1) {
    int radius = 2;
    cv::Mat feats;

    // convert grayscale img to color in order to display
    // colored points on it
    cv::cvtColor(img, feats, cv::COLOR_GRAY2BGR);

    // draw circle for detected features
    for (int i = 0; i < pts_t0.size(); i++) {
        if (i % 10 == 0) {
            cv::circle(feats, cv::Point(pts_t0[i].x, pts_t0[i].y), radius, CV_RGB(0, 137, 255));
        }
    }

    // draw line from pts at time=1 to time=0 to show velocity
    for (int i = 0; i < pts_t0.size(); i++) {
        if (i % 10 == 0) {
            cv::line(feats, pts_t0[i], pts_t1[i], CV_RGB(0,137,255));
        }
    }
    cv::imshow("Features", feats);
}

void displayTrajectory(cv::Mat& pose, cv::Mat& trajectory, cv::Point2f& groundTruth) {
    // Load groundTruth at frame

    // Calculate x,y coords from current pose
    int x = int(pose.at<double>(0)) + 300;
    int y = int(pose.at<double>(2)) + 800;

    cv::circle(trajectory, cv::Point2f(x, y), 1, CV_RGB(0, 137, 255), 1);
//    cv::circle(trajectory, groundTruth, 1, CV_RGB(255, 67, 67), 2);
    cv::imshow("Trajectory", trajectory);
}

void sequenceFrames() {
    char fileImg[100]{};
    char file_gt[100]{};
    cv::Mat frame_t0, frame_t1, frame_t1_c, rPose, tPose;
    cv::Point2f groundTruth;
    std::vector<cv::Point2f> pts_t0, pts_t1;
    std::vector<uchar> status;
    cv::Mat trajectory = cv::Mat::zeros(1000, 1000, CV_8UC3);

    // TODO: drawing goes out of sight
    cv::namedWindow( "Features", cv::WINDOW_AUTOSIZE );// Create a window for display.
    cv::namedWindow( "Trajectory", cv::WINDOW_GUI_NORMAL);// Create a window for display.
//    cv::resizeWindow("Trajectory", 1600, 1600);

    // TODO: change to variable name
    std::ifstream file("../dataset/poses/02.txt");

    // TODO: remove branches from hot path
    for(int frameCnt = 0; frameCnt < MAX_FRAMES; frameCnt++) {
        cv::Mat r, t, mask;

        sprintf(fileImg, "../dataset/sequences/02/image_0/%06d.png", frameCnt);
        std::cout << fileImg << "\n";
        frame_t1_c = cv::imread(fileImg);

        // Make into gray images
        cv::cvtColor(frame_t1_c, frame_t1, cv::COLOR_BGR2GRAY);

        // Load ground truth
        std::string poseStr;
        std::getline(file, poseStr); // get new line from the ground truth file
        auto groundTruth = loadGroundTruth(poseStr);

        if (frameCnt == 0) {
            detectFeatures(frame_t1, pts_t1);
        }
        else {
            if (frameCnt == 1) {
                estimatePose(pts_t0, pts_t1, mask, r, t);

                tPose = t.clone();
                rPose = r.clone();
            }
            else if (frameCnt > 1){
                trackFeatures(frame_t0, frame_t1, pts_t0, pts_t1, status);
                estimatePose(pts_t0, pts_t1, mask, r, t);
                auto scale = getScale(frameCnt);

                if (scale > 0.1) {
                    tPose = tPose + scale * (rPose * t);
                    rPose = r * rPose;
                }
                if (pts_t1.size() < MIN_FEATURE_THRESHOLD) {
                    detectFeatures(frame_t0, pts_t0);
                    trackFeatures(frame_t0, frame_t1, pts_t0, pts_t1, status);
                }
                // Display the tracked features and the
                // camera feed as
                // as well as drawing the trajectory
                displayFeatures(frame_t1, pts_t0, pts_t1);
                displayTrajectory(tPose, trajectory, groundTruth);
            }
        }
        // Put everything at time=1
        // to time=0
        frame_t0 = frame_t1.clone();
        pts_t0 = pts_t1;
        cv::waitKey(1);
    }
}

// From Avi Singh
double getScale(int frameCnt) {
    std::string line;
    int i = 0;
    std::ifstream myfile("../dataset/poses/02.txt");
    double x =0, y=0, z = 0;
    double x_prev, y_prev, z_prev;

    if (myfile.is_open()) {
        while (( getline (myfile,line) ) && (i<=frameCnt)) {
            z_prev = z;
            x_prev = x;
            y_prev = y;
            std::istringstream in(line);
            for (int j=0; j<12; j++)  {
                in >> z ;
                if (j==7) y=z;
                if (j==3)  x=z;
            }
            i++;
        }
        myfile.close();
    }

    else {
        std::cout << "Unable to open file";
        return 0;
    }
    return sqrt((x-x_prev)*(x-x_prev) + (y-y_prev)*(y-y_prev) + (z-z_prev)*(z-z_prev)) ;
}
