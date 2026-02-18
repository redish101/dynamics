#ifndef ENGINE_H
#define ENGINE_H

#include "world.h"

// 前向声明 GLFWwindow，避免在头文件中直接包含 GLFW/GL headers
struct GLFWwindow;

struct EngineConfigure {
    int window_width;
    int window_height;
    const char* window_title;
};

class Engine {
public:
  Engine(EngineConfigure config) : config(config), window(nullptr) {};
  ~Engine() {};

  void run();
  Vector getCenterPosition();
private:
  void initGraphics();
  void initPhysics();
  void update(double delta_time);

  EngineConfigure config;

  GLFWwindow* window;
  double last_time;

  World world;
};

#endif