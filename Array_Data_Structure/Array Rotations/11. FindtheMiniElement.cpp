#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include<cassert>
#include <set>
#include <map>

using namespace std;


int findMin(int arr[] , int low , int high)
{
	if (high < low) return arr[0];

	if (high==low) return arr[0];

	int mid = low + (high-low)/2;

	if (mid < high && arr[mid+1] < arr[mid])
	{
		return arr[mid+1];
	}
	if (mid > low && arr[mid-1] > arr[mid])
	{
		return arr[mid];
	}
	if (arr[high] > arr[mid])
	{
		return findMin(arr , low , mid-1);
	}
	return findMin(arr , mid+1 , high);
}



int findMin2 (int * arr , int low , int high)
{
	if( high < low) return *arr;

	if (high==low) return *arr;

	int mid = low + (high-low)/2;

	if (mid < high && *(arr+mid+1) <*(arr+ mid))
	{
		return * (arr+mid +1);
	}
	if (mid > low && *(arr + mid-1) > *(arr + mid))
	{
		return *(arr+mid);
	}

	if (*(arr+high) > *(arr + mid))
	{
		return findMin2(arr, low , mid-1);
	}
	return findMin2(arr , mid+1 , high);
	
}


int  main() {

	int arr1[] ={5, 6, 1, 2, 3, 4};
	 int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "The minimum element is " << findMin(arr1, 0, n1-1) << endl;



	int *p = arr1;

	  cout << "The minimum element is " << findMin2(p, 0, n1-1) << endl;
	system("pause");
	return 0;
}



