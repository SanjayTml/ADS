/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p3
*/

#include<iostream>
#include<deque>

using namespace std;

//defining windgauge class
class WindGauge {
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
        void dump();
        static int counter;
    private:
        deque<int> speed;
        int timeper;
};
