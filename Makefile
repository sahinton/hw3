CXX = g++
CXXFLAGS = -g -Wall --std=c++11
VALGRIND = valgrind --tool=memcheck --leak-check=yes
DEFS=-DDEBUG

OBJS=llrec-test.o llrec.o stack_test.o

all: llrec-test

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)


#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp
llrec.o: llrec.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp
stack_test.o: stack_test.cpp stack.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c stack_test.cpp
	

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 