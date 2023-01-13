/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p8
*/

#include<iostream>
#include<map>

using namespace std;

class Access {
    public:
        void activate(unsigned int code, unsigned int level);
        void deactivate(unsigned int code);
        bool isactive(unsigned int code, unsigned int level) const;
        void change_level(unsigned int code, unsigned int level);
    private:
        map<int,unsigned int> contents;
        int size=0;
};
