#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;

/*Method  Simple Solution
	 one by one check the given condition
*/
int findMaxSum(int arr[], int n) {
	int res = INT_MIN;
	for (int i = 0; i < n; i++){
		int prefix_sum = arr[i];
		for (int j = 0; j < i; j++)
		{
			prefix_sum += arr[j];
		}
		int suffix_sum = arr[i];

		for (int j = n-1; j > i; j--){
			suffix_sum += arr[j];
		}
		if (prefix_sum==suffix_sum){
			
			res = max(res, prefix_sum);
		}
	}
	return res;

}
*
Method 2: Better Approach
traverse the array and store prefix sum
* /
int findMaxSum(int arr[], int n) {
	int preSum[8];
	int suffSum[8];

	int ans = INT_MIN;

	preSum[0] = arr[0];
	// Calculate suffix sum 
	for (int i = 1; i < n; i++)
	{
		preSum[i] = preSum[i - 1] + arr[i];
	}
	// Calculate suffix sum and compare
	// it with prefix sum. Update ans
	// accordingly.
	suffSum[n - 1] = arr[n - 1];
	if (preSum[n - 1] == suffSum[n - 1])
	{
		ans = max(ans, preSum[n - 1]);
	}

	for (int i = n - 2; i >= 0; i--)
	{
		suffSum[i] = suffSum[i + 1] + arr[i];
		if (suffSum[i] == preSum[i])
		{
			ans = max(ans, preSum[i]);
		}
	}
	return  ans;
}
int main() {
	int arr[] = { -2, 5, 3, 1,
			   2, 6, -4, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findMaxSum(arr, n);


	system("pause");
	return 0;
}