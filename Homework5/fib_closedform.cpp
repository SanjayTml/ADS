#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
    int num = 0;
    long double res;
    ofstream filep;
    filep.open("closedform.txt");
    for (int i = 0; i < 30; i++)
    {
        auto startTime = chrono::system_clock::now();
        res = pow((1+sqrt(5))/2,num)/sqrt(5);
        auto endTime = chrono::system_clock::now();
        chrono::duration<double> diff = endTime - startTime;
        filep << num << " " << round(res) << " " << diff.count() << endl;
        num++;
        if (i>10)
        {
            num = num + num/4;
        }
        
    }
    filep.close();
    return 0;
}