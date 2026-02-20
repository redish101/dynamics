#include "force.h"

Force Force::operator+(const Force &other) const {
  return Force(Vector2D(forceVector.x + other.forceVector.x,
                        forceVector.y + other.forceVector.y));
}

std::ostream &operator<<(std::ostream &os, const Force &force) {
  os << "Force(vector=" << force.forceVector << ")";
  return os;
}