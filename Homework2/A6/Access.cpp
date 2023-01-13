/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p6
*/

#include<iostream>
#include "Access.h"
#include<set>

using namespace std;

//defining methods
void Access::activate(unsigned int code){
    codes.insert(code);
    size++;
}

void Access::deactivate(unsigned int code){
    codes.erase(code);
    size--;
}

bool Access::isactive(unsigned int code) const{
    for(auto n:codes){
        if(code==n){
            return true;
        }
    }
    return false;
}