#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "canvas.h"

int canvas_create(Canvas** canvas) {
  *canvas = malloc(sizeof(Canvas));
  if (*canvas == NULL) {
    return -1;
  }
  memset(*canvas, 0, sizeof(Canvas));
  printf("canvas_create: %p\n", (void *)*canvas);
  return 0;
};

int canvas_destroy(Canvas** canvas) {
  if (canvas == NULL || *canvas == NULL) {
    return 0;
  }
  free(*canvas);
  *canvas = NULL;
  printf("canvas_destroy: %p\n", (void *)*canvas);
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