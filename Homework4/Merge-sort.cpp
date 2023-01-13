#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

const int beginval = 10;
const int endval = 20000;
const int range = 500;
const int steps = 600;

void Insertion_sort(double Arr[], int l, int r){
    int holder, key;
    for(int j=l; j<r; j++){
        key = Arr[j];
        int pos = j-1;
        while(pos >= l && key < Arr[pos]){
            holder = Arr[pos];
            Arr[pos] = key;
            Arr[pos+1] = holder;
            key = holder;
            pos--;
        }
    }
}

void merge(double* arr, double* temp, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while ((i <= m) && (j <= r))
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

        for (; j <= r; j++, k++)
            temp[k] = arr[j];

        for (; i <= m; i++, k++)
            temp[k] = arr[i];

        for (i = l; i <= r; i++)
            arr[i] = temp[i];
}

void mergesort(double* arr, double* temp, int l, int r, int threshold)
{
    if (l < r)
    {
        if ((r - l) <= threshold)
            Insertion_sort(arr, l, r);
        else
        {
            int m = (l + r) / 2;
            mergesort(arr, temp, l, m, threshold);
            mergesort(arr, temp, m + 1, r, threshold);
            merge(arr, temp, l, m, r);
        }
    }
}

double* averageCase(int n) {
    double* arr = new double[n];
    //randomizing elements
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % range + 1;
    }
    return arr;
}

double* bestCase(int n) {
    double* arr = new double[n];
    double* temp = new double[n];
    arr = averageCase(n);
    //sorting array beforehand for best case   
    mergesort(arr, temp, beginval, n, 100);
    return arr;
}

double* worstCase(int n) {
    double* arr = new double[n];
    arr = averageCase(n);
    double* temp = new double[n];
    mergesort(arr, temp, beginval, n, 100);
    double hold = arr[n-1];
    arr[n-1] = arr[0];
    arr[0] = hold;
    return arr;
}

int main() {
    double besttime, avgtime, worsttime;
    double timetaken;
    ofstream filep;
    filep.open("data.txt");
    int thresold = 1;
    for (int n = beginval; n < endval; n+=steps)
    {
        double* arr = new double[n];
        double* temp = new double[n];
        // best case scenario
        timetaken = 0;
        for(int i=0; i<3; i++) {
            arr = bestCase(n);
            auto startTime = chrono::system_clock::now();
            mergesort(arr, temp, beginval, n-1, thresold);
            auto endTime = chrono::system_clock::now();
            chrono::duration<double> diff = endTime - startTime;
            timetaken += diff.count();
        }

        besttime = timetaken / 3;

        // average case scenario
        timetaken = 0;
        for(int i=0; i<3; i++) {
            arr = averageCase(n);
            auto startTime = chrono::system_clock::now();
            mergesort(arr, temp, beginval, n-1, thresold);
            auto endTime = chrono::system_clock::now();
            chrono::duration<double> diff = endTime - startTime;
            timetaken += diff.count();
        }

        avgtime = timetaken / 3;

        // worst case scenario
        timetaken = 0;
        for(int i=0; i<3; i++) {
            arr = worstCase(n);
            auto startTime = chrono::system_clock::now();
            mergesort(arr, temp, beginval, n-1, thresold);
            auto endTime = chrono::system_clock::now();
            chrono::duration<double> diff = endTime - startTime;
            timetaken += diff.count();
        }

        worsttime = timetaken / 3;

        filep << n << " " << besttime << " " << avgtime << " " << worsttime << endl;
        //delete[] arr;
        //delete[] temp;
    }
    
    filep.close();
    return 0;
}