#ifndef GRAVITY_H
#define GRAVITY_H

#include "force.h"

// 重力加速度
constexpr double GRAVITY_ACCELERATION = 9.8; // m/s²

class Gravity : public Force {
public:
  Gravity(double mass);
  ~Gravity() = default;
};

#endif