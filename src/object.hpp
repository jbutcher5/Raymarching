#pragma once
#include "vec2.hpp"
#include <cmath>
#include <raylib.h>


struct Object{
public:
  Vec2 pos;

  virtual float signedDistance(const Vec2& point) const = 0;
  virtual void draw(const int, const int) const = 0;
};

struct Circle : public Object{
  Vec2 pos;
  float radius;

  Circle(){
    Circle(0., 0., 0.);
  }

  Circle(float rad, float x, float y){
    this->radius = rad;
    this->pos.set(x, y);
  }

  float signedDistance(const Vec2& point) const override{
    return sqrt(
      power2(pos.x-point.x)+power2(pos.y-point.y)
    ) - radius;
  }

  void draw(const int screenWidth, const int screenHeight) const override{

    Vector2 screenPosition = {pos.x+(screenWidth/2), pos.y+(screenHeight/2)};

    DrawCircleV(screenPosition, this->radius, GREEN);
  }
};
