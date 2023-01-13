#include<iostream>
#include<exception>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

const int beginval = 10;
const int endval = 20000;
const int range = 500;
const int steps = 600;

/*class heap{
    public: 
        int capacity;
        int size = 0;
        int* items;
    
    public:
        heap(int num,int* arr){ capacity=num; size=num; items = arr;}
        int getLeftChildIndex(int parentIndex){return 2*parentIndex +1;}
        int getRightChildIndex(int parentIndex){return 2*parentIndex +2;}
        int getParentIndex(int childIndex){return (childIndex-1)/2;}

        bool hasLeftChild(int index){ return getLeftChildIndex(index)<size;}
        bool hasRightChild(int index){ return getRightChildIndex(index)<size;}
        bool hasParent(int index){return getParentIndex(index) >=0;}

        int leftChild(int index){return items[getLeftChildIndex(index)];}
        int rightChild(int index){return items[getRightChildIndex(index)];}
        int parent(int index){return items[getParentIndex(index)];}

        void swap(int indexOne, int indexTwo){
            int hold = items[indexOne];
            items[indexOne] = items[indexTwo];
            items[indexTwo] = hold;
        }

        void checkCapacity() {
            if(size == capacity) {
                int *newitems = new int[capacity*2];
                copy(items,items+min(capacity, capacity*2),newitems);
                delete[] items;
                items = newitems;
                capacity *= 2;
            }
        }

        int peek(){
            if (size==0) return 0;
            return items[0];
        }

        int poll(){
            if (size==0) return 0;
            int nitem = items[0];
            items[0] = items[size -1];
            size--;
            heapifyDown();
            return nitem;
        }

        void add(int nitem){
            items[size] = nitem;
            size++;
            heapifyUp();
        }

        void heapifyUp(){
            int index = size-1;
            while (hasParent(index) && parent(index) < items[index]){
                swap(getParentIndex(index), index);
                index = getParentIndex(index);
            }
        }

        void heapifyDown(){
            int index = 0;
            while (hasLeftChild(index)){
                int biggerChildIndex = getLeftChildIndex(index);
                if (hasRightChild(index) && rightChild(index) > leftChild(index))
                {
                    biggerChildIndex =  getRightChildIndex(index);
                }
                if (items[index] > items[biggerChildIndex])
                {
                    break;
                }
                else
                {
                    swap(index, biggerChildIndex);
                }
                index = biggerChildIndex;
            }
        }
};*/

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

int main(){
    double timetaken;
    ofstream filep;
    filep.open("data.txt");
    for (int n = beginval; n < endval; n+=steps)
    {
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % range + 1;
            cout << arr[i] << ", ";
        }
        cout << endl;

        timetaken = 0;
        auto startTime = chrono::system_clock::now();
        heapSort(arr, n);
        auto endTime = chrono::system_clock::now();
        chrono::duration<double> diff = endTime - startTime;
        timetaken += diff.count();

        filep << n << " " << timetaken << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ", ";
        }
        delete[] arr;
    }
    
    filep.close();
    return 0;
}