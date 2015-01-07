CC=gcc
OPTIONS=-g -Wall
TARGET=main

all: *.c
	$(CC) *.c -o $(TARGET) $(OPTIONS)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)

