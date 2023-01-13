/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p5
*/

#include<iostream>
#include<algorithm>
#include<time.h>
#include<set>

using namespace std;

//defining struct class
struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main(){
    int x;
    set<int> num;
    //initializing randomization
    srand (time(NULL));
    for(int i=0;i<6;i++){
        x = rand() % 49 +1;
        num.insert(x);
    }
    //sort(num.begin(),num.end(), myobject);
    for(auto n:num){
        cout << n << " ";
    }
    cout << endl;
}