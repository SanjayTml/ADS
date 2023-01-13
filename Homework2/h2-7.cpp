/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p7
*/

#include<iostream>
#include<cstdlib>
#include<map>
#include<fstream>

using namespace std;

int main(){
    string names; 
    string input;
    int dob;
    ifstream filep;
    map<string,int> content;
    //opening input file
    filep.open("data.txt");
    if(!filep.is_open()){
        cout << "File open unsuccessful " << endl;
        return(0);
    }
    //getting data from file
    while(!filep.eof()){
        getline(filep,names);
        filep >> dob;
        //content.insert(content.begin(), pair<string,int>(names,dob));
        content[names]=dob;
    }
    
    cout << "Enter name: ";
    cin >> input;
    //checking input with the database
    if(content.find(input)!=content.end()){
        cout << content.find(input)->second << endl;
    }
    else
    {
        cout << "Name not found!" << endl;
    }
    filep.close();
    return 0; 
}