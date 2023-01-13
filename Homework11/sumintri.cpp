#include <iostream>
#include <algorithm>

using namespace std;

void maxsum(int **arr, int n){
    int addarr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            addarr[i][j] = arr[i][j];
        }
        
    }
    for (int i=n-2; i>=0; i--){
		for (int j=0; j<=i; j++){
			//adding bottom up the longest paths
			if (addarr[i+1][j] > addarr[i+1][j+1]){
				addarr[i][j] += addarr[i+1][j];
			} else {
				addarr[i][j] += addarr[i+1][j+1];
			}
		}
	}
    //printing the maximum sum
    cout << addarr[0][0];
    cout << endl;
    int j = 0;
    //printing the longest path
	for (int i = 0; i < n; i++){
		cout << arr[i][j] <<" ";
		if (addarr[i+1][j] <  addarr[i+1][j+1]){
			j++;
		}
	}
    cout << endl;
}

int main(){
    int n;
    cout << "Enter height of the triangle" << endl;
    cin >> n;
    int **arr;
    arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    cout << "Enter elements of the triangle" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    maxsum(arr,n);
    return 0;
}