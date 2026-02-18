#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"

class Sphere : public Object {
public:
  double radius;

  Sphere(double radius = 1.0, double mass = 1.0, Vector position = Vector(),
         Vector velocity = Vector(), Vector acceleration = Vector())
      : Object(mass, position, velocity, acceleration), radius(radius) {}

  void update(double delta_time) override;
  void render(double delta_time) override;
};
 
#endif