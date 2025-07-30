#include <stdio.h>
#include <stdlib.h>

#include "canvas.h"

// int clear_screen() {
//   system("clear");
//   return 0;
// }

// int draw_shape() {
//   printf("Drawing shape...\n");
//   // Placeholder for drawing logic
//   return 0;
// }

// int init_canvas(int width, int height, int border_width) {
//   printf("-----start----- \n");
//   width += 2 * border_width;
//   height += 2 * border_width;
//   for (int i = 0; i < height; i++) {
//     for (int j = 0; j < width; j++) {
//       if (i < border_width || i >= height - border_width ||
//           j < border_width || j >= width - border_width)
//         printf("#");
//       else
//         printf(" ");
//     }
//     printf("\n");
//   }
//   printf("-----end----- \n");
//   return 0;
// }

int main () {
  Canvas* canvas = NULL;
  canvas_create(&canvas);
  canvas_init(canvas, 20, 10, 1);
  canvas_destroy(&canvas);
  canvas_clear(canvas);
  Point points[] = {{1, 1}, {2, 2}, {3, 3}};
  canvas_draw_points(canvas, points, sizeof(points) / sizeof(points[0]));
  return 0;
}