CC=gcc
OPTIONS=-g -Wall
TARGET=main

MEMCHECKPRGRAM=valgrind 
MEMCHECKPARAMETERS=--tool=memcheck 

all: *.c
	$(CC) *.c -o $(TARGET) $(OPTIONS)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)

mem:
	$(MEMCHECKPRGRAM) $(MEMCHECKPARAMETERS) ./$(TARGET) $(TESTARGUMENTS)
