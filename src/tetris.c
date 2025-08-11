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

  int **pixels = NULL;
  int x_size = 0;
  int y_size = 0;
  canvas_get_pixels(canvas, pixels, &x_size, &y_size);
  printf("x1 = %d y1 = %d \n", x_size, y_size);

  for (int i = 0; i < y_size; i++)
  {
    printf("===== %d \n", x_size);
    for (int j = 0; j < x_size; j++)
    {
      printf("x=%d,y=%d \n", i, j);
    }
  }

  while (0)
  {
    usleep(100000);
    canvas_add_points(canvas, shape->points, 4);
    canvas_draw(canvas);
    canvas_remove_ponits(canvas, shape->points, 4);
  }
  return 0;
}