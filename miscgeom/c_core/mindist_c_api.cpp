/*
This file contains the C API for the source testing functions. To be accessed by c extension module definition.
*/


#include "min_distance.hpp"
#include "mindist_c_api.h"


extern "C" {

double _minDistancePP(double p1[], double q1[]) {   
    Point3D p1_pt(p1[0], p1[1], p1[2]);
    Point3D q1_pt(q1[0], q1[1], q1[2]);
    return minDistancePP(p1_pt, q1_pt);
}

double _minDistancePS(double p1[], double q1[], double q2[]) {
    Point3D p1_pt(p1[0], p1[1], p1[2]);
    Point3D q1_pt(q1[0], q1[1], q1[2]);
    Point3D q2_pt(q2[0], q2[1], q2[2]);
    return minDistancePS(p1_pt, q1_pt, q2_pt);
}

double _minDistancePL(double p1[], double q1[], double q2[]) {
    Point3D p1_pt(p1[0], p1[1], p1[2]);
    Point3D q1_pt(q1[0], q1[1], q1[2]);
    Point3D q2_pt(q2[0], q2[1], q2[2]);
    return minDistancePL(p1_pt, q1_pt, q2_pt);
}

double _minDistanceSS(double p1[], double p2[], double q1[], double q2[]) {
    Point3D p1_pt(p1[0], p1[1], p1[2]);
    Point3D p2_pt(p2[0], p2[1], p2[2]);
    Point3D q1_pt(q1[0], q1[1], q1[2]);
    Point3D q2_pt(q2[0], q2[1], q2[2]);
    return minDistanceSS(p1_pt, p2_pt, q1_pt, q2_pt);
}

double _minDistanceSL(double p1[], double p2[], double q1[], double q2[]) {
    Point3D p1_pt(p1[0], p1[1], p1[2]);
    Point3D p2_pt(p2[0], p2[1], p2[2]);
    Point3D q1_pt(q1[0], q1[1], q1[2]);
    Point3D q2_pt(q2[0], q2[1], q2[2]);
    return minDistanceSL(p1_pt, p2_pt, q1_pt, q2_pt);
}

double _minDistanceLL(double p1[], double p2[], double q1[], double q2[]) {
    Point3D p1_pt(p1[0], p1[1], p1[2]);
    Point3D p2_pt(p2[0], p2[1], p2[2]);
    Point3D q1_pt(q1[0], q1[1], q1[2]);
    Point3D q2_pt(q2[0], q2[1], q2[2]);
    return minDistanceLL(p1_pt, p2_pt, q1_pt, q2_pt);
}

}
