SHELL := bash
CC := g++
AR := ar
AR_FLAGS := rvs
SCRDIR := src
FLAGS := -Wall
LINKLIBS := -lsnappy -lz
NCD_LIB := -L ./ -lfastncd



all:
	$(CC) -o main $(SCRDIR)/main.cpp $(SCRDIR)/ncd.cpp  $(SCRDIR)/utils.cpp  $(FLAGS) $(LINKLIBS)


all2:
	$(CC) -o main $(SCRDIR)/main.cpp $(NCD_LIB) $(FLAGS) $(LINKLIBS)


test:
	rm -f test
	$(CC)   -o test $(SCRDIR)/test_ncd.cpp $(SCRDIR)/ncd.cpp  $(FLAGS)
	chmod u+x ./test && ./test


clean:
	rm -f main test $(SCRDIR)/*.o



lib:
	$(CC) -o $(SCRDIR)/ncd.o -c $(SCRDIR)/ncd.cpp
	$(AR) $(AR_FLAGS) fastncd.a $(SCRDIR)/ncd.o


.PHONY:	all
