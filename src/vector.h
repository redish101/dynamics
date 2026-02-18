#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <ostream>

// 二维矢量
struct Vector {
  double x,y;

  Vector() : x(0), y(0) {}
  Vector(double x, double y) : x(x), y(y) {}

  Vector operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y);
  }

  Vector operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y);
  }

  Vector operator*(double scalar) const {
    return Vector(x * scalar, y * scalar);
  }

  Vector operator*(const Vector& other) const {
    return Vector(x * other.x, y * other.y);
  }

  friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "Vector(" << vec.x << ", " << vec.y << ")";
    return os;
  }

  double length() const {
    return std::sqrt(x * x + y * y);
  }
};

#endif