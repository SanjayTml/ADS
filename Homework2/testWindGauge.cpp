/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p3
*/

#include<iostream>
#include<deque>
#include "WindGauge.h"

using namespace std;

int main(){
    WindGauge one;
    //giving inputs
    one.currentWindSpeed(15);
    one.currentWindSpeed(16);
    one.currentWindSpeed(12);
    one.currentWindSpeed(15);
    one.currentWindSpeed(15);
    //printing input
    one.dump();
    one.currentWindSpeed(16);
    one.currentWindSpeed(17);
    one.currentWindSpeed(16);
    one.currentWindSpeed(16);
    one.currentWindSpeed(20);
    one.currentWindSpeed(17);
    one.currentWindSpeed(16);
    one.currentWindSpeed(15);
    one.currentWindSpeed(16);
    one.currentWindSpeed(20);
    one.dump();
    return 0;
}