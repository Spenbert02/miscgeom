#pragma once

#ifdef __cplusplus

class Point3D {
    public:
        double x, y, z;

        Point3D(double x, double y, double z);
        Point3D operator+(const Point3D& other);
        Point3D operator-(const Point3D& other);
        Point3D operator*(double scalar);
        double operator*(const Point3D& other);
        Point3D cross(const Point3D& other);
        double norm();
        Point3D normalize();
};

#endif
