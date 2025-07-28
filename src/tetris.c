#include <stdio.h>
#include <stdlib.h>

int clear_screen() {
  return system("clear");
}

int init_canvas(int width, int height, int border_width) {
  printf("-----start----- \n");
  width += 2 * border_width;
  height += 2 * border_width;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (i < border_width || i >= height - border_width ||
          j < border_width || j >= width - border_width)
        printf("#");
      else
        printf(" ");
    }
    printf("\n");
  }
  printf("-----end----- \n");
  return 0;
}

int main () {
  printf("Tetris game starting...\n");
  clear_screen();
  init_canvas(20, 20, 1);
  while(1) {

  }
}