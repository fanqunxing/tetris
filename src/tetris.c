#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "tetris.h"

int main()
{
  setvbuf(stdout, NULL, _IONBF, 0);
  Canvas *canvas = NULL;
  canvas_create(&canvas);
  canvas_init(canvas, 20, 10, 1);
  Shape *shape = NULL;
  shape_create(&shape, SHAPE_J, ROTATION_0);
  while (1)
  {
    usleep(100000);
    canvas_add_points(canvas, shape->points, 4);
    canvas_draw(canvas);
    canvas_remove_ponits(canvas, shape->points, 4);
  }
  return 0;
}