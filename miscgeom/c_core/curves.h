#ifndef CURVES_H
#define CURVES_H


void _lagrangeInterpolation1D(double* t_data, double* control_points_data, int num_control_points, double* result_data, int t_size);
double _L_i(double t, int i, double* control_points_data, int control_points_size);

#endif