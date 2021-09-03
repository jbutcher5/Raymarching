#pragma once
#include "display.hpp"
#include "object.hpp"
#include <raylib.h>


Display::Display(
    int screenWidth,
    int screenHeight,
    const char * title,
    int targetFPS
){
  InitWindow(screenWidth, screenHeight, title);
  SetTargetFPS(targetFPS);

  this->screenWidth = screenWidth;
  this->screenHeight = screenHeight;
}


void Display::attachShape(Object* shape){
  shapes.push_back(shape);
}

void Display::drawShape(){
  for (auto i : shapes)
    i->draw(
      this->screenWidth,
      this->screenHeight
    );
}

void Display::closeScreen(){
  CloseWindow();
}
