CC := g++
SCRDIR := src
FLAGS := -Wall
LINKLIBS := -lsnappy -lboost_iostreams

all:
	$(CC)	-o examples $(SCRDIR)/examples.cpp $(SCRDIR)/ncd.cpp  $(FLAGS) $(LINKLIBS)

test:
	rm -f test
	$(CC)   -o test $(SCRDIR)/test_ncd.cpp $(SCRDIR)/ncd.cpp  $(FLAGS)
	chmod u+x ./test && ./test

clean:
	rm -f main  examples test $(SCRDIR)/*.o
