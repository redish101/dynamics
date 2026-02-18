#include "sphere.h"
#include <glad/glad.h>
#include <cmath>

// 每步度数
constexpr double ANGLE_STEP = 1.0;

void Sphere::update(double delta_time) {
  // 更新运动学状态
  updateKinematics(delta_time);
}

void Sphere::render(double delta_time) {
  glBegin(GL_LINE_LOOP);

  glColor3f(color[0], color[1], color[2]);

  update(delta_time);

  for (double angle = 0; angle < 360; angle += ANGLE_STEP) {
    double rad = angle * M_PI / 180.0; // 转换为弧度
    double x = position.x + radius * cos(rad);
    double y = position.y + radius * sin(rad);
    glVertex2d(x, y);
  }

  glEnd();
}