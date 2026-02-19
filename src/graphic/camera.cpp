#include "camera.h"
// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <cmath>

void Camera::processInput(GLFWwindow* window, double dt) {
  const double move = MOVE_SPEED / zoom * dt;

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) position.y += move;
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) position.y -= move;
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) position.x -= move;
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) position.x += move;

  if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
    zoom *= std::pow(ZOOM_FACTOR, dt);
  if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
    zoom /= std::pow(ZOOM_FACTOR, dt);

  if (zoom < 0.01) zoom = 0.01;
  if (zoom > 500.0) zoom = 500.0;
}
