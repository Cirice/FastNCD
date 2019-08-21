CC := g++
SCRDIR := src
FLAGS := -Wall

all:
	$(CC)	-o main $(SCRDIR)/main.cpp $(SCRDIR)/ncd.cpp  $(FLAGS)
