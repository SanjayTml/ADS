/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p3
*/

#include<iostream>
#include "WindGauge.h"
#include <deque>

using namespace std;

//initializing counter
int WindGauge::counter = 0;

//defining methods
WindGauge::WindGauge(int period){
    timeper = period;
}

void WindGauge::currentWindSpeed(int speed){
    counter++;
    if(counter>timeper){
        this->speed.pop_front();
        counter--;
    }
    this->speed.push_back(speed);
}

int WindGauge::highest() const{
    int high=speed[0];
    for(auto n:speed){
        if(n>high){
            high = n;
        }
    }
    return high;
}

int WindGauge::lowest() const{
    int low=speed[0];
    for(auto n:speed){
        if(n<low){
            low = n;
        }
    }
    return low;
}

int WindGauge::average() const {
    int sum=0;
    for(auto iter=speed.begin();iter < speed.end(); iter++){
        sum = sum + *iter;
    }
    return (sum/counter);
}

void WindGauge::dump() {
    cout << "Highest speed: " << highest() << endl;
    cout << "Lowest speed: " << lowest() << endl;
    cout << "Average speed: " << average() << endl;
}