#include <raylib.h>
#include <iostream>
#include "models.hpp"
#include <cmath>
#include <vector>


#define LOG(x) std::cout << x << std::endl
#define screenWidth 800
#define screenHeight 450
#define screenTitle "[Example] Ray Marching"
#define screenFPS 60


Vector2 WtoS(Vector2 position){
  // Convert world space to screen space
  return (Vector2){
    position.x+(screenWidth/2),
    position.y+(screenHeight/2)
  };
}


int main(){
  Vec2 point = {0., 1.};

  std::vector<Circle> x;

  x.push_back((Circle){25., 80., 20.});
  x.push_back((Circle){25., 100., 100.});
  x.push_back((Circle){30., -20., 40.});

  float distance;

  Display screen(
    screenWidth,
    screenHeight,
    screenTitle,
    screenFPS
  );

  for (auto &i : x)
    screen.attachShape(&i);

  while (!WindowShouldClose()){
    if (IsKeyDown(KEY_RIGHT)) point.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) point.x -= 2.0f;
    if (IsKeyDown(KEY_UP)) point.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) point.y += 2.0f;

    distance = INFINITY;

    for (auto i : x)
      if (i.signedDistance(point) < distance)
        distance = i.signedDistance(point);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircleV(WtoS(point.expose()), 2, RED);
    DrawCircleV(WtoS(point.expose()), distance, (Color){20, 20, 200, 50});
    screen.drawShape();
    EndDrawing();

  }

  screen.closeScreen();

  return 0;
}
