OBJS=main.o graph.o
CXX=g++
CXXLAGS=-Wall -std=c++11
LFLAGS=

program: $(OBJS) graph.h main.cpp
	$(CXX) $(OBJS) -o program

main.o: main.cpp
	$(CXX) -c $(CXXLAGS) main.cpp -o main.o

graph.o: graph.h
	$(CXX) -c $(CXXLAGS) graph.cpp

clean:
	rm -f *.o
.PHONY: clean