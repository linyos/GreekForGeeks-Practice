#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include<unordered_map>
#include <set>

using namespace std;
// Method : Simple 
bool chkPair(int arr[] , int n, int x)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] + arr[j] ==x )
			{
				cout << "Pair with a given sum : " << x << " is (" << arr[i] << ", " << arr[j] << ")" << endl;
				return 1;
			}
		}
	}
	return 0;
}

// Method 1: Sorting and two pointers 
bool hasArrayTwoCandidates(int * A, int arr_size, int sum)
{
	int l, r;
	sort(A, A + arr_size);
	
	r = 0;
	r = arr_size - 1;
	while (l < r)
	{
		if (*(A+l) + *(A+r)==sum)
		{
			return 1;
		}
		else if (*(A+l) + *(A+r) <sum)
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	return 0;
}





pair <int, int > findSum(int *arr, int & n, int &target)
{
	int i, findElement;
	unordered_map<int, int > map;
	pair<int, int > result;
	for ( i = 0; i < n; i++)
	{
		findElement = target - arr[i];
		if (map[findElement])
		{
			result.first = i - 1;
			result.second = map[findElement] - 1;
			break;

		}
		else
		{
			map.insert({ arr[i],i });
		}
	}
	return result;
}

int main() {

	int A[] = { 0, -1, 2, -3, 1 };
	int x = -2;
	int size = sizeof(A) / sizeof(A[0]);

	if (chkPair(A, size, x)) {
		cout << "Valid pair exists" << endl;
	}
	else {
		cout << "No valid pair exists for " << x << endl;
	}


	int arr[] = { 1,5,4,3,7,9,2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int search = 7;
	pair<int, int>ans = findSum(arr, n, search);
	cout << min(ans.first, ans.second) << " " << max(ans.first, ans.second);

	system("pause");
	return 0;
}




