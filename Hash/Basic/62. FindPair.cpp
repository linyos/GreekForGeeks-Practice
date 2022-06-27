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

using namespace std;

void printPairs(int arr[], int n)
{
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (abs(arr[i])==abs(arr[j]))
			{
				v.push_back(abs(arr[i]));
			}
		}
	}

	if (v.size() == 0)
		return;

	for (int i = 0; i < v.size(); i++)
	{
		cout << -v[i] << " " << v[i] << " ";
	}
	cout << endl;
}


// Method 2: Hashing
void printPairs2(int arr[], int n)
{
	vector<int> v;
	unordered_map <int, bool> cnt;

	for (int i = 0; i < n; i++)
	{

		
		// If element has not encounter early,
		// mark it on cnt array.
		if (cnt[abs(arr[i])]==0)
		{
			cnt[abs(arr[i])] =1;
		}
		// If seen before. push it in vector
		else
		{
			v.push_back(abs(arr[i]));
			cnt[abs(arr[i])] = 0;
		}
	}

	if (v.size() == 0)
		return;

	for (int i = 0; i < v.size(); i++)
	{
		cout << "-" << v[i] << " " << v[i] << " ";
	}
}




// Method 3
void printPairs3(int arr[], int n)
{
	unordered_set <int> hs;
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		if (hs.find((arr[i]) * -1) != hs.end() ) 
		{
			if (arr[i] < 0 )
			{
				cout << arr[i] << " ";
				cout << (arr[i] * -1) << " ";
			}
			else
			{
				cout << (arr[i] * -1) << " ";
				cout << arr[i] << " ";
			}
		}
		hs.insert(arr[i]);
	}
	return;
}


int main() 
{
	int arr[] = { 4, 8, 9, -4, 1, -1, -8, -9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//printPairs(arr, n);
	printPairs2(arr, n);

	printPairs3(arr, n);
	system("pause"); 
	return 0;
}




