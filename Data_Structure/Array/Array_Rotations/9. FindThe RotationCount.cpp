#include <iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

// Return count of rotations for an array which
// is first sorted in ascending orderm then rotated
int countRotations(int arr[], int n)
{
	int min = arr[0], min_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			min_index = i;
		}
	}
	return min_index;
}




int countRotation(int arr[], int low, int high)
{
	if (high < low) return 0;
	
	if (high == low) return low;

	int mid = low + (high - low) / 2;

	if (mid < high &&  arr[mid+1] < arr[mid])
	{
		return mid + 1;
	}
	if (low < mid &&  arr[mid]  < arr[mid-1]   )
	{
		return mid;
	}


	if (arr[high] > arr[mid])
	{
		return countRotation(arr, low, mid - 1);
	}

	return countRotation(arr, mid + 1, high);

}

int main() 
{


	int arr[] = { 15, 18, 2, 3, 6, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//cout << countRotations(arr, n);

	cout << countRotation(arr, 0, n - 1);
	system("pause");
	return 0;
}


