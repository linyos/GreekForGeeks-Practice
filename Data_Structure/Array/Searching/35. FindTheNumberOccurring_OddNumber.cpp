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

// Simple Solution
int getOddOccurrence(int arr[], int arr_size)
{

	for (int i = 0; i < arr_size; i++)
	{
		int count = 0;
		for (int j = 0; j < arr_size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count % 2 !=0)
		{
			return arr[i];
		}
	}
	return -1;
}


//Method 2 : use Hashing

int getOddOccurrence2(int arr[], int size)
{
	unordered_map <int, int> hash;
	for (int i = 0; i < size; i++)
	{
		hash[arr[i]]++;
	}

	for  (auto i : hash )
	{
		if (i.second %2 != 0)
		{
			return i.first;
		}
	}
	return -1;
}

int main() 
{
	int arr[] = { 2, 3, 5, 4, 5, 2,
					4, 3, 5, 2, 4, 4, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function calling
	cout << getOddOccurrence(arr, n);

	
	system("pause"); 
	return 0;
}


