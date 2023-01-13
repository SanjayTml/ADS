CC = g++
CFLAGS = -Wall

all: program1, program2, program3, program4

program1: stack.o
	$(CC) $(CFLAGS) -o problem1 stack.o

stack.o: stack.cpp
	$(CC) -c stack.cpp

program2: reverse_stack.o
	$(CC) $(CFLAGS) -o problem2 reverse_stack.o

reverse_stack.o: reverse_stack.cpp
	$(CC) -c reverse_stack.cpp

program3: bst_to_ll.o
	$(CC) $(CFLAGS) -o problem3 bst_to_ll.o

bst_to_ll.o: bst_to_ll.cpp
	$(CC) -c bst_to_ll.cpp

program4: ll_to_bst.o
	$(CC) $(CFLAGS) -o problem4 ll_to_bst.o

ll_to_bst.o: ll_to_bst.cpp
	$(CC) -c ll_to_bst.cpp

clean:
	rm -f *.*