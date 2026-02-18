#include "engine.h"
#include "objects/sphere.h"
// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <iostream>

void Engine::run() {
  initGraphics();
  initPhysics();

  last_time = glfwGetTime();

  while (!glfwWindowShouldClose(window) &&
         glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
    double now = glfwGetTime();
    double delta_time = now - last_time;
    last_time = now;

    // 防止窗口拖动/失焦导致 delta_time 过大（超过 100ms 则截断）
    if (delta_time > 0.1) delta_time = 0.1;

    update(delta_time);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
}

void Engine::initGraphics() {
  if (!glfwInit()) {
    std::cerr << "无法初始化GLFW\n" << std::endl;
    return;
  }

  window = glfwCreateWindow(config.window_width, config.window_height,
                            config.window_title, nullptr, nullptr);

  if (!window) {
    std::cerr << "无法创建窗口\n" << std::endl;
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);
  // 初始化 GLAD：必须在创建 OpenGL 上下文并使其 current 之后执行
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return;
  }
  glfwSwapInterval(1); // 启用垂直同步

  // 设置视口和正交投影：使用帧缓冲大小（考虑 Retina / 高 DPI）
  int fbw = 0, fbh = 0;
  glfwGetFramebufferSize(window, &fbw, &fbh);
  if (fbw == 0 || fbh == 0) {
    fbw = config.window_width;
    fbh = config.window_height;
  }
  glViewport(0, 0, fbw, fbh);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // 使用帧缓冲像素为单位的正交投影，使坐标与 glVertex 所用像素一致
  glOrtho(0.0, (double)fbw, 0.0, (double)fbh, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glLineWidth(2.0f);

  // glEnable(GL_LINE_SMOOTH);
  // glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void Engine::initPhysics() {
  world = World();
  world.init();
}

void Engine::update(double delta_time) {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  world.update(delta_time);
  world.render(delta_time);
}

Vector Engine::getCenterPosition() {
  int fbw = 0, fbh = 0;
  glfwGetFramebufferSize(window, &fbw, &fbh);
  if (fbw == 0 || fbh == 0) {
    fbw = config.window_width;
    fbh = config.window_height;
  }
  return Vector((double)fbw / 2.0, (double)fbh / 2.0);
}
