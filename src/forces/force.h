#ifndef FORCE_H
#define FORCE_H

#include "math/vector.h"

class Force {
public:
  Force(Vector2D forceVector) : forceVector(forceVector) {}
  virtual ~Force() = default;
  virtual void update(double delta_time) {};

  // 力的合成
  Force operator+(const Force &other) const;

  // 输出
  friend std::ostream &operator<<(std::ostream &os, const Force &force);

  Vector2D forceVector;
};

#endif