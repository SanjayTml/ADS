#include <iostream>
#include <iomanip>
using namespace std;

#define NARRAY 8  /* array size */
#define NBUCKET 5 /* bucket size */
#define INTERVAL 10 /* bucket range */

struct Node 
{ 
	float data;  
	struct Node *next; 
};

void BucketSort(float arr[]);
struct Node *InsertionSort(struct Node *list);
void print(float arr[]);
int getBucketIndex(float value);

void BucketSort(float arr[])
{	
	int i,j;
	struct Node **buckets;  

	/* allocate memory for array of pointers to the buckets */
	buckets = (struct Node **)malloc(sizeof(struct Node*) * NBUCKET); 

	/* initialize pointers to the buckets */
	for(i = 0; i < NBUCKET;++i) {  
		buckets[i] = NULL;
	}

	/* put items into the buckets */
	for(i = 0; i < NARRAY; ++i) {	
		struct Node *current;
		int pos = getBucketIndex(arr[i]);
		current = (struct Node *) malloc(sizeof(struct Node));
		current->data = arr[i]; 
		current->next = buckets[pos];  
		buckets[pos] = current;
	}
	
	/* sorting bucket using Insertion Sort */
	for(i = 0; i < NBUCKET; ++i) {  
		buckets[i] = InsertionSort(buckets[i]); 
	}

	/* put items back to original array */
	for(j =0, i = 0; i < NBUCKET; ++i) {	
		struct Node *node;
		node = buckets[i];
		while(node) {
			arr[j++] = node->data;
			node = node->next;
		}
	}
	
	/* free memory */
	for(i = 0; i < NBUCKET;++i) {	
		struct Node *node;
		node = buckets[i];
		while(node) {
			struct Node *tmp;
			tmp = node; 
			node = node->next; 
			free(tmp);
		}
	}
	free(buckets); 
	return;
}

/* Insertion Sort */
struct Node *InsertionSort(struct Node *list)
{	
	struct Node *k,*nodeList;
	/* need at least two items to sort */
	if(list == 0 || list->next == 0) { 
		return list; 
	}
	
	nodeList = list; 
	k = list->next; 
	nodeList->next = 0; /* 1st node is new list */
	while(k != 0) {	
		struct Node *ptr;
		/* check if insert before first */
		if(nodeList->data > k->data)  { 
			struct Node *tmp;
			tmp = k;  
			k = k->next; 
			tmp->next = nodeList;
			nodeList = tmp; 
			continue;
		}

		for(ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
			if(ptr->next->data > k->data) break;
		}

		if(ptr->next!=0){  
			struct Node *tmp;
			tmp = k;  
			k = k->next; 
			tmp->next = ptr->next;
			ptr->next = tmp; 
			continue;
		}
		else{
			ptr->next = k;  
			k = k->next;  
			ptr->next->next = 0; 
			continue;
		}
	}
	return nodeList;
}

int getBucketIndex(float value)
{
	return value/INTERVAL;
}

void print(float ar[])
{	
	int i;
	for(i = 0; i < NARRAY; ++i) { 
		cout << ar[i] << " "; 
	}
	cout << endl;
}

int main(void)
{	
	float array[NARRAY] = {0.9,0.1,0.6,0.7,0.6,0.3,0.1};

	cout << "Initial array" << endl;
	print(array);

	BucketSort(array); 
	cout << "<------------>" << endl;
	cout << "Sorted array"  << endl;
	print(array); 
	return 0;
}