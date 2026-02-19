#ifndef CAMERA_H
#define CAMERA_H

#include "math/vector.h"

struct GLFWwindow;

// 2D 摄像机
class Camera {
public:
  Camera(int screen_w, int screen_h, double zoom = 1.0,
         Vector2D position = Vector2D())
      : screen_w(screen_w), screen_h(screen_h), zoom(zoom),
        position(position) {}

  Vector2D worldToScreen(const Vector2D& p) const;
  void processInput(GLFWwindow* window, double delta_time);
  void resize(int w, int h);

  // 每世界单位对应的像素数
  double zoom;
  Vector2D position; // 世界坐标系中的摄像机中心

private:
  int screen_w, screen_h;

  static constexpr double MOVE_SPEED  = 300.0; // 世界单位/秒
  static constexpr double ZOOM_FACTOR = 1.5;   // 每秒缩放倍率
};

#endif
