#include "world.h"
#include "forces/gravity.h"
#include "graphic/engine.h"
#include "objects/sphere.h"

void World::addObject(std::unique_ptr<Object> obj) {
  objects.push_back(std::move(obj));
}

void World::init() {
  // 世界单位: 米 (m)，重力加速度 9.8 m/s²
  // 初始位置在屏幕中央偏左下（约 x=3, y=3），屏幕范围约 10m×7.5m
  auto sphere_with_gravity = std::make_unique<Sphere>(
      0.3, 2.0, Vector2D(3.0, 3.0), Vector2D(2.0, 5.0), Vector2D(0.0, 0.0));
  sphere_with_gravity->applyForce(Gravity(sphere_with_gravity->mass));
  addObject(std::move(sphere_with_gravity));
  addObject(std::make_unique<Sphere>(0.3, 2.0, Vector2D(4.0, 3.0),
                                     Vector2D(0.0, 0.0), Vector2D(0.0, 0.0)));
}

void World::update(double delta_time) {
  for (auto &obj : objects) {
    obj->update(delta_time);
  }
}
