#include "Point3D.h"
#include <math.h>


// constructor
Point3D::Point3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// addition
Point3D Point3D::operator+(const Point3D& other) {
    return Point3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

// subtraction
Point3D Point3D::operator-(const Point3D& other) {
    return Point3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

// scalar multiplication (use 1/scalar for division)
Point3D Point3D::operator*(double scalar) {
    return Point3D(this->x * scalar, this->y * scalar, this->z * scalar);
}

// dot product
double Point3D::operator*(const Point3D& other) {
    return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

// cross product
Point3D Point3D::cross(const Point3D& other) {
    return Point3D(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
}

// norm
double Point3D::norm() {
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

// get normalized point (new point)
Point3D Point3D::normalize() {
    double l = this->norm();
    return Point3D(this->x / l, this->y / l, this->z / l);
}
