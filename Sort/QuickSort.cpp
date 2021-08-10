#include <iostream>

using namespace std;

void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// sort two subarrays recursively
int Parition(int *arr, int front, int end) {
	int pivot = arr[end];
	int i = front - 1;
	for (int j = front; j < end; j++){
		if (arr[j] < pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	i++;
	swap(&arr[i], &arr[end]);
	return i;//  Pivot index
}
void QuickSort(int *arr , int front , int end) {
	if (front <end){
		int pivot = Parition(arr, front, end);
		QuickSort(arr, front, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}

}

void PrintArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };
	int n = sizeof(arr) / sizeof(*arr);
	cout << n << endl;
	cout << "original:\n";
	PrintArray(arr, n);

	QuickSort(arr, 0, n - 1);

	cout << "sorted:\n";
	PrintArray(arr, n);

	system("pause");
	return 0;
}