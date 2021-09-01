#pragma once
#include "vec2.hpp"
#include <cmath>


struct Circle{
  Vec2 pos;
  float radius;

  float signedDistance(const Vec2& point) const{
    return sqrt(
      power2(pos.x-point.x)+power2(pos.y-point.y)
    ) - radius;
  }
};
