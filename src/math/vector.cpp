#include "vector.h"
#include <cmath>

Vector2D Vector2D::operator+(const Vector2D &other) const {
  return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
  return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(double scalar) const {
  return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator*(const Vector2D &other) const {
  return Vector2D(x * other.x, y * other.y);
}

std::ostream &operator<<(std::ostream &os, const Vector2D &vec) {
  os << "Vector(" << vec.x << ", " << vec.y << ")";
  return os;
}
double Vector2D::length() const { return std::sqrt(x * x + y * y); }
