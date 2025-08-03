#include <stdio.h>
#include <stdlib.h>

#include "canvas.h"

Point shape_L[] = {
  {0, 0}, {1, 0}, {2, 0},
  {2, 1}, {2, 2}
}; 
Point shape_T[] = {
  {0, 1}, {1, 0}, {1, 1},
  {1, 2}, {2, 1}
};
Point shape_S[] = {
  {1, 0}, {2, 0}, {0, 1},
  {1, 1}, {1, 2}
};
Point shape_Z[] = {
  {0, 0}, {1, 0}, {1, 1},
  {2, 1}, {2, 2}
};
Point shape_I[] = {
  {0, 0}, {0, 1}, {0, 2},
  {0, 3}, {0, 4}
};
Point shape_O[] = {
  {0, 0}, {1, 0}, {0, 1},
  {1, 1}, {2, 2}
};
Point shape_J[] = {
  {0, 0}, {0, 1}, {1, 1},
  {2, 1}, {2, 2}
};

Point* shapes[] = {
  shape_L, shape_T, shape_S, shape_Z, shape_I, shape_O, shape_J
};