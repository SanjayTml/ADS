/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h1_p2
*/

#include <cassert>
#include <iostream>

using namespace std;

/* 
This is a generic stack. Its type T is generic and its initial 
size defaults to 10.
*/
template<class T>
class Stack 
{
	T *ptr;			// data will be stored in an array
	int size;		// number of elements in the array
	int where;  	// last non-free position
	void extend();  // used to expand the vector when it is full
public:
	Stack();
    Stack(const Stack&);
	~Stack();
    Stack(int size);
	bool push(T element);	// inserts an element
	bool pop(T& out);			// returns and extracts an element
    T back(void);
    int getNumEntries();
};

template<class T>
Stack<T>::Stack()
{
	T narray[10];	// creates a vector of the default size
    ptr = narray;
	size = 10;
	where = -1;					// no elements up to now
}

template<class T>
Stack<T>::Stack(int nsize)
{
	T narray[nsize];	// creates a vector of the custom size
    ptr = narray;
	size = nsize;
	where = -1;					// no elements up to now
}

template<class T>
Stack<T>::~Stack()
{
	delete[] ptr;			// deallocate memory
} 

template<class T>
bool Stack<T>::push(T element)
{
	if (where + 1 == size)	// no room?  
		extend();			// expand the vector
	where++;				// and insert the element 
	ptr[where] = element;
    return true;
}

template<class T>
void Stack<T>::extend()
{
	T *newptr = new T[2 * size];	// creates a new vector with double size
	for (int i = 0; i < size; i++)	// copy the old elements
		newptr[i] = ptr[i];
	delete[] ptr;	// release old memory
	ptr = newptr;	// adjust pointers
	size *= 2;		// store the new size
}

template<class T>
bool Stack<T>::pop(T& out)
{
	if(where < 0)  // non pops if no elements are present
        return false;
	out = ptr[where--];  // return the element and update the free position
    return true;
}

template<typename T>
T Stack<T>::back()
{   
    if(where < 0){
        exit(1);
    }
    return ptr[0];  //returns the element inserted at first position
}

template<typename T>
int Stack<T>::getNumEntries()
{
    return where++;     //returns number of elements
}
