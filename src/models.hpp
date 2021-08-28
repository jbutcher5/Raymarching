#pragma once
#include <raylib.h>

class Vec2{
public:
  Vector2 vec;
  bool vecIsInit = false;
};

class Line{
private:
  Vec2 x;
  Vec2 y;

public:
  Line(Vector2 _x, Vector2 _y){
    setX(_x);
    setY(_y);
  }

  Vector2 getX(){
    if (x.vecIsInit)
      return x.vec;
  }

  Vector2 getY(){
    if (y.vecIsInit)
      return y.vec;
  }

  void setX(Vector2 _x){
    x.vec = _x;
    x.vecIsInit = true;
  }

  void setY(Vector2 _x){
    x.vec = _x;
    x.vecIsInit = true;
  }

  Vector2 intersection(Line other){
    Vector2 result;
    Vector2 _x = {
      x.vec.x - y.vec.x,
      x.vec.y - y.vec.y
    };

    Vector2 _y = {
      other.getX().x - other.getY().x,
      other.getX().y - other.getY().y
    };

    result = {
      _x.x - _y.x,
      _x.y - _y.y
    };

    return result;
  }
};
