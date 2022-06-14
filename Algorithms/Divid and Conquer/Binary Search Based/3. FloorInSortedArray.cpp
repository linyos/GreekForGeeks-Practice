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


 /* An inefficient function to get
index of floor of x in arr[0..n-1] */


// Method 1 : Simple linear 
 int floorSearch (int arr[] , int n , int x)
{
	if (x>= arr[n-1])
	{
		return n-1;
	}
	if (x<arr[0])
	{
		return -1;
	}


	// 
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > x)
			return i-1;
	}

	return -1;
}



 // Method 2 

int floorSearch2 (int arr[] , int low , int high , int x)
{
	if (low > high)
		return -1;

	if (x >= arr[high])
		return high;

	int mid = low + (high-low)/2;

	if (arr[mid]==x)
		return mid;

	if (mid > 0 && arr[mid-1] < x  && x < arr[mid])
	{
		return mid-1;
	}

	if (x < arr[mid])
	{
		return floorSearch2(arr,low , mid-1,x);
	}
	return floorSearch(arr , mid+1 , high , x);
}






int main()
{  
		int arr[] = { 1, 2, 4, 6, 10, 12, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 7;
	int index = floorSearch2(arr, n - 1, x);
	if (index == -1)
		cout<<"Floor of "<<x <<" doesn't exist in array ";
	else
		cout<<"Floor of "<< x <<" is " << arr[index];

	system("pause");
	return 0;
}