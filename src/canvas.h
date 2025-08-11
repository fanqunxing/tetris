// #ifndef CANVAS_H
// #define CANVAS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int x;
  int y;
} Point;

typedef struct
{
  int width;
  int height;
  int border_width;
  int **pixels;
} Canvas;

int canvas_create(Canvas **canvas);
int canvas_destroy(Canvas **canvas);
int canvas_init(Canvas *canvas, int width, int height, int border_width);
int canvas_clear(Canvas *canvas);
int canvas_add_points(Canvas *canvas, int points[5][2], int num_points);
int canvas_remove_ponits(Canvas *canvas, int points[5][2], int num_points);
int canvas_get_pixels(Canvas *canvas, int **pixels, int *x_size, int *y_size);
int canvas_draw(Canvas *canvas);