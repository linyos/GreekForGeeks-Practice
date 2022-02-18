#include <iostream>
using	namespace std;



int binarySearch(int arr[], int low, int high, int x) {

	if (high <= low) {
		return (x >= arr[low]) ? (low + 1) : low;
	}
	int mid = low + (high - low) / 2;
	if (x == arr[mid]) {
		return mid + 1;
	}
	if (x > arr[mid]) {
		return binarySearch(arr, mid + 1, high, x);
	}
	return binarySearch(arr, low, mid - 1, x);
}


void insertionSort(int arr[], int n) {
	int i, loc, j, k, selected;
	for (i = 1; i < n; ++i) {
		j = i - 1;
		selected = arr[i];
		loc = binarySearch(arr, 0, j, selected);
		while (j >= loc) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = selected;
	}
}
int main()
{

	int a[]
		= { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	int n = sizeof(a) / sizeof(a[0]), i;

	insertionSort(a, n);

	cout << "Sorted array: \n";
	for (i = 0; i < n; i++)
		cout << " " << a[i];



	system("pause");
	return 0;
}