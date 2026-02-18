add_executable(dynamics main.cpp

    # 图形及物理引擎
    engine.cpp
    world.cpp

    # 数学
    math/vector.cpp

    # 物体类
    objects/object.cpp
    objects/sphere.cpp
)

target_include_directories(dynamics PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(dynamics PRIVATE glad glfw)