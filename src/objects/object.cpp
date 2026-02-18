#include "object.h"

void Object::updateKinematics(double delta_time) {
  velocity = velocity + acceleration * delta_time;
  position = position + velocity * delta_time;
}
