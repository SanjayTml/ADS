#include <iostream>
#include <algorithm>

using namespace std;

void maxsubarr(int *arr, int n){
    int counter[n];
    for (int i = 0; i < n; i++)
    {
        counter[i] = 1;
    }

    // loop to find length of increasing subarray for
    // each element of the given array
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && counter[i] < counter[j]+1){
                counter[i] = counter[j] + 1;
            }
        }
        
    }

    //get the maximum value of the counter array
    int maximum = *max_element(counter,counter+n);
    int subarr[maximum];
    int j=0, helper = maximum;

    // loop to store longest subarray using bottom up approach
    for (int i = n-1; i >= 0; i--)
    {
        if(counter[i] == helper){
            subarr[j] = arr[i];
            j++;
            helper--;
        }
    }
    
    //reverse the array
    reverse(subarr, subarr+maximum);
    
    cout << "One of the optimal solution is:" << endl;
    for (int i = 0; i < maximum; i++)
    {
        cout << subarr[i] << " ";
    }
    cout << endl;
    
}

int main(){
    int n;
    cout << "Enter size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    maxsubarr(arr, n);
    
    return 0;
}