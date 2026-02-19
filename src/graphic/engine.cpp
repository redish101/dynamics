#include "graphic/engine.h"
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
    if (delta_time > 0.1)
      delta_time = 0.1;

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

  // 启用 MSAA 4x 多重采样抗锯齿
  glfwWindowHint(GLFW_SAMPLES, 4);

  window = glfwCreateWindow(config.window_width, config.window_height,
                            config.window_title, nullptr, nullptr);

  if (!window) {
    std::cerr << "无法创建窗口\n" << std::endl;
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return;
  }

  glfwSwapInterval(1); // 启用垂直同步

  // 启用 MSAA 多重采样
  glEnable(GL_MULTISAMPLE);

  // 设置视口和正交投影
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

  glLineWidth(5.0f);

  glEnable(GL_LINE_SMOOTH);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Engine::initPhysics() {
  world = World();
  world.init();
}

void Engine::update(double delta_time) {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  world.update(delta_time);

  // 渲染所有物体
  const float LINE_HALF_W = 2.5f; // 线宽的一半（像素）
  for (const auto &obj : world.getObjects()) {
    const auto &verts = obj->getVertices();
    if (verts.empty())
      continue;

    const size_t n = verts.size();
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(obj->color[0], obj->color[1], obj->color[2]);

    for (size_t i = 0; i <= n; i++) {
      // 当前顶点与前后顶点（环形取模）
      const Vector2D &prev = verts[(i + n - 1) % n];
      const Vector2D &cur = verts[i % n];
      const Vector2D &next = verts[(i + 1) % n];

      // 两段方向的法线（指向外侧）
      double tx1 = cur.x - prev.x, ty1 = cur.y - prev.y;
      double len1 = std::sqrt(tx1 * tx1 + ty1 * ty1);
      if (len1 > 0) {
        tx1 /= len1;
        ty1 /= len1;
      }

      double tx2 = next.x - cur.x, ty2 = next.y - cur.y;
      double len2 = std::sqrt(tx2 * tx2 + ty2 * ty2);
      if (len2 > 0) {
        tx2 /= len2;
        ty2 /= len2;
      }

      // 平均法线（miter 方向）
      double nx = -(ty1 + ty2), ny = tx1 + tx2;
      double nl = std::sqrt(nx * nx + ny * ny);
      if (nl > 0) {
        nx /= nl;
        ny /= nl;
      }

      // miter 缩放：保证垂直线宽恒为 LINE_HALF_W
      double miter = LINE_HALF_W;
      double dot = nx * (-ty1) + ny * tx1; // cos(半角)
      if (std::abs(dot) > 0.01)
        miter = LINE_HALF_W / dot;
      // 限制过尖的 miter
      if (miter > LINE_HALF_W * 4.0)
        miter = LINE_HALF_W * 4.0;

      glVertex2d(cur.x + nx * miter, cur.y + ny * miter); // 外侧
      glVertex2d(cur.x - nx * miter, cur.y - ny * miter); // 内侧
    }
    glEnd();
  }
}

Vector2D Engine::getCenterPosition() {
  int fbw = 0, fbh = 0;
  glfwGetFramebufferSize(window, &fbw, &fbh);
  if (fbw == 0 || fbh == 0) {
    fbw = config.window_width;
    fbh = config.window_height;
  }
  return Vector2D((double)fbw / 2.0, (double)fbh / 2.0);
}
