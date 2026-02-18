#ifndef WORLD_H
#define WORLD_H

#include "objects/object.h"
#include <memory>
#include <vector>

class World {
public:
  World() {};
  ~World() {};

  // 禁止拷贝（unique_ptr 不可拷贝）
  World(const World&) = delete;
  World& operator=(const World&) = delete;

  // 允许移动
  World(World&&) = default;
  World& operator=(World&&) = default;

  // 添加物体
  void addObject(std::unique_ptr<Object> obj);

  // 初始化世界
  void init();

  // 更新世界中所有物体
  void update(double delta_time);

  // 渲染世界中所有物体
  void render(double delta_time);

private:
  std::vector<std::unique_ptr<Object>> objects;
};

#endif