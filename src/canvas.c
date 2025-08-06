#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "canvas.h"

int canvas_create(Canvas **canvas)
{
  *canvas = malloc(sizeof(Canvas));
  if (*canvas == NULL)
  {
    return -1;
  }
  memset(*canvas, 0, sizeof(Canvas));
  // printf("canvas_create: %p\n", (void *)*canvas);
  return 0;
};

int canvas_destroy(Canvas **canvas)
{
  if (canvas == NULL || *canvas == NULL)
  {
    return 0;
  }
  free(*canvas);
  *canvas = NULL;
  // printf("canvas_destroy: %p\n", (void *)*canvas);
  return 0;
};

int canvas_draw(Canvas *canvas)
{
  int width = canvas->width;
  int height = canvas->height;
  int border_width = canvas->border_width;
  char buffer[4096]; // 足够大的缓冲区
  char *p = buffer;

  p += sprintf(p, "\033[2J\033[H"); // 清屏和移动光标

  p += sprintf(p, "\033[?25l"); // 隐藏光标
  for (int i = 0; i < height + 2 * border_width; i++)
  {
    for (int j = 0; j < width + 2 * border_width; j++)
    {
      if (canvas->pixels[i][j] == 1)
      {
        *p++ = '#'; // 将字符添加到缓冲区
      }
      else
      {
        *p++ = ' ';
      }
    }
    *p++ = '\n'; // 添加换行符到缓冲区
  }
  *p = '\0';
  size_t len = p - buffer;
  write(STDOUT_FILENO, buffer, len);
  return 0;
};

int canvas_init(Canvas *canvas, int width, int height, int border_width)
{
  canvas->width = width;
  canvas->height = height;
  canvas->border_width = border_width;
  for (int i = 0; i < height + 2 * border_width; i++)
  {
    for (int j = 0; j < width + 2 * border_width; j++)
    {
      if (i < border_width || i >= height + border_width ||
          j < border_width || j >= width + border_width)
        canvas->pixels[i][j] = 1;
      else
        canvas->pixels[i][j] = 0;
    }
  }
  // canvas_draw(canvas);
  return 0;
};

int canvas_clear(Canvas *canvas)
{
  int width = canvas->width + 2 * canvas->border_width;
  int height = canvas->height + 2 * canvas->border_width;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      canvas->pixels[i][j] = 0;
    }
  }
  canvas_draw(canvas);
  return 0;
};

int canvas_add_points(Canvas *canvas, int points[5][2], int num_points)
{
  for (int i = 0; i < num_points; i++)
  {
    int x = points[i][0] + canvas->border_width;
    int y = points[i][1] + canvas->border_width;
    canvas->pixels[x][y] = 1;
  }
  return 0;
};

int canvas_remove_ponits(Canvas *canvas, int points[5][2], int num_points)
{
  for (int i = 0; i < num_points; i++)
  {
    int x = points[i][0] + canvas->border_width;
    int y = points[i][1] + canvas->border_width;
    canvas->pixels[x][y] = 0;
  }
  return 0;
};