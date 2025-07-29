CC = gcc
CFLAGS = -Wall -O2
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = tetris

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) src/*.o