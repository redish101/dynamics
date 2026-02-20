#include "graphic/engine.h"

int main(int argc, char *argv[]) {
  EngineConfigure engineConfig;

  engineConfig.window_width = 800;
  engineConfig.window_height = 600;
  engineConfig.window_title = "Dynamics";

  Engine engine(engineConfig);

  engine.run();
}