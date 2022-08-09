#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
using	namespace std;




void pswap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



void BubbleSort(int arr[], int n) {
	int i, j;

	for (i= 0;  i< n-1; i++){

		for ( j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				pswap(&arr[j], &arr[j + 1]);
			}
		}
	}


}


// method2 :
void BubbleSort2(int arr[], int n)
{
	if (n == 0 || n == 1) return;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}
	BubbleSort2(arr, n - 1);
}


int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);

	system("pause");
	return 0;

}


