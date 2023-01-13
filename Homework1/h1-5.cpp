/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h1_p5
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

    //replacing 2nd and 5th element
    if(size>=5){
        string replacer;
        replacer = vwords[1];
        vwords[1] = vwords[4];
        vwords[4] = replacer;
    }
    else
    {
        cout << "The size of the vector is less than 5." << endl;
    }
    
    //replacing last element
    vwords[size-1] = "???";

    for(int i=0; i<(size-1); i++){
        cout << vwords[i] << ",";
    }
    cout << vwords[size-1];

    cout << endl;

    //declaring vector iterator
	vector<string>::iterator viter = vwords.begin();
  
  	while (viter != vwords.end()-1) {
		cout << *viter << ";" ;
		viter++;
	}
    cout << *viter;
  
	cout << endl;

    for(viter = vwords.end()-1; viter >= vwords.begin(); viter--){
        cout << *viter << " ";
    }

    cout << endl;
  
    return 0;
}