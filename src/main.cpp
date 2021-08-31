#include <raylib.h>
#include <iostream>
#include "models.hpp"

#define LOG(x) std::cout << x << std::endl
#define screenWidth 800
#define screenHeight 450
#define screenTitle "[Example] Ray Marching"

Vector2 WtoS(Vector2 position){
  // Convert world space to screen space
  return (Vector2){
    position.x+(screenWidth/2),
    position.y+(screenHeight/2)
  };
}

float WtoS(float pos, bool isWidth=false){
  float sub = screenHeight/2;

  if (isWidth)
    sub = screenWidth/2;

  return pos+sub;
}

int main(){
  Vec2 point;
  point.set(0., 1.);

  Circle x;
  x.radius = 50;
  x.pos.set(5., 0.);

  InitWindow(screenWidth, screenHeight, screenTitle);

  SetTargetFPS(60);

  while (!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircle(WtoS(point.x, true), WtoS(point.y), 2, RED);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
