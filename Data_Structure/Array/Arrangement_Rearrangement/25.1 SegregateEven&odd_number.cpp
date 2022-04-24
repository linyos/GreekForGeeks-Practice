#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;




void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}



// Method 1 : simple 
void segregateEvenOdd(int arr[], int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		while (arr[left]%2==0 && left < right)
		{
			left++;
		}
		while (arr[right] %2 ==1 && left<right)
		{
			right--;
		}
		if (left<right)
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
}


// Method 2 : lomuto partition 
void rearrangeEvenAndOdd(int arr[], int n)
{
	int j = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] %2==0)
		{
			j++;
			swap(&arr[i], &arr[j]);
		}
	}
}




// method 3: stable partition
void rearrangeEvenAndOdd(vector<int>v)
{
	stable_partition(v.begin(), v.end(), [](auto a)
	{
		return a % 2 == 0;
	});
	for (int num : v)
		cout << num << " ";
}






void segregrate(int arr[], int n)
{
	int i = 0, j = n - 1;

	// Iterate while j >= i
	while (j >=i )
	{ 
		
		// Check is a[i] is even or odd
		if (arr[i] %2 !=0)
		{

			if (arr[j]%2==0)
			{
				// Swap a[i] and a[j]
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
			else
			{
				j--;
			}
		}
		else
		{
			i++;
		}
	}


	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}





int main() {
	int arr[] = { 12, 34, 45, 9, 8, 90, 3 };
	int n= sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	//segregateEvenOdd(arr,n);

	//cout << "Array after segregation ";
	//for (i = 0; i < arr_size; i++)
	//	cout << arr[i] << " ";


	cout << "Array after rearrange ";

	rearrangeEvenAndOdd(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;


	cout << "Using stable partition" << endl;

	vector<int> v = { 12, 10, 9, 45, 2, 10, 10, 45 };

	// Function Call
	rearrangeEvenAndOdd(v);


	cout << endl; 

	int a[] = { 1,2,3,4,5,6 };
	int n1 = sizeof(a) / sizeof(a[0]);

	// Function Call
	segregrate(a, n1);


	system("pause");
	return 0;
}




