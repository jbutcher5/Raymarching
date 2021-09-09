#pragma once
#include "vec2.hpp"
#include <cmath>
#include <algorithm>
#include <raylib.h>
#include <iostream>

#define toVec2(x) (Vec2){x, x}

static Vec2 abs(Vec2 x){
  return (Vec2){std::abs(x.x), std::abs(x.y)};
}

static Vec2 max(Vec2 x, Vec2 y){
  Vec2 result;

  result.x = std::fmaxf(x.x, y.x);
  result.y = std::fmaxf(x.y, y.y);

  return result;
}

static Vec2 min(Vec2 x, Vec2 y){
  Vec2 result;

  result.x = std::fminf(x.x, y.x);
  result.y = std::fminf(x.y, y.y);

  return result;
}

struct Object{
  Vec2 pos;

  virtual float signedDistance(const Vec2& point) const = 0;
  virtual void draw(const int, const int) const = 0;
  virtual float getIntersectRotation(const Vec2) const = 0;
};

struct Circle : public Object{
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

  float getIntersectRotation(const Vec2 point) const override{
    float dist = sqrt(
      power2(pos.x-point.x)+power2(pos.y-point.y)
    );

    float diff = sqrt(power2(dist)+power2(radius));

    float numerator = power2(dist) + power2(radius) - power2(diff);

    float th = numerator/(2*dist*radius);

    return th;
  }
};

struct Square : public Object{
  Vec2 width;
  float degPerSide = 90;

  Square(){
    Square(0., 0., 0., 0.);
  }

  Square(float x, float y, float hx, float hy){
    pos = {x, y};
    width = {hx, hy};
  }

  float signedDistance(const Vec2& point) const override{
    //float d = (Vec2){(float)std::fmax(point.x - width.x, 0.), (float)std::fmax(point.y - width.y, 0.)}.length();
    //std::cout << point.x - width.x << std::endl;

    Vec2 x = pos - point;

    Vec2 d = abs(x)-width;

    float f = (Vec2){(max(d,(Vec2){0., 0.})) + toVec2(std::fmin(std::max(d.x,d.y), 0.))}.length();

    //std::cout << f << std::endl;

    return f;
  }

  void draw(const int screenWidth, const int screenHeight) const override{
    Vec2 screenPosition = {pos.x+(screenWidth/2), pos.y+(screenHeight/2)};
    screenPosition = screenPosition - width;

    DrawRectangleV(screenPosition.expose(), (width * toVec2(2)).expose(), GREEN);
  }

};
