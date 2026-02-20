#include "graphic/engine.h"

int main(int argc, char *argv[]) {
  EngineConfigure engineConfig;

  engineConfig.window_width = 800;
  engineConfig.window_height = 600;
  engineConfig.window_title = "Dynamics";

  Engine engine(engineConfig);

  engine.run();
}

#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
  int argc = __argc;
  char **argv = __argv;

  int ret = main(argc, argv);

  return ret;
}
#endif
