#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <ctime>
#include <time.h>
#include <stack>


using namespace std;


// Returns number of times x occurs in arr[0..n-1]
int countOccurrences(int arr[], int n, int x)
{
	int res =0 ;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
			res++;
	}

	return res;
}

// Binary Search 
int binarySearch(int arr[], int l, int r, int x)
{
	if (r < l)
		return -1;

	int mid = l + (r-l)/2;

	if (arr[mid]==x)
		return mid;

	if (arr[mid] > x)
	{
		return binarySearch(arr , l , mid-1 , x);
	}
	return binarySearch(arr , mid+1 , r ,x);
}


int countOccurrences2(int arr[], int n, int x)
{
	int ind = binarySearch(arr , 0 , n-1 , x);

	if (ind ==-1)
		return 0;

	// Count element on left side
	int count =1;
	int left = ind-1;
	while (left >= 0 && arr[left] == x)
	{
		count++ , left--;
	}
	
	int right = ind+1;
	while (right< n && arr[right]==x)
	{
		count ++ , right++;
	}
	return count;
}


// Method 3 ()
/* if x is present in arr[] then returns the count
	of occurrences of x, otherwise returns 0. */
int count(int arr[], int x, int n)
{
	/* get the index of first occurrence of x */
	
	int *low = lower_bound(arr ,arr+n ,x);       // 找出vector中「大於或等於」val的「最小值」的位置：
	// If element is not present, return 0
	if (low==(arr+n) || *low != x)
		return 0;

	/* Else get the index of last occurrence of x.
	Note that we are only looking in the
	subarray after first occurrence */
	
	int * high = upper_bound(low , arr+n , x);  //找出vector中「大於」val的「最小值」的位置



	return high -low;
}

int main()
{  
	 int arr[] = {1, 2, 2, 2, 2, 3, 4, 7 ,8 ,8 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 2;
    cout << countOccurrences(arr, n, x) << endl;

	cout << countOccurrences2(arr, n, x) << endl;


	int c = count(arr, x, n);
	printf(" %d occur %d times " , x , c);

	system("pause");
	return 0;
}