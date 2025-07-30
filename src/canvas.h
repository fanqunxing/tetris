// #ifndef CANVAS_H
// #define CANVAS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int width;
  int height;
  int border_width;
} Canvas;

typedef struct {
  int x;
  int y;
} Point;

int canvas_create(Canvas** canvas);
int canvas_destroy(Canvas** canvas);
int canvas_init(const Canvas* canvas, int width, int height, int border_width);
int canvas_clear(const Canvas* canvas);
int canvas_draw_points(const Canvas* canvas, Point* points, int num_points);