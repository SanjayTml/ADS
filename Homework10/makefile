CC = g++
CFLAGS = -Wall

all: main

main: testhash.o hash.o
	$(CC) $(CFLAGS) -o main hash.cpp testhash.cpp

hash.o: hash.cpp
	$(CC) $(CFLAGS) -c hash.cpp

testhash.o: testhash.cpp
	$(CC) $(CFLAGS) -c testhash.cpp

clean:
	rm -f *.*