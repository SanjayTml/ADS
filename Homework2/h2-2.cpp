/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p2
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int size=0;
    float input;
    //creating deque of float
	deque<int> A;
    cin >> input;

    //loop to get input until end
	while(input!=0) {
		if(input>0){
            A.push_back(input);
        }
        else
        {
            A.push_front(input);
        }
        size++;
		cin >> input;
	}

    cout << "Initially: " << endl;
    //printing with spaces
    for(auto i:A){
        cout << i << " ";
    }
    cout << endl;

    for(auto iter=A.begin(); iter!=A.end(); iter++){
        if(*iter>0){
            A.insert(iter, 0);
            break;
        }
    }
    cout << endl;

    //declaring deque iterator
	deque<int>::iterator iter = A.begin();

    cout << "After adding 0 " << endl;

    //printing with commas
  	while (iter != --A.end()) {
		cout << *iter << ";" ;
		iter++;
	}
    cout << *iter;
	cout << endl;
  
    return 0;
}