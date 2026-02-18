#include "engine.h"

int main(int argc, char* argv[]) {
    Engine engine(EngineConfigure{
        .window_width = 800,
        .window_height = 600,
        .window_title = "Dynamics",
        .tps = 240
    });

    engine.run();
}