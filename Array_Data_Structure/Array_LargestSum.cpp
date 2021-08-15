// Largest sum contiguous increasing subarray
#include <iostream>
#include <vector>

using namespace std;
int largestSum(int arr[], int n) {

	int result = 0;
	for (int i = 0; i < n; i++){
		int curr_sum = arr[i];
		// 不超過尺吋(n) 以及 下一個數(arr[i+1]) 必須大於當時的數列(arr[i])=> sort
		while (i+1<n && arr[i+1]>arr[i]){
			curr_sum += arr[i + 1];
			i++;
		}

		if (curr_sum >result){
			result = curr_sum;
		}
	}

	return result;
}



int main(void) {
	int arr[] = { 1, 1, 4, 7, 3, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Largest sum = "
		<< largestSum(arr, n);
	system("pause");
	return 0;
}