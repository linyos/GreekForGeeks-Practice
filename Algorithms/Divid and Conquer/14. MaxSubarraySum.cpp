#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;


int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	return max(max(a, b), c);
}



// Find the maxmium possible  sum in arr[] such that arr[m] is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
	int sum = 0;
	int left_sum = INT_MIN;
	for (int i = m; i >=l  ; i--)
	{
		sum += arr[i];
		if (sum > left_sum)
		{
			cout << sum << endl;
			left_sum = sum;
		}
	}

	cout << left_sum;
	return 0;
}


int maxSubArraySum(int arr[], int l, int h)
{
	if (l==h)
	{
		return arr[l];
	}
	int m = l + (h - l) / 2;

	return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m ,h));

}


int main() 
{
	int arr[] = { 2, 3, 4, 5, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int max_sum = maxSubArraySum(arr, 0, n - 1);
	printf("Maximum contiguous sum is %d\n", max_sum);



	
	system("pause"); 
	return 0;
}


