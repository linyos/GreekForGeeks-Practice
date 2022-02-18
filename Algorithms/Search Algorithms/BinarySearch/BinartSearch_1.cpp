#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using	namespace std;



int binarySearch(int arr[], int l, int r, int x) {
	if (r >= l) {
		int mid = r + (l - r) / 2;

		if (arr[mid] == x)
		{
			return mid;
		}
		if (mid > l && arr[mid - 1] == x)
		{
			return mid - 1;
		}
		if (mid < r && arr[mid + 1] == x)
		{
			return mid + 1;
		}

		if (arr[mid] > x) {
			return binarySearch(arr, l, mid - 2, x);
		}
		return binarySearch(arr, mid + 2, r, x);
	}

	return -1;
}


int main()
{

	int arr[] = { 3,2,10,4,40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 4;
	int result = binarySearch(arr, 0, n - 1, x);

	(result == -1) ? cout << "Element is not present in array"
		: cout << "Element is present at index : " << result << endl;

	system("pause");
	return 0;
}