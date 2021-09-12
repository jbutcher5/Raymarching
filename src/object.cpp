#pragma once
#include "vec2.hpp"
#include "object.hpp"
#include <cmath>
#include <algorithm>
#include <raylib.h>
#include <iostream>

#define LOG(x) std::cout << x << std::endl
#define toVec2(x) (Vec2){x, x}
#define radMul 180/PI

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

Circle::Circle(){
  Circle(0., 0., 0.);
}

Circle::Circle(float rad, float x, float y){
  this->radius = rad;
  this->pos.set(x, y);
}

float Circle::signedDistance(const Vec2& point) const{
  return sqrt(
    power2(pos.x-point.x)+power2(pos.y-point.y)
  ) - radius;
}

void Circle::draw(const int screenWidth, const int screenHeight) const{
  Vector2 screenPosition = {pos.x+(screenWidth/2), pos.y+(screenHeight/2)};

  DrawCircleV(screenPosition, this->radius, GREEN);
}

float Circle::getIntersectRotation(const Vec2 point) const{
  Vec2 p1 = abs(pos);
  Vec2 p2 = abs(point);

  float c = (p1-p2).length();

  float b = radius;

  float a = (point-(pos+(Vec2){0, b})).length();

  float numerator = power2(b) + power2(c) - power2(a);

  float th = abs(acos(numerator/(2*b*c))*radMul);

  return th;
}

TraceCircle::TraceCircle(){
  TraceCircle(0., 0., 0., 0.);
}

TraceCircle::TraceCircle(float rad, float x, float y, float th){
  this->radius = rad;
  this->pos.set(x, y);
  this->th = th;
}


Square::Square(){
  Square(0., 0., 0., 0.);
}

Square::Square(float x, float y, float hx, float hy){
  pos = {x, y};
  width = {hx, hy};
}

float Square::signedDistance(const Vec2& point) const{
  Vec2 x = pos - point;

  Vec2 d = abs(x)-width;

  float f = (Vec2){(max(d,(Vec2){0., 0.})) + toVec2(std::fmin(std::max(d.x,d.y), 0.))}.length();

  return f;
}

void Square::draw(const int screenWidth, const int screenHeight) const{
  Vec2 screenPosition = {pos.x+(screenWidth/2), pos.y+(screenHeight/2)};
  screenPosition = screenPosition - width;

  DrawRectangleV(screenPosition.expose(), (width * toVec2(2)).expose(), GREEN);
}

float Square::getIntersectRotation(const Vec2 point) const{
  Vec2 p1 = abs(pos);
  Vec2 p2 = abs(point);

  float c = (p1-p2).length();

  float b = width.y;

  float a = (point-(pos+(Vec2){0, b})).length();

  float numerator = power2(b) + power2(c) - power2(a);

  float th = abs(acos(numerator/(2*b*c))*radMul);

  float result;
  size_t coveredSides = 0;

  if (th > 45)
    coveredSides++;

  if (th > 135)
    coveredSides++;

  if (th > 225)
    coveredSides++;

  if (th > 315)
    coveredSides++;

  result = degPerSide * coveredSides;

  return result;
}
