#include <iostream>
#include <vector>
#include "Eigen/Core"

using namespace std;

struct CameraParameters {
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    CameraParameters() {
        f.setZero();
        c.setZero();
        k.setZero();
        p.setZero();
        Tbc.setZero();
    };

    inline bool isInitial() {
        bool flag = false;
        if ((c(0) == 0.0) && (c(1) == 0.0) && (f(0) == 0.0) && (f(1) == 0.0) && (k(0) == 0.0) && (k(1) == 0.0) &&
            (p(0) == 0.0) && (p(1) == 0.0)) {
            // if (c(0) == 0.0) {
            flag = true;
        }
        return flag;
    }

    Eigen::Vector2d f;    // focal length, fx, fy
    Eigen::Vector2d c;    // optical center, or principal point, cx, cy
    Eigen::Vector2d k;    // radical distortion parameters, k1, k2
    Eigen::Vector2d p;    // tangential distortion parameters, p1, p2
    Eigen::Matrix4d Tbc;  // extrinsic matrix Tbc, from body to camera
};

int main(int argc, char* argv[]) {
    CameraParameters cp;
    cout << cp.c(0) << endl;
    bool k = cp.isInitial();
    cout << k << endl;
}
