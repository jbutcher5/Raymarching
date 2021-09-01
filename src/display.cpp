#pragma once
#include "display.hpp"
#include "circle.hpp""
#include <raylib.h>



Display::Display(
    int screenWidth,
    int screenHeight,
    const char * title,
    int targetFPS
){
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(targetFPS);
}

Vector2 Display::WtoS(Vector2 position){
  // Convert world space to screen space
  return (Vector2){
    position.x+(screenWidth/2),
    position.y+(screenHeight/2)
  };
}

void Display::attachShape(Circle* shape){
    shapes.push_back(shape);
}

void Display::drawShape(){
    BeginDrawing();
    for (auto i : shapes)
        DrawCircleV(WtoS(i->pos), i->radius, GREEN);
    EndDrawing();
}

void Display::closeScreen(){
    CloseWindow();
}
