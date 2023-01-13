#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
    int num = 0;
    long long int res;
    ofstream filep;
    filep.open("bottomup.txt");
    for (int i = 0; i < 30; i++)
    {
        long long int fib[num+1];
        auto startTime = chrono::system_clock::now();
        if(num<2){
            res = num;
        }
        else
        {
            fib[0] = 0;
            fib[1] = 1;
            for (int i = 2; i < (num+1); i++)
            {
                fib[i] = fib[i-1] + fib[i-2];
            }
            res = fib[num];
        }
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