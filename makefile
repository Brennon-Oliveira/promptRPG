INIT_FILE=main.cpp

PROJECT_NAME=promptRPG

INCLUDES=./**/*.cpp

COMPILER=g++

LIBS=-lncurses

all: 
	$(COMPILER) -o $(PROJECT_NAME).o -Iinclude $(INCLUDES) $(INIT_FILE) $(LIBS)
	./$(PROJECT_NAME).o