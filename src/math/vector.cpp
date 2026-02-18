#include "vector.h"
#include <cmath>

Vector Vector::operator+(const Vector &other) const {
  return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector &other) const {
  return Vector(x - other.x, y - other.y);
}

Vector Vector::operator*(double scalar) const {
  return Vector(x * scalar, y * scalar);
}

Vector Vector::operator*(const Vector &other) const {
  return Vector(x * other.x, y * other.y);
}

std::ostream &operator<<(std::ostream &os, const Vector &vec) {
  os << "Vector(" << vec.x << ", " << vec.y << ")";
  return os;
}
double Vector::length() const { return std::sqrt(x * x + y * y); }
