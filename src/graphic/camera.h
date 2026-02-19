#ifndef CAMERA_H
#define CAMERA_H

#include "math/vector.h"

// 2D 正交摄像机：管理世界坐标 <-> 屏幕坐标的变换
// 世界坐标原点对应屏幕中心，zoom 为每世界单位对应的像素数
class Camera {
public:
  Camera(int screen_w, int screen_h, double zoom = 1.0,
         Vector2D position = Vector2D())
      : screen_w(screen_w), screen_h(screen_h), zoom(zoom),
        position(position) {}

  // 将世界坐标转为屏幕像素坐标
  Vector2D worldToScreen(const Vector2D& p) const {
    return Vector2D(
        screen_w * 0.5 + (p.x - position.x) * zoom,
        screen_h * 0.5 + (p.y - position.y) * zoom);
  }

  // 根据键盘输入更新摄像机状态
  void processInput(struct GLFWwindow* window, double delta_time);

  // 窗口大小改变时同步，同时按新尺寸重算原点偏移
  void resize(int w, int h) {
    screen_w = w;
    screen_h = h;
    // 让世界原点(0,0)落在屏幕左下角
    // worldToScreen: screen_center + (world - position) * zoom
    // 左下角对应 world = (0,0)，要求 screen = (0,0)：
    // 0 = screen_w/2 + (0 - position.x) * zoom  =>  position.x = screen_w/2/zoom
    position = Vector2D((double)w * 0.5 / zoom, (double)h * 0.5 / zoom);
  }

  double zoom;
  Vector2D position; // 世界坐标系中的摄像机中心

private:
  int screen_w, screen_h;

  static constexpr double MOVE_SPEED  = 300.0; // 世界单位/秒
  static constexpr double ZOOM_FACTOR = 1.5;   // 每秒缩放倍率
};

#endif
