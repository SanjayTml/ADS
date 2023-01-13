#include<iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

const int beginval = 0;
const int endval = 20000;
const int range = 500;
const int steps = 600;

void Selection_sort(int Arr[], int n){
    int holder, key;
    for(int j=0; j<(n-1); j++){
        holder = Arr[j];
        key = Arr[j+1];
        int pos = j+1;
        for(int i=j+2; i<n; i++){
            if(Arr[i] < key){
                key = Arr[i];
                pos = i;
            }
        }
        Arr[j] = key;
        Arr[pos] = holder;
    }
}


int* averageCase(int n) {
    int* arr = new int[n];
    //randomizing elements
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % range + 1;
    }
    return arr;
}

int* bestCase(int n) {
    int* arr = new int[n];
    arr = averageCase(n);
    //sorting array beforehand for best case   
    Selection_sort(arr, n);
    return arr;
}

int* worstCase(int n) {
    int* arr = new int[n];
    arr = averageCase(n);
    int temp;
    //the order of items should be alternated as highest, lowest, 2nd highest....
    //for alternating highest elements
    for (int i = 0; i < n; i=i+2)
    {
        int high = arr[i];
        temp = arr[i];
        int pos = i;
        for (int j = i-1; j < n; j++)
        {
            if (arr[j]>high)
            {
                high = arr[j];
                pos = j;
            }
            
        }
        arr[i] = high;
        arr[pos] = temp;
    }
    //for alternating lowest elements
    for (int i = 1; i < n; i=i+2)
    {
        int low = arr[i];
        temp = arr[i];
        int pos = i;
        for (int j = i-1; j < n; j++)
        {
            if (arr[j]<low)
            {
                low = arr[j];
                pos = j;
            }
            
        }
        arr[i] = low;
        arr[pos] = temp;
    }
    return arr;
}

int main() {
    double besttime, avgtime, worsttime;
    double timetaken;
    ofstream filep;
    filep.open("data.txt");
    for (int n = beginval; n < endval; n+=steps)
    {
        int* arr = new int[n];
        // best case scenario
        timetaken = 0;
        for(int i=0; i<3; i++) {
            arr = bestCase(n);
            auto startTime = chrono::system_clock::now();
            Selection_sort(arr, n);
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
            Selection_sort(arr, n);
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
            Selection_sort(arr, n);
            auto endTime = chrono::system_clock::now();
            chrono::duration<double> diff = endTime - startTime;
            timetaken += diff.count();
        }

        worsttime = timetaken / 3;

        filep << n << " " << besttime << " " << avgtime << " " << worsttime << endl;
    }
    
    filep.close();
    return 0;
}