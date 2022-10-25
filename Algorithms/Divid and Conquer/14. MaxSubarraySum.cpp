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


int max(int a , int b)
{
	return a>b ? a: b;
}


int max(int a , int b , int c)
{
	return max(max(a ,b) ,c);
}




// Find the maximum possible sum in arr[] auch that arr[m]
// is part of it
int maxCrossSum (int arr[] , int l , int m , int h)
{
	// Include elements on left of mid.
	int sum = 0 ;
	int left_sum = INT_MIN;
	for (int i = m; i >=l; i--)
	{
		sum += arr[i];
		if (sum > left_sum)
		{
			left_sum = sum;
		}
	}
	// Include elements on right of mid.
	sum =0 ;
	int right_sum = INT_MIN;
	for (int i = m+1; i <= h; i++)
	{
		sum +=arr[i];
		if (sum > right_sum)
		{
			right_sum = sum;
		}
	}

	// Return sum of elements on left and right of mid
	// returning only left_sum + right_sum will fail for
	// [-2, 1]
	return max(left_sum + right_sum  , left_sum , right_sum);
}




// Return sum of maximum sum subarray in arr[l..h]
int  maxSubArraySum(int arr[] , int l , int h )
{
	// Base Case: Only one element
	if (l==h)
		return arr[l];
	// Find middle point
	int m = l + (h-l)/2;
	/* Return maximum of following three possible cases
			a) Maximum subarray sum in left half
			b) Maximum subarray sum in right half
			c) Maximum subarray sum such that the subarray
	crosses the midpoint */
	return max(maxSubArraySum(arr , l , m) , 
			   maxSubArraySum(arr , m+1 , h),
			   maxCrossSum(arr,l , m ,h));

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

