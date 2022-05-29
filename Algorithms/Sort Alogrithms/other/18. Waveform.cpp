#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;




void swap(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// method : simple 
void sortInWave(int arr[], int n)
{
	sort(arr, arr + n);

	for (int i = 0; i < n-1; i+=2)
	{
		swap(&arr[i], &arr[i + 1]);
	}
}





// This function sorts are [0..n-1] in wave form .
//i.e., arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5] ....
void sortInWave1(int arr[], int n)
{
	for(int i = 0; i < n; i+=2)
	{
		// If current even element is smaller than previous
		if (i > 0 && arr[i-1]> arr[i])
		{
			swap(&arr[i], &arr[i - 1]);
		}
		//If current even element is smaller than next
		if (i < n-1 && arr[i] < arr[i+1])
		{
			swap(&arr[i], &arr[i + 1]);
		}
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
	
	int arr[] = { 10, 90, 49, 2, 1, 5, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortInWave1(arr, n);
	printArray(arr, n);
	
	system("pause"); 
	return 0;
}


