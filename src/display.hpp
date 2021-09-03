#pragma once
#include "object.hpp"
#include <vector>
#include <raylib.h>


class Display{
private:
  std::vector<Object*> shapes;
  int screenWidth, screenHeight;

  Vector2 WtoS(Vector2);

public:

  Display(int, int, const char*, int);
  void attachShape(Object*);
  void drawShape();
  void closeScreen();
};
