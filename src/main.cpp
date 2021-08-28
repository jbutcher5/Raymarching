#include <raylib.h>
#include <models.hpp>

int main(){
  Line a;
  a.x = {0, 1};
  a.y = {0, -1};

  Line b;
  b.x = {-1, 0};
  b.y = {1, 0};

  Vector2 c = a.intersection(b);

  return 0;
}
