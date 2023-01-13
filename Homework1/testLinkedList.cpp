/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h1_p3
*/

#include<iostream>
#include "LinkedList.h"

using namespace std;

int main(){
    //creating a linked list of integers
    Linked_list<int> mylist;

    //storing values in the linked list
    for(int i=0;i<8;i++){
        mylist.push_front(i);
    }
    mylist.push_back(999);

    //displaying results with methods
    cout << "Total elements in the list: " << mylist.getSize() << endl;

    cout << "First = " << mylist.getFirst() << endl;
    cout << "Last = " << mylist.getLast() << endl;
    
    cout << "Removing two elements.. " << endl;
    cout << "From last :" << mylist.pop_back() << endl;
    cout << "From first :" << mylist.pop_front() << endl;

    cout << "Number of elements in the list: " << mylist.getSize() << endl;
    return 0;
}