#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

// 二维矢量
struct Vector2D {
  double x, y;

  Vector2D() : x(0), y(0) {}
  Vector2D(double x, double y) : x(x), y(y) {}

  // 加
  Vector2D operator+(const Vector2D &other) const;

  // 减
  Vector2D operator-(const Vector2D &other) const;

  // 数乘
  Vector2D operator*(double scalar) const;

  // 点乘
  Vector2D operator*(const Vector2D &other) const;

  // 输出
  friend std::ostream &operator<<(std::ostream &os, const Vector2D &vec);

  // 模
  double length() const;
};

#endif