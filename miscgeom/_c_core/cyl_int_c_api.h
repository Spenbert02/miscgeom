/*
Defines the C API for the cylinder intersection functions. To be accessed by c extension module definition.
*/

#ifndef CYL_INT_C_API_H
#define CYL_INT_C_API_H
#endif

#ifdef __cplusplus
extern "C" {
#endif

    int intersectsCylinder(double *cyl_path, double *other_path, int size_cyl, int size_other, double sweep_diameter);

#ifdef __cplusplus
}
#endif
