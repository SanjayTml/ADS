/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h2_p4
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    //declaration
    vector<int> vecA;
    //providing value
    for(int i=1;i<31;i++){
        vecA.push_back(i);
    }
    vecA.push_back(5);
    //reversing vector
    reverse(vecA.begin(),vecA.end());
    for(int i=0;i<31;i++){
        cout << vecA[i] << " ";
    }
    cout << endl;
    cout << "After Replacing 5 " << endl;
    //replacing all 5 by 129
    replace(vecA.begin(),vecA.end(),5,129);
    for(int i=0;i<31;i++){
        cout << vecA[i] << " ";
    }
    cout << endl;
    return 0;
}