CC=gcc
OPTIONS=-g -Wall
TARGET=main
DEFINE=-D DOUBLE_LINKED_LIST

DOC=doxygen
DOCCONFIG=doxygen.config

FORMATPROGRAM=astyle

MEMCHECKPRGRAM=valgrind 
MEMCHECKPARAMETERS=--tool=memcheck 

all: *.c
	$(CC) *.c -o $(TARGET) $(OPTIONS)

double: *.c
	$(CC) *.c $(DEFINE) -o $(TARGET) $(OPTIONS)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)

mem:
	$(MEMCHECKPRGRAM) $(MEMCHECKPARAMETERS) ./$(TARGET) $(TESTARGUMENTS)

doc:	*.c
	$(DOC) $(DOCCONFIG) $(TARGET)

doc-gen-config-file:
	$(DOC) -g $(DOCCONFIG)

format: *.c
	$(FORMATPROGRAM) $(TARGET)

doc-clean:
	rm -rf latex
	rm -rf html

help:
	@echo Targets
	@echo : doc 
	@echo : doc-gen-config-file 
	@echo : doc-clean 
	@echo : mem-check
	@echo : format 
	@echo : clean
	@echo : double
	@echo : all 
	@echo : run
