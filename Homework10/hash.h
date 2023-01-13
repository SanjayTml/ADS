#include <iostream>

class Node
{
  public:
	int key;
	int value;

	// Constructors
	Node(){};
	Node(int key, int value);
	~Node(){};
};

class HashTable
{
  private:
	Node **arr;
	int maxSize = 37; // Define m to be prime
	int currentSize = 0;

  public:
	int hashFunc(int key);
	int hashCode(int key);
	void insertNode(int key, int value);
	int get(int key);
	bool isEmpty();

	// Constructors & Destructors
	HashTable();
	~HashTable();
};

