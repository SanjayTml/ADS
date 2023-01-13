#include <iostream>

using namespace std;

void print(int a[], int sz) {
	for (int i = 0; i < sz;  i++ ) cout << a[i] << " ";
	cout << endl;
}

void CountingSort(int arr[], int sz) {
	int i, j, k;
	int idx = 0;
	int min, max;
 
	min = max = arr[0];
	for(i = 1; i < sz; i++) {
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}
 
	k = max - min + 1;
	/* creates k buckets */
	int *B = new int [k]; 
	for(i = 0; i < k; i++) B[i] = 0;

	for(i = 0; i < sz; i++) B[arr[i] - min]++;
	for(i = min; i <= max; i++) 
		for(j = 0; j < B[i - min]; j++) arr[idx++] = i;
 
	print(arr,sz);

	delete [] B;
}

int main()
{
	int a[] = {9,1,6,7,6,2,1};
	const size_t sz = sizeof(a)/sizeof(a[0]);
    cout << "Initial array" << endl;
	print(a,sz);
	cout << "<------------>\n" ;
    cout << "Sorted array" << endl;
	CountingSort(a, sz);
}