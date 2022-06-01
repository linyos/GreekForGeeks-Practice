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


// method 1:  Prints all triplets in arr[] with 0 sum
void findTriplets(int arr[], int n)
{
	bool found = false;
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i+1; j < n-1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] ==0 )
				{
					cout << arr[i] << " " << arr[j] << " "<< arr[k] << endl;
					found = true;
				}
			}
		}
	}
	if (found == false)
		cout << " not exist " << endl;
}

// Method 2: Using Hashing
void findTriplets1(int arr[], int n)
{
	bool found = false;

	for (int i = 0; i < n-1; i++)
	{
		unordered_set<int> s;
		for (int j = i+1; j < n; j++)
		{
			int x = -(arr[i]+arr[j]);
			if (s.find(x) != s.end())
			{
				printf("%d %d %d \n", x, arr[i], arr[j]);
				found = true;
			}
			else
			{
				s.insert(arr[j]);
			}
		}
	}
	if (found == false)
	{
		cout << " No Triplet Found" << endl;
	}
}

// Method 3 : 
void findTriplets2(int arr[], int n)
{
	bool found = false;

	sort(arr, arr + n);

	for (int i = 0; i < n-1; i++)
	{
		int l = i + 1;
		int r = n - 1; 
		int x = arr[i];
		while (l < r)
		{
			if (x+ arr[l] + arr[r]==0)
			{
				printf("%d %d %d \n", x, arr[l], arr[r]);
				l++;
				r--;
			}
			else if (x +arr[l] + arr[r] <0 )
			{
				l++;
			}
			else
			{
				r--;
			}
		}

	}
	if (found == false)
		cout << " No Triplet Found" << endl;
}



int main() 
{
	int arr[] = { 0, -1, 2, -3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findTriplets2(arr, n);
	system("pause"); 
	return 0;
}


