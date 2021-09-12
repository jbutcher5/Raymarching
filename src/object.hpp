#pragma once
#include "vec2.hpp"

struct Object{
  Vec2 pos;

  virtual float signedDistance(const Vec2& point) const = 0;
  virtual void draw(const int, const int) const = 0;
  virtual float getIntersectRotation(const Vec2) const = 0;
};

struct Circle : Object{
  float radius;

  Circle();
  Circle(float, float, float);

  float signedDistance(const Vec2&) const override;
  void draw(const int, const int) const override;
  float getIntersectRotation(const Vec2) const override;
};

struct TraceCircle : public Circle{
  float th;

  TraceCircle();
  TraceCircle(float, float, float, float);
};

struct Square : public Object{
  Vec2 width;
  float degPerSide = 90;

  Square();
  Square(float, float, float, float);

  float signedDistance(const Vec2&) const override;
  void draw(const int, const int) const override;
  float getIntersectRotation(const Vec2) const override;
};
