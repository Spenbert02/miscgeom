#pragma once

#include "Point3D.hpp"


double minDistancePP(Point3D p1, Point3D q1);
double minDistancePS(Point3D p1, Point3D q1, Point3D q2);
double minDistancePL(Point3D p1, Point3D q1, Point3D q2);
double minDistanceSS(Point3D p1, Point3D p2, Point3D q1, Point3D q2);
double minDistanceSL(Point3D p1, Point3D p2, Point3D q1, Point3D q2);
double minDistanceLL(Point3D p1, Point3D p2, Point3D q1, Point3D q2);
