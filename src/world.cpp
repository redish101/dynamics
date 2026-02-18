#include "world.h"
#include "engine.h"
#include "objects/sphere.h"

void World::addObject(std::unique_ptr<Object> obj) {
  objects.push_back(std::move(obj));
}

void World::init() {
  Vector position = Vector(200.0, 800.0);
  addObject(std::make_unique<Sphere>(50.0, 2.0, position, Vector(70.0, 200.0),
                                     Vector(0, -98)));
}

void World::update(double delta_time) {
  for (auto &obj : objects) {
    obj->update(delta_time);
  }
}

void World::render(double delta_time) {
  for (auto &obj : objects) {
    obj->render(delta_time);
  }
}
