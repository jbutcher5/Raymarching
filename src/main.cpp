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
  x.radius = 25;
  x.pos.set(100., 20.);

  InitWindow(screenWidth, screenHeight, screenTitle);

  SetTargetFPS(60);

  while (!WindowShouldClose()){
    if (IsKeyDown(KEY_RIGHT)) point.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) point.x -= 2.0f;
    if (IsKeyDown(KEY_UP)) point.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) point.y += 2.0f;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircleV(WtoS(point.expose()), 2, RED);
    DrawCircleV(WtoS(x.pos.expose()), x.radius, GREEN);
    DrawCircleV(WtoS(point.expose()), x.signedDistance(point), (Color){20, 20, 200, 50});
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
