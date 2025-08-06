#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shape.h"

int shape_L[5][2] = {
    {0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}};
int shape_T[5][2] = {
    {0, 1}, {1, 0}, {1, 1}, {1, 2}, {2, 1}};
int shape_S[5][2] = {
    {1, 0}, {2, 0}, {0, 1}, {1, 1}, {1, 2}};
int shape_Z[5][2] = {
    {0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}};
int shape_I[5][2] = {
    {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}};
int shape_O[5][2] = {
    {0, 0}, {1, 0}, {0, 1}, {1, 1}, {2, 2}};
int shape_J[5][2] = {
    {0, 0}, {0, 1}, {1, 1}, {2, 1}, {2, 2}};

int shape_set_points(Shape *shape, enum ShapeType type)
{
  switch (type)
  {
  case SHAPE_L:
    memcpy(shape->points, shape_L, sizeof(shape_L));
    break;
  case SHAPE_T:
    memcpy(shape->points, shape_T, sizeof(shape_T));
    break;
  case SHAPE_S:
    memcpy(shape->points, shape_S, sizeof(shape_S));
    break;
  case SHAPE_Z:
    memcpy(shape->points, shape_Z, sizeof(shape_Z));
    break;
  case SHAPE_I:
    memcpy(shape->points, shape_I, sizeof(shape_I));
    break;
  case SHAPE_O:
    memcpy(shape->points, shape_O, sizeof(shape_O));
    break;
  case SHAPE_J:
    memcpy(shape->points, shape_J, sizeof(shape_J));
    break;
  }
  return 0;
}

int shape_create(
    Shape **shape,
    enum ShapeType type,
    enum ShapeRotation rotation)
{
  *shape = malloc(sizeof(Shape));
  (*shape)->type = type;
  (*shape)->rotation = rotation;
  shape_set_points(*shape, type);
  return 0;
}

int shape_destroy(Shape *shape)
{
  return 0;
};

int shape_rotate(Shape *shape)
{
  return 0;
}