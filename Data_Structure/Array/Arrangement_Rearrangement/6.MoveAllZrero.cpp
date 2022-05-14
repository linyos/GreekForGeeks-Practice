#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <unordered_map>

using namespace std;

void moveZerosToEnd(int arr[], int n)
{
	int count = 0; 

	for (int i = 0; i < n ;i++)
	{
		if (arr[i] != 0)
		{
			arr[count++] = arr[i];
		}
	}


	for (int i = count; i <n ; i++)
	{
		arr[i] = 0;
	}
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}




int main() 
{
	int arr[] = { 0, 1, 9, 8, 4, 0, 0, 2,
						 7, 0, 6, 0, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original array: ";
	printArray(arr, n);

	moveZerosToEnd(arr, n);

	cout << "\nModified array: ";
	printArray(arr, n);

	
	system("pause");
	return 0;
}


