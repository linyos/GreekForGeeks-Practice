#include <iostream>

using namespace std;
int interpolationSearch(int arr[], int n, int x) {
	int lo = 0; //�@Starting index in arr[]
	int hi = (n - 1); // Ending index in arr[]
	while (lo<= hi && x >=arr[lo] && x <=arr[hi]){
		if (lo==hi){
			if (arr[lo] == x) return lo;
			return -1; // not Found  value
		}

		int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo]))*(x - arr[lo]));

		if (arr[pos] == x) return pos;
		if (arr[pos] < x) {
			lo = pos + 1;
		}
		else{
			hi = pos - 1;
		}
	}
	return -1;
}

int main() {
	int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
			  22, 23, 24, 33, 35, 42, 47 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int x = 18;
	int index = interpolationSearch(arr, n, x);

	// If element was found
	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";



	system("pause");
	return 0;
}