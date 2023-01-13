/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h1_p4
*/

#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int size=0;
    string words;

    //creating vector of strings
	vector<string> vwords;
    cin >> words;

    //loop to get input until end
	while(words!="END" && words!="end") {
		vwords.push_back(words);
        size++;
		cin >> words;
	}

    //printing with spaces
    for(int i=0; i<size; i++){
        cout << vwords[i] << " ";
    }

    cout << endl;

    //declaring vector iterator
	vector<string>::iterator viter = vwords.begin();
  
    //printing with commas
  	while (viter != vwords.end()-1) {
		cout << *viter << "," ;
		viter++;
	}
    cout << *viter;
  
	cout << endl;
  
    return 0;
}