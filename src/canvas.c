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

int canvas_draw(Canvas* canvas) {
  int width = canvas->width;
  int height = canvas->height;
  int border_width = canvas->border_width;
  for (int i = 0; i < height + 2 * border_width; i++) {
    for (int j = 0; j < width + 2 * border_width; j++) {
      if (canvas->pixels[i][j] == 1) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
};

int canvas_init(Canvas* canvas, int width, int height, int border_width) {
  printf("Address of canvas: %p\n", (void *)canvas);
  canvas->width = width;
  canvas->height = height;
  canvas->border_width = border_width;
  for (int i = 0; i < height + 2 * border_width; i++) {
    for (int j = 0; j < width + 2 * border_width; j++) {
      if (i < border_width || i >= height + border_width ||
        j < border_width || j >= width + border_width)
        canvas->pixels[i][j] = 1;
      else
        canvas->pixels[i][j] = 0;
    }
  }
  canvas_draw(canvas);
  return 0;
};

int canvas_clear(Canvas* canvas){
  printf("Clearing canvas...\n");
  int width = canvas->width + 2 * canvas->border_width;
  int height = canvas->height + 2 * canvas->border_width;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      canvas->pixels[i][j] = 0;
    }
  }
  canvas_draw(canvas);
  return 0;
};

int canvas_add_points(Canvas* canvas, Point* points, int num_points) {
  printf("canvas_draw_points: %p\n", (void *)canvas);
  for (int i = 0; i < num_points; i++) {
    int x = points[i].x + canvas->border_width;
    int y = points[i].y + canvas->border_width;
    canvas->pixels[x][y] = 1;
    printf("Drawing point at (%d, %d)\n", points[i].x, points[i].y);
  }
  canvas_draw(canvas);
  return 0;
};