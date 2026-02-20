#include "sphere.h"
#include <cmath>

// 每步度数
constexpr double ANGLE_STEP = 1.0;

#ifdef _WIN32
#define M_PI 3.14159265358979323846264338327950288
#endif

void Sphere::update(double delta_time) { updateKinematics(delta_time); }

std::vector<Vector2D> Sphere::getVertices() const {
  std::vector<Vector2D> vertices;
  vertices.reserve(static_cast<size_t>(360.0 / ANGLE_STEP));

  for (double angle = 0; angle < 360; angle += ANGLE_STEP) {
    double rad = angle * M_PI / 180.0;
    double x = position.x + radius * cos(rad);
    double y = position.y + radius * sin(rad);
    vertices.emplace_back(x, y);
  }

  return vertices;
}