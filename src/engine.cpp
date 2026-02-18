#include "engine.h"
#include "objects/sphere.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Engine::Engine(EngineConfigure config) { this->config = config; }

Engine::~Engine() {}

void Engine::run() { init(); }

double delta_time = 0.0;

void Engine::init() {
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

//   glEnable(GL_LINE_SMOOTH);
//   glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

  while (!glfwWindowShouldClose(window) &&
         glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
    update();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
}

void Engine::update() {

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // 使用帧缓冲像素计算中心点，保证在高 DPI（Retina）显示器上仍然居中
  int fbw_u = 0, fbh_u = 0;
  glfwGetFramebufferSize(window, &fbw_u, &fbh_u);
  if (fbw_u == 0 || fbh_u == 0) {
    fbw_u = config.window_width;
    fbh_u = config.window_height;
  }

  Vector center((double)fbw_u / 2.0, (double)fbh_u / 2.0);

  Sphere sphere(50.0, 1.0, center + Vector(0.0, 400.0), Vector(50.0, 0.0),
                Vector(0.0, -9.8));
  sphere.render(1.0 / config.tps);

  delta_time += 1.0 / config.tps;

  if (delta_time > 3) {
    delta_time = 0.0;
    std::cout << sphere << std::endl;
  }
}
