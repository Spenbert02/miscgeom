/*
Contains the definitions of the helper functions used to determine if a curve intersects a cylinder.
*/


#pragma once


void fourPointNormals(double p0[], double p1[], double p2[], double p3[], double n1[], double n2[]);
int segmentIntersectsCylinder(double p1[], double p2[], double c1[], double c2[], double n1[], double n2[], double d);
double D(double s, double t, double a, double b, double c, double d, double e, double f);
double minDistSegmentLine(double p0[], double p1[], double q0[], double q1[]);
int truncateSegment(double p1[], double p2[], double n1[], double c1[], double n2[], double c2[]);
void intersection(double p1[], double p2[], double n[], double c[], double output[]);
