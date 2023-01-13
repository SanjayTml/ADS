/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p6
*/

#include<iostream>
#include<set>

using namespace std;

//declaring class
class Access {
    public:
        void activate(unsigned int code);
        void deactivate(unsigned int code);
        bool isactive(unsigned int code) const;
    private:
        set<unsigned int> codes;
        int size=0;
};
