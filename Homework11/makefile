CC = g++
CFLAGS = -Wall

all: program1, program2, program3

program1: los.o
	$(CC) $(CFLAGS) -o problem1 los.o

los.o: los.cpp
	$(CC) -c los.cpp

program2: sumintri.o
	$(CC) $(CFLAGS) -o problem2 sumintri.o

sumintri.o: sumintri.cpp
	$(CC) -c reverse_stack.cpp

program3: scuba.o
	$(CC) $(CFLAGS) -o problem3 scuba.o

scuba.o: scuba.cpp
	$(CC) -c scuba.cpp

clean:
	rm -f *.*