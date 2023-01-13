#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int Fibonacci(int n){
    if(n<2){
        return n;
    }
    else
    {
        return Fibonacci(n-1) + Fibonacci (n-2);
    }
}

int main(){
    int num = 0;
    long long int res;
    ofstream filep;
    filep.open("recursion.txt");
    for (int i = 0; i < 30; i++)
    {
        auto startTime = chrono::system_clock::now();
        res = Fibonacci(num);
        auto endTime = chrono::system_clock::now();
        chrono::duration<double> diff = endTime - startTime;
        filep << num << " " << res << " " << diff.count() << endl;
        num++;
        if (i>10)
        {
            num = num + num/4;
        }
        
    }
    filep.close();
    return 0;
}