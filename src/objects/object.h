#ifndef OBJECT_H
#define OBJECT_H

#include "forces/force.h"
#include "math/vector.h"
#include <iostream>
#include <vector>

// 物体
class Object {
public:
  virtual ~Object() = default;

  Object(double mass, Vector2D position, Vector2D velocity = Vector2D(),
         Vector2D acceleration = Vector2D())
      : mass(mass), position(position), velocity(velocity),
        acceleration(acceleration) {
    // 初始化颜色为黑色（默认值为 0.0f 表示黑）
    color[0] = 0.0f;
    color[1] = 0.0f;
    color[2] = 0.0f;
  };

  // 施加外力
  void applyForce(const Force &force);

  // 更新物体状态
  virtual void update(double delta_time) {};

  // 更新运动学状态
  void updateKinematics(double delta_time);

  // 返回用于渲染的顶点列表
  virtual std::vector<Vector2D> getVertices() const = 0;

  friend std::ostream &operator<<(std::ostream &os, const Object &obj) {
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

  // 物体受力
  std::vector<Force *> forces;

  // 运动学属性
  // 位置
  Vector2D position;
  // 速度
  Vector2D velocity;
  // 加速度
  Vector2D acceleration;
};

#endif