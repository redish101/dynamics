#include "object.h"
#include "forces/force.h"

void Object::applyForce(const Force &force) {
  forces.push_back(new Force(force));
}

void Object::updateKinematics(double delta_time) {
  // 重置加速度
  acceleration = Vector2D();

  // 计算总加速度
  for (const auto &force : forces) {
    acceleration = acceleration + Vector2D(force->forceVector.x / mass,
                                           force->forceVector.y / mass);
  }

  velocity = velocity + acceleration * delta_time;
  position = position + velocity * delta_time;
}
