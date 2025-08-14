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

  int w_size = 0;
  int h_size = 0;
  canvas_get_pixels(canvas, NULL, &w_size, &h_size);
  printf("x1 = %d y1 = %d \n", w_size, h_size);

  int **pixels = NULL;
  pixels = (int **)malloc(h_size * sizeof(int *));
  for (int i = 0; i < h_size; i++)
  {
    pixels[i] = (int *)malloc(w_size * sizeof(int));
  }
  canvas_get_pixels(canvas, &pixels, &w_size, &h_size);

  for (int i = 0; i < h_size; i++)
  {
    for (int j = 0; j < w_size; j++)
    {
      printf("i=%d j=%d v=%d \n", i, j, pixels[i][j]);
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