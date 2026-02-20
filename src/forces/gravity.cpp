#include "gravity.h"

Gravity::Gravity(double mass)
    : Force(Vector2D(0.0, -GRAVITY_ACCELERATION * mass)) {}