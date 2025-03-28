#include "min_distance.hpp"
#include "Point3D.hpp"
#include "math.h"
#include "utils.hpp"
#include "Eigen/Dense"


/*
euclidean distance between two 3D points
*/
double minDistancePP(Point3D p1, Point3D q1) {
    return (p1 - q1).norm();
}


/*
min euclidean distance between a 3D point p1 and a 3D line segment q1---q2
*/
double minDistancePS(Point3D p1, Point3D q1, Point3D q2) {
    double A = (q1 - q2) * (q1 - q2);
    double B = (q2 - q1) * (q1 - p1);
    double C = (q1 - p1) * (q1 - p1);

    double t_min = -B / A;
    if (abs(t_min) < TOL || t_min < 0.0) {  // t_min <= 0, within tolerance
        return sqrt(C);
    } else if (abs(t_min - 1.0) < TOL || t_min > 1.0) {  // t_min >= 1, within tolerance
        return sqrt(A + (2*B) + C);
    } else {  // 0 < t_min < 1
        return sqrt((A*t_min*t_min) + (2*B*t_min) + C);
    }
}


/*
min euclidean distance between a 3D point p1 and the infinite 3D line containing q1---q2
*/
double minDistancePL(Point3D p1, Point3D q1, Point3D q2) {
    double A = (q1 - q2) * (q1 - q2);
    double B = (q2 - q1) * (q1 - p1);
    double C = (q1 - p1) * (q1 - p1);

    double t_min = -B / A;
    
    return sqrt((A*t_min*t_min) + (2*B*t_min) + C);
}


/*
min euclidean distance between two 3D line segments p1---p2 and q1---q2
*/
double minDistanceSS(Point3D p1, Point3D p2, Point3D q1, Point3D q2) {
    return(0.0);
}


/*
min euclidean distance between a 3D line segment p1---p2 and the infinite line containing q1---q2
*/
double minDistanceSL(Point3D p1, Point3D p2, Point3D q1, Point3D q2) {
    return(0.0);
}


/*
min euclidean distance between two infinite 3D lines, containing p1---p2 and q1---q2, respectively
*/
double minDistanceLL(Point3D p1, Point3D p2, Point3D q1, Point3D q2) {
    // check if lines are parallel. If so, distance can be found using
    // point to line minimum distance
    if (abs(abs((p2 - p1).normalize() * (q2 - q1).normalize()) - 1.0) < TOL) {
        return minDistancePL(p1, q1, q2);
    }

    // M:
    //      A -C
    //     -C  B
    Eigen::Matrix<double, 2, 2> M;
    M(0, 0) = (p2 - p1) * (p2 - p1);  // A
    M(0, 1) = -1 * ((p2 - p1) * (q2 - q1));  // -C
    M(1, 0) = M(0, 1);  // -C
    M(1, 1) = (q2 - q1) * (q2 - q1);  // B

    // k:
    //      D
    //      E
    Eigen::Matrix<double, 2, 1> k;
    k(0, 0) = -1 * ((p2 - p1) * (p1 - q1));  // D
    k(1, 0) = -1 * ((q2 - q1) * (q1 - p1));  // E

    // F
    double F = (p1 - q1) * (p1 - q1);  // F

    // conjugate gradient method to find min s,t
    Eigen::Matrix<double, 2, 1> s0;
    s0(0, 0) = 0.0;
    s0(1, 0) = 0.0;

    Eigen::Matrix<double, 2, 1> v0;
    v0(0, 0) = 1.0;
    v0(1, 0) = 0.0;

    double alpha0 = -1.0 * ((v0.transpose() * k)(0, 0) / (v0.transpose() * M * v0)(0, 0));

    Eigen::Matrix<double, 2, 1> s1 = s0 + (alpha0 * v0);

    Eigen::Matrix<double, 2, 1> v1;
    v1(0, 0) = -1 * M(0, 1);  // getting C from M matrix
    v1(1, 0) = M(0, 0);  // getting A from M matrix

    double alpha1 = -1.0 * ((v1.transpose() * k)(0, 0) / (v1.transpose() * M * v1)(0, 0));

    Eigen::Matrix<double, 2, 1> s2 = s1 + (alpha1 * v1);

    // evaluate R function at s2 (global minimum)
    double s = s2(0, 0);
    double t = s2(1, 0);

    double R_min = (s2.transpose() * M * s2)(0, 0) + (2.0 * (k.transpose() * s2)(0, 0)) + F;

    return sqrt(R_min);  // return square root of R_min to get min distance
}
