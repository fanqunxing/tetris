#include <stdio.h>
#include <stdlib.h>

enum ShapeType
{
  SHAPE_L,
  SHAPE_T,
  SHAPE_S,
  SHAPE_Z,
  SHAPE_I,
  SHAPE_O,
  SHAPE_J
};

enum ShapeRotation
{
  ROTATION_0,
  ROTATION_90,
  ROTATION_180,
  ROTATION_270
};

typedef struct Shape
{
  enum ShapeType type;
  enum ShapeRotation rotation;
  int points[5][2];
} Shape;

int shape_create(Shape **shape, enum ShapeType type, enum ShapeRotation rotation);
int shape_destroy(Shape *shape);