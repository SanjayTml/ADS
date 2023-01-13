/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p8
*/

#include<iostream>
#include<map>
#include "Access.h"

using namespace std;

int main(){
    Access building;
    unsigned int input;
    //activating codes and their levels
    building.activate(1234,1);
    building.activate(9999,5);
    building.activate(9867,9);

    cin >> input;
    //loop to check input
    while ((!building.isactive(input,5)))
    {
        cout << "Access Denied" << endl;
        cin >> input;
    }
    cout << "Access granted" << endl;
    //deactivating code
    building.deactivate(input);
    building.change_level(9999,8);
    building.activate(1111,7);
    
    cin >> input;
    while ((!building.isactive(input,7)))
    {
        cout << "Access Denied" << endl;
        cin >> input;
    }
    cout << "Access granted" << endl;
    
    return 0;
}