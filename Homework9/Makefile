CC = g++
CFLAGS = -Wall

all: main

main: rbt.o testrbt.o
	$(CC) $(CFLAGS) -o main rbt.cpp testrbt.cpp

rbt.o: rbt.cpp
	$(CC) $(CFLAGS) -c rbt.cpp
	
testrbt.o: testrbt.cpp
	$(CC) $(CFLAGS) -c testrbt.cpp

clean:
	rm -f *.*