/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p1
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    int size=0;
    int input;
    ofstream ofile;
    //creating lists of int
	list<int> A, B;
    cin >> input;

    //loop to get input until end
	while(input>0) {
		A.push_back(input);
        B.push_front(input);
        size++;
		cin >> input;
	}

    cout << "Initially: " << endl;
    //printing with spaces
    for(int i:A){
        cout << i << " ";
    }

    cout << endl;

    ofile.open("listB.txt");
    if(ofile.is_open()){
        for(int i:B){
            ofile << i << " ";
        }
        cout << "File written successfully!" << endl;
    }

    cout << endl;

    //moving first element to last
    int holder = A.front();
    A.pop_front();
    A.push_back(holder);
    holder = B.front();
    B.pop_front();
    B.push_back(holder);

    //declaring list iterator
	list<int>::iterator literA = A.begin();

    cout << "After moving element " << endl;

    //printing with commas
  	while (literA != --A.end()) {
		cout << *literA << "," ;
		literA++;
	}
    cout << *literA;
	cout << endl;

    auto literB = B.begin();
    while(literB != --B.end()) {
        cout << *literB << ",";
        literB++;
    }
    cout << *literB;
    cout << endl << endl;

    cout << "After merging: " << endl;

    //merging two lists
    A.merge(B);

    for(int n:A){
        cout << n << " ";
    }
    cout << endl;
  
    return 0;
}