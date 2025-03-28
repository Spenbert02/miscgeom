/*
Defines the C API for the minimum distance functions. To be accessed by c extension module definition.
*/

#ifndef MINDIST_C_API_H
#define MINDIST_C_API_H
#endif

#ifdef __cplusplus
extern "C" {
#endif

    double _minDistancePP(double p1[], double q1[]);
    double _minDistancePS(double p1[], double q1[], double q2[]);
    double _minDistancePL(double p1[], double q1[], double q2[]);
    double _minDistanceSS(double p1[], double p2[], double q1[], double q2[]);
    double _minDistanceSL(double p1[], double p2[], double q1[], double q2[]);
    double _minDistanceLL(double p1[], double p2[], double q1[], double q2[]);

#ifdef __cplusplus
}
#endif