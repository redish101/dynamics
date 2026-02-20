set(PLATFORM)

if(APPLE)
    set(MACOSX_BUNDLE_BUNDLE_NAME "dynamics")
    set(MACOSX_BUNDLE_GUI_IDENTIFIER "top.redish101.dynamics")
    set(MACOSX_BUNDLE_BUNDLE_VERSION "1.0.0")
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0.0")
    set(PLATFORM "MACOSX_BUNDLE")
endif()

if(WIN32)
    set(PLATFORM "WIN32")
endif()

add_executable(dynamics ${PLATFORM} main.cpp

    # 图形引擎
    graphic/engine.cpp
    graphic/camera.cpp

    # 物理引擎
    forces/force.cpp
    forces/gravity.cpp
    world.cpp

    # 数学
    math/vector.cpp

    # 物体类
    objects/object.cpp
    objects/sphere.cpp
)

target_include_directories(dynamics PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(dynamics PRIVATE glad glfw)