#include <stdio.h>
#include <stdlib.h>

#include "canvas.h"

int canvas_create(Canvas** canvas) {
  printf("Creating canvas...\n");
  printf("Address of canvas: %p\n", (void *)*canvas);
  Canvas new_canvas = {0, 0, 0};
  *canvas = &new_canvas;
  printf("Creating canvas...\n");
  printf("Address of canvas: %p\n", (void *)*canvas);
  return 0;
};

int canvas_destroy(Canvas* canvas) {
  printf("Destroying canvas...\n");
  printf("Address of canvas: %p\n", (void *)canvas);
  return 0;
};

int canvas_init(const Canvas* canvas, int width, int height, int border_width) {
  printf("-----canvas_init----- \n");
  printf("Address of canvas: %p\n", (void *)canvas);
  return 0;
};

int canvas_clear(const Canvas* canvas){
  printf("Clearing canvas...\n");
  printf("Address of canvas: %p\n", (void *)canvas);
  return 0;
};

int canvas_draw_points(const Canvas* canvas, Point* points, int num_points) {
  printf("Drawing points on canvas...\n");
  printf("Address of canvas: %p\n", (void *)canvas);
  return 0;
};