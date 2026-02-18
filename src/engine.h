#ifndef ENGINE_H
#define ENGINE_H

// 前向声明 GLFWwindow，避免在头文件中直接包含 GLFW/GL headers
struct GLFWwindow;

struct EngineConfigure {
    int window_width;
    int window_height;
    const char* window_title;

    // Tick per second
    int tps;
};

class Engine {
public:
  Engine(EngineConfigure config);
  ~Engine();

  void run();

private:
  void init();
  void update();

  EngineConfigure config;

  GLFWwindow* window;
};

#endif