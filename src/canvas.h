// #ifndef CANVAS_H
// #define CANVAS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  int width;
  int height;
  int border_width;
  Point* points;
} Canvas;

int canvas_create(Canvas** canvas);
int canvas_destroy(Canvas** canvas);
int canvas_init(Canvas* canvas, int width, int height, int border_width);
int canvas_clear(Canvas* canvas);
int canvas_draw_points(Canvas* canvas, Point* points, int num_points);