#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include <iostream>

// 物体
class Object {
public:
  Object(double mass, Vector position, Vector velocity = Vector(),
         Vector acceleration = Vector())
      : mass(mass), position(position), velocity(velocity),
        acceleration(acceleration) {
    // 初始化颜色为黑色（默认值为 0.0f 表示黑）
    color[0] = 0.0f;
    color[1] = 0.0f;
    color[2] = 0.0f;
  };
  virtual ~Object() {};

  // 更新物体状态
  virtual void update(double delta_time) {};

  // 更新运动学状态
  void updateKinematics(double delta_time);

  // 渲染物体
  virtual void render(double delta_time) {};

  friend std::ostream& operator<<(std::ostream& os, const Object& obj) {
    os << "Object(mass=" << obj.mass << ", position=" << obj.position
       << ", velocity=" << obj.velocity << ", acceleration=" << obj.acceleration
       << ")";
    return os;
  }

  // 物体属性
  // 质量
  double mass;
  // 颜色
  float color[3];

  // 运动学属性
    // 位置
  Vector position;
  // 速度
  Vector velocity;
  // 加速度
  Vector acceleration;
};

#endif