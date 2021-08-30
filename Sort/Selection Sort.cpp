#include <iostream>

using namespace std;
void Swap(int & a, int & b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int arr[], int n) {
	int i, j, min_idx;
	// One by one move boundary of unsorted subarray.
	for ( i = 0; i < n-1; i++){
		min_idx = i; // Find the minimum element in unsorted array
		for ( j =i+1; j < n; j++){
			if (arr[j] < arr[min_idx]){
				min_idx = j;
			}
		}
		// Swap the found minimum element with the first element.
		Swap(arr[min_idx], arr[i]);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	system("pause"); 
	return 0;
}