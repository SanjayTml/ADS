/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p6
*/

#include<iostream>
#include "Access.h"
#include <set>

using namespace std;

int main(){
    unsigned int code;
    Access maindoor;
    //actiating codes
    maindoor.activate(1234);
    maindoor.activate(9999);
    maindoor.activate(9876);
    cin >> code;
    //loop to check the input code
    while(!maindoor.isactive(code)){
        cout << "Access Denied! " << endl;
        cin >> code;
    }
    cout << "Access Granted " << endl;
    //deactivating code
    maindoor.deactivate(code);
    maindoor.deactivate(9999);
    maindoor.activate(1111);
    cin >> code;
    while(!maindoor.isactive(code)){
        cout << "Access Denied! " << endl;
        cin >> code;
    }
    cout << "Access Granted " << endl;
    return 0;
}