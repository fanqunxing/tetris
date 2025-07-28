CC = gcc
CFLAGS = -Wall -O2

tetris: src/tetris.c
	$(CC) $(CFLAGS) src/tetris.c -o tetris

clean:
	rm -f tetris
