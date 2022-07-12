#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>

using namespace std;


// Method 1 : Simple 
int getPairsCount(int arr[], int n, int sum)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] + arr[j]==sum)
			{
				cout << "(" << arr[i] <<"," << arr[j] << ")" << endl;
				count++;
			}
		}
	}
	return count;
}



// Method 2 : Hash
int getPairsCount2(int arr[], int n, int sum)
{
	unordered_map <int, int> m;

	for (int i = 0; i < n; i++)
	{
		m[arr[i]]++;
	}


	int count = 0;
	// Iterate through each element and increment the count 
	for (int i = 0; i < n; i++)
	{
		count += m[sum - arr[i]];

		cout << "Count : " << count<< endl;
		if (sum- arr[i]==arr[i])
		{
			count--;
		}
	}
	// return the half of twice_count
	return count / 2;
}


int getPairsCount3(int arr[], int n, int k)
{
	unordered_map <int, int> m;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (m.find(k -arr[i]) != m.end())
		{
			count += m[k - arr[i]];
		}
		m[arr[i]]++;
	}
	return count;
}


int main()
{

	int  arr[] = { 1 ,5 ,7,-1,5 }; 
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6; 
	cout<< "Count of pair is " << getPairsCount2(arr, n, sum);
		 

	system("pause");
	return 0;
}
