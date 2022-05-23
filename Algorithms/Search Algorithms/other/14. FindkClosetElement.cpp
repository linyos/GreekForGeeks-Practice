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

using namespace std;


//Find cross over point 
//(the point before which elements are smaller than or equal to x and after
// which greater than x)
int findCrossOver(int arr[], int low, int high, int x)
{
	if (arr[high] <=x)
	{
		return high;
	}
	if (arr[low] > x)
	{
		return low;
	}

	int mid = low+(high-low)/2;

	/* If x is same as middle element, then return mid */
	if (arr[mid] <=x && arr[mid+1] >x)
	{
		return mid;
	}

	if (arr[mid] < x )
	{
		return findCrossOver(arr , mid+1  , high , x); 
	}
	return findCrossOver(arr, low , mid-1 ,x);

}

void printKclosest(int arr[], int x, int k, int n)
{
	// Find the crossOver point
	int l = findCrossOver(arr , 0 ,n-1 , x);

	cout << l <<endl;
	// right index to search
	int r = l+1;
	// To keep track of count of element already printed
	int count = 0 ;


	// IF x is present in arr[] , then reduce left index 
	// all element in arr[] are distinct.
	if (arr[l]==x ) l--;

	cout<< arr[l]<<endl;
	while (l >=0 && r< n && count < k )
	{
		if (x -arr[l] < arr[r]-x)
		{
			cout<< arr[l--]<<" ";
		}
		else
		{
			cout<< arr[r++]<<" " ;
		}
			count++;
	}


	// If there are no more elements on right side, then print left element.
	while (count < k && l>= 0 )
	{
		cout<< arr[l--]<<" ";
		count++;
	}

	// If there are no more elements on left side, then
    // print right elements
	while (count< k && r<n)
	{
		cout<< arr[r++]<<" " ;
		count++;
	}
}



int main()
{  
	int arr[] ={12, 16, 22, 30, 35, 39, 42,
            45, 48, 50, 53, 55, 56};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 35, k = 4;
	printKclosest(arr, x, 4, n);

	system("pause");
	return 0;
}