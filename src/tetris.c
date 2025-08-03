#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "tetris.h"

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  Canvas* canvas = NULL;
  canvas_create(&canvas);
  canvas_init(canvas, 20, 10, 1);
  // Point points[] = shape_L;
  int n = 1;
  while(1) {
    usleep(100000);

    canvas_add_points(canvas, shapes[n%7], 4);

    canvas_draw(canvas);

    canvas_remove_ponits(canvas, shapes[n%7], 4);

    n ++;
  }
  return 0;
}