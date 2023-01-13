/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p8
*/

#include<iostream>
#include "Access.h"
#include<map>

using namespace std;

//defining methods
void Access::activate(unsigned int code, unsigned int level){
    contents[code]=level;
    size++;
}

void Access::deactivate(unsigned int code){
    contents.erase(code);
    size--;
}

bool Access::isactive(unsigned int code, unsigned int level) const{
    //checking for code and level of authority
    if(contents.find(code)!=contents.end()){
        if ((contents.at(code)>=level))
        {
            return true;
        }
        
    }
    return false;
}

void Access::change_level(unsigned int code, unsigned int level){
    contents[code]=level;
}