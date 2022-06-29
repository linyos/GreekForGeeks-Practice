#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;


int floorSearch(int arr[], int low, int high, int x)
{
	if (low> high)
		return -1;
	
	if (x>= arr[high])
	{
		return high;
	}

	int mid = low + (high - low) / 2;

	if (arr[mid]==x)
	{
		return mid;
	}
	if (mid > 0 && arr[mid-1] < x && x < arr[mid])
	{
		return mid - 1;
	}
	if (x< arr[mid])
	{
		return floorSearch(arr, low, mid - 1, x);
	}
	return floorSearch(arr, mid + 1, high, x);
}



int main()
{

	int arr[] = { 1, 2, 4, 6, 10, 12, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 7;
	int index = floorSearch(arr, 0, n - 1, x);
	if (index == -1)
		cout << "Floor of " << x << " doesn't exist in array ";
	else
		cout << "Floor of " << x << " is " << arr[index];
	
	system("pause");
	return 0;
}
