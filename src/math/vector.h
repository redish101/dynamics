#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

// 二维矢量
struct Vector {
  double x, y;

  Vector() : x(0), y(0) {}
  Vector(double x, double y) : x(x), y(y) {}

  // 加
  Vector operator+(const Vector &other) const;

  // 减
  Vector operator-(const Vector &other) const;

  // 数乘
  Vector operator*(double scalar) const;

  // 点乘
  Vector operator*(const Vector &other) const;

  // 输出
  friend std::ostream &operator<<(std::ostream &os, const Vector &vec);

  // 模
  double length() const;
};

#endif