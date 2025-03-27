/*
This file contains the C API for the cylinder intersection functions. To be accessed by c extension module definition.
*/


#include <stdlib.h>
#include "cyl_int_c_api.h"
#include "cyl_int.hpp"
#include "utils.hpp"


extern "C" {

/*
determine if a curve intersects the bounding cylinder of another curve. to be used as a port to python
arguments:
- cyl_path: pointer to 1d double array, which in actuality represents an n by 3 array, the points of the curve to use as the
            central axis to the bounding cylinder
- other_path: pointer to 1d double array, which in actuality represents an m by 3 array, the points of the "other" curve
              to check for intersection with the bounding cylinder
- size_cyl: int, the number of points in the cylinder curve array
- size_other: int, the number of points in the "other" curve array
- sweep_diameter: double, the diameter to use for the swept cylinder
- result: int, where the output of the calculation is stored
output:
- result will be assigned 0 if the curve doesn't intersect the cylinder, otherwise 1
*/
int intersectsCylinder(double *cyl_path, double *other_path, int size_cyl, int size_other, double sweep_diameter) {
    // creating local copies for easier indexing - if this takes too much time, can try not doing this
    double (*local_cyl_path)[3] = (double(*)[3])malloc(size_cyl * sizeof(double[3]));
    if (!local_cyl_path) {  // ensure memory allocation was successful
        free(local_cyl_path);
        return -1;
    }
    for (int i = 0; i < size_cyl; i++) {
        for (int j = 0; j < 3; j++) {
            local_cyl_path[i][j] = cyl_path[i*3 + j];
        }
    }

    double (*local_other_path)[3] = (double(*)[3])malloc(size_other * sizeof(double[3]));
    if (!local_other_path) {  // ensure memory allocation was successful
        free(local_cyl_path);  // Free previously allocated memory on error
        return -1;
    }
    for (int i = 0; i < size_other; i++) {
        for (int j = 0; j < 3; j++) {
            local_other_path[i][j] = other_path[i*3 + j];
        }
    }


    // iterating over each segment in the cylinder array
    for (int i = 0; i < size_cyl - 1; i++) {  // with size_cyl # of points, there are size_cyl-1 # of segments
        double p1[3] = {local_cyl_path[i][0], local_cyl_path[i][1], local_cyl_path[i][2]};
        double p2[3] = {local_cyl_path[i+1][0], local_cyl_path[i+1][1], local_cyl_path[i+1][2]};

        // getting normal vectors
        double n1[3];
        double n2[3];
        if (i == 0) {  // first segment, need to "manually" create a point to use for calculating first normal vector
            double p0[3];
            double tmp[3];
            copyvals(tmp, p1);
            mult(tmp, 2);
            subtract(tmp, p2, p0);  // p0 = (2*p1) - p2 = p1 + (p1 - p2), the artificially implanted point
            double p3[3] = {local_cyl_path[2][0], local_cyl_path[2][1], local_cyl_path[2][2]};  // the last point
            fourPointNormals(p0, p1, p2, p3, n1, n2);
        } else if (i == size_cyl - 2) {  // last segment, need to "manually" create the last point for calculating the second normal vector
            double p3[3];
            double tmp[3];
            copyvals(tmp, p2);
            mult(tmp, 2);
            subtract(tmp, p1, p3);  // p3 = (2*p2) - p1 = p2 + (p2 - p1), the artificially created point to get the normal vector
            double p0[3] = {local_cyl_path[size_cyl - 3][0], local_cyl_path[size_cyl - 3][1], local_cyl_path[size_cyl - 3][2]};
            fourPointNormals(p0, p1, p2, p3, n1, n2);
        } else {  // not first or last segment, don't need to artifically create points
            double p0[3] = {local_cyl_path[i-1][0], local_cyl_path[i-1][1], local_cyl_path[i-1][2]};
            double p3[3] = {local_cyl_path[i+2][0], local_cyl_path[i+2][1], local_cyl_path[i+2][2]};
            fourPointNormals(p0, p1, p2, p3, n1, n2);
        }

        for (int j = 0; j < size_other - 1; j++) {  // for every segment of other paths
            double otherp1[3] = {local_other_path[j][0], local_other_path[j][1], local_other_path[j][2]};
            double otherp2[3] = {local_other_path[j+1][0], local_other_path[j+1][1], local_other_path[j+1][2]};
            if (segmentIntersectsCylinder(otherp1, otherp2, p1, p2, n1, n2, sweep_diameter)) {  // the current segments intersects the bounding cylinder
                free(local_cyl_path);
                free(local_other_path);
                return(1);
            }
        }
    }

    // at this point, all of the segment pairs have been checked for intersection, and no intersections have been found
    free(local_cyl_path);
    free(local_other_path);
    return(0);
}

}