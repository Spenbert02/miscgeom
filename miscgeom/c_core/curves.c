#include "curves.h"

void _lagrangeInterpolation1D(double* t_data, double* control_points_data, int num_control_points, double* result_data, int t_size) {
    for (int t_ind = 0; t_ind < t_size; t_ind++) {  // for each t value to evaluate at
        double t = t_data[t_ind];
        result_data[t_ind] = 0.0;  // initialize the result to 0 just in case not already set
        for (int i = 0; i < num_control_points; i++) {
            result_data[t_ind] += control_points_data[2*i + 1] * _L_i(t, i, control_points_data, num_control_points);
        }
    }
}


double _L_i(double t, int i, double* control_points_data, int control_points_size) {
    double ret_evaluation = 1.0;
    for (int j = 0; j < control_points_size; j++) {
        if (j == i) {
            continue;
        }
        ret_evaluation *= (t - control_points_data[2*j]) / (control_points_data[2*i] - control_points_data[2*j]);
    }
    return ret_evaluation;
}

