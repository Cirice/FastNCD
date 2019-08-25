CC := g++
SCRDIR := src
FLAGS := -Wall
LINKLIBS := -lsnappy

all:
	$(CC)	-o main $(SCRDIR)/main.cpp $(SCRDIR)/ncd.cpp  $(FLAGS) $(LINKLIBS)

test:
	rm -f test
	$(CC)   -o test $(SCRDIR)/test_ncd.cpp $(SCRDIR)/ncd.cpp  $(FLAGS)
	chmod u+x ./test && ./test

clean:
	rm -f main test $(SCRDIR)/*.o
