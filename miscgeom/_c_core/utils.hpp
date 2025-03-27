/*
Contains the definitions of the helper functions used to determine if a curve intersects a cylinder.
*/


#pragma once


const double TOL = 0.000001;  // 10^-6, tolerance for zero approximation in numerical calculations


void copyvals(double vec1[], double vec2[]);
void mult(double vec[], double factor);
void divide(double vec[], double factor);
void add(double vec1[], double vec2[], double output[]);
void subtract(double vec1[], double vec2[], double output[]);
void cross(double vec1[], double vec2[], double output[]);
double dot(double vec1[], double vec2[]);
void normalize(double vec[]);
double magnitude(double vec[]);
double distance(double point1[], double point2[]);
int isEqual(double vec1[], double vec2[]);
void matrixMult(double m[3][3], double x[3], double out[3]);
int pointInsidePolygon(double vertices[][2], const int num_vertices, double point[]);
