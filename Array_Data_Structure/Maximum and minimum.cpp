#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Pair
{
public:
	int min;
	int max;
	Pair getminmax(int arr[], int n);
	Pair getminmax(int arr[], int low, int high);
	Pair getminmax3(int arr[], int n);
};
// Method 1 
Pair getminmax(int arr[], int n) {
	Pair minmax;
	int i;

	if (n == 1) {
		minmax.max = arr[0];
		minmax.min = arr[0];
		cout << "only one element  value: " << arr[0];
		return minmax;
	}
	// If there are more than one elements,
	// then initialize min and max 
	if (arr[n] > arr[1]) {
		minmax.max = arr[0];
		minmax.min = arr[1];
	}
	else {
		minmax.max = arr[1];
		minmax.min = arr[0];
	}

	for (i = 2; i < n; i++) {
		if (arr[i] > minmax.max) {
			minmax.max = arr[i];
		}
		else if (arr[i] < minmax.min) {
			minmax.min = arr[i];
		}
	}
	return minmax;
}

// Method 2 
Pair getminmax(int arr[], int low, int high) {
	Pair minmax, mml, mmr;
	int mid;
	// If only one element
	if (low == high) {
		minmax.max = arr[low];
		minmax.min = arr[low];
		return minmax;
	}
	// If two element;
	if (high == low + 1) {
		if (arr[low] > arr[high]) {
			minmax.max = arr[low];
			minmax.min = arr[high];
		}
		else {
			minmax.max = arr[high];
			minmax.min = arr[low];
		}
		return minmax;
	}

	// If more than two element;
	mid = low + (high - low) / 2;
	mml = getminmax(arr, low, mid);
	mmr = getminmax(arr, mid + 1, high);
	// Compare minimums of two parts
	if (mml.min < mmr.min) {
		minmax.min = mml.min;
	}
	else {
		minmax.min = mmr.min;
	}
	if (mml.max > mmr.max)
		minmax.max = mml.max;
	else
		minmax.max = mmr.max;

	return minmax;

}


// Method 3 
Pair getminmax3(int arr[], int n) {
	Pair maxmin;
	int i = 0;
	// If array has even number of elements
	// than initialize the first two element
	// as max and min
	if (n % 2 == 0) {
		if (arr[0] > arr[1])
		{
			maxmin.max = arr[0];
			maxmin.min = arr[1];
		}
		else {
			maxmin.max = arr[1];
			maxmin.min = arr[0];
		}
		// Set the starting index for loop
		i = 2;
	}
	else {
		maxmin.min = maxmin.max = arr[0];

		i = 1;
	}

	while (i < n - 1) {
		if (arr[i] > arr[i + 1]) { // 1. compare array with arr[1] and arr[i+1]
			if (arr[i] > maxmin.max) {  //  2. compare the pair with max and min 
				maxmin.max = arr[i];
			}
			else if (arr[i + 1] < maxmin.min) {
				maxmin.min = arr[i + 1];
			}
		}
		else {
			if (arr[i + 1] > maxmin.max) {
				maxmin.max = arr[i + 1];
			}
			else if (arr[i] < maxmin.min) {
				maxmin.min = arr[i];
			}
		}
		i += 2;
	}
	return maxmin;
}


int main() {

	int arr[] = { 1000, 11, 445,
					1, 330, 3000 };
	int arr_size = 6;
	Pair minmax;
	// Method1
	minmax = getminmax(arr, arr_size);
	// Method 2
	minmax = getminmax(arr, 0, arr_size - 1);
	// Method 3
	minmax = getminmax3(arr, arr_size);
	cout << "Minimum element is "
		<< minmax.min << endl;
	cout << "Maximum element is "
		<< minmax.max;
	system("pause");
	return 0;
}