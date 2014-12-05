CC=gcc
OPTIONS=-g -Wall
TARGET=main

# all: *.c
# 	$(CC) main.c -o $(TARGET) $(OPTIONS)

# run:
# 	./$(TARGET)

# clean:
# 	rm -f $(TARGET)

all: test_student

prime_test: test_student.c student.c
	 gcc test_student.c -otest_student -lm
 
tests: test_student
	 ./test_student
