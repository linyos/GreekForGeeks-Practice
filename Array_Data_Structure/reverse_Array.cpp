#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void swap(int * a, int  *b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void ReverseArray(int *arr, int start, int end) {
	while (start < end) {
		swap(*(arr + start), *(arr + end));
		start++;
		end--;
	}
}

void printArray(int *arr, int  n) {
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;


}

int main() {

	int arr[] = { 1, 2, 3, 4, 5, 6 };

	int n = sizeof(arr) / sizeof(arr[0]);

	// To print original array
	printArray(arr, n);



	ReverseArray(arr, 0, n - 1);
	printArray(arr, n);
	system("pause");
	return 0;
}