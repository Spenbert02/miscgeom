#pragma once

#include "Point3D.h"

#ifdef __cplusplus
extern "C" {
#endif

// C API for all functions
double _minDistancePP(double p1[], double q1[]);
double _minDistancePS(double p1[], double q1[], double q2[]);
double _minDistancePL(double p1[], double q1[], double q2[]);
double _minDistanceSS(double p1[], double p2[], double q1[], double q2[]);
double _minDistanceSL(double p1[], double p2[], double q1[], double q2[]);
double _minDistanceLL(double p1[], double p2[], double q1[], double q2[]);

#ifdef __cplusplus
}

double minDistancePP(Point3D p1, Point3D q1);
double minDistancePS(Point3D p1, Point3D q1, Point3D q2);
double minDistancePL(Point3D p1, Point3D q1, Point3D q2);
double minDistanceSS(Point3D p1, Point3D p2, Point3D q1, Point3D q2);
double minDistanceSL(Point3D p1, Point3D p2, Point3D q1, Point3D q2);
double minDistanceLL(Point3D p1, Point3D p2, Point3D q1, Point3D q2);

#endif