#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;


// void prod(long int *b,const long int *a){
//     long long int c[4];
//     c[0] = b[0]*a[0] + b[1]*a[2];
//     c[1] = b[0]*a[1] + b[1]*a[3];
//     c[2] = b[2]*a[0] + b[3]*a[2];
//     c[3] = b[2]*a[1] + b[3]*a[3];
//     b[0]=c[0];
//     b[1]=c[1];
//     b[2]=c[2];
//     b[3]=c[3];
// }
// void power(long int* temp,int num){
//     const long int a[] = {1,1,1,0};
//     if (num == 0 || num == 1)
//         return;

//     /*for(int i=1;i < (num-1);i++){
//         prod(temp, a);
//     }*/
//     power(temp, num / 2);
//     prod(temp, a);
//     if (num % 2 != 0)
//        prod(temp, a);
// }

// int fibonacci_matrix(int n){
//    long int temp[] = {1,1,1,0};
//     if (n ==0)
//       return 0;
//     power(temp, (n-1));
//    return temp[0];
// }

void multiply(int F[2][2], int M[2][2]) {
   int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
   int b= F[0][0] * M[0][1] + F[0][1] * M[1][1];
   int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
   int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
   F[0][0] = a;
   F[0][1] = b;
   F[1][0] = c;
   F[1][1] = d;
}
void power(int F[2][2], int n) {
   if (n == 0 || n == 1)
      return;
   int M[2][2] = {{1,1},{1,0}};
   power(F, n / 2);
   multiply(F, F);
   if (n % 2 != 0)
      multiply(F, M);
}
int fibonacci_matrix(int n) {
   int F[2][2] = {{1,1},{1,0}};
   if (n == 0)
      return 0;
   power(F, n - 1);
   return F[0][0];
}

int main(){
    //long int temp[] = {1,1,1,0};
    int num = 0;
    int res;
    ofstream filep;
    filep.open("matrix.txt");
    for (int i = 0; i < 30; i++)
    {
        auto startTime = chrono::system_clock::now();
        res = fibonacci_matrix(num);
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