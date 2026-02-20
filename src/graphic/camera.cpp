#include "camera.h"
// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <cmath>

Vector2D Camera::worldToScreen(const Vector2D &p) const {
  return Vector2D(screen_w * 0.5 + (p.x - position.x) * zoom,
                  screen_h * 0.5 + (p.y - position.y) * zoom);
}

void Camera::resize(int w, int h) {
  screen_w = w;
  screen_h = h;
  // 让世界原点(0,0)落在屏幕左下角
  // 推导：0 = screen_w/2 + (0 - position.x)*zoom => position.x =
  // screen_w/2/zoom
  position = Vector2D(w * 0.5 / zoom, h * 0.5 / zoom);
}

void Camera::processInput(GLFWwindow *window, double dt) {
  const double move = MOVE_SPEED / zoom * dt;

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    position.y += move;
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    position.y -= move;
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    position.x -= move;
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    position.x += move;

  if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
    zoom *= std::pow(ZOOM_FACTOR, dt);
  if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
    zoom /= std::pow(ZOOM_FACTOR, dt);

  if (zoom < 0.01)
    zoom = 0.01;
  if (zoom > 500.0)
    zoom = 500.0;
}
