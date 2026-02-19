#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include <vector>

class Sphere : public Object {
public:
  double radius;

  Sphere(double radius = 1.0, double mass = 1.0, Vector2D position = Vector2D(),
         Vector2D velocity = Vector2D(), Vector2D acceleration = Vector2D())
      : Object(mass, position, velocity, acceleration), radius(radius) {}

  void update(double delta_time) override;

  std::vector<Vector2D> getVertices() const override;
};
 
#endif