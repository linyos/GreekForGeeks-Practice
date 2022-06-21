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

int max(int a, int b)
{
	return a > b ? a : b;
}


// 1. Optimal Substructure: 
int cutRod(int price[], int index, int n)
{
	if (index == 0)
		return n * price[0];

	int notCut = cutRod(price, index - 1, n);
	int cut = INT_MIN;
	
	int rod_length = index + 1;

	if (rod_length <= n )
	{
		cut = price[index] + cutRod(price, index, n - rod_length);
	}
	return max(notCut, cut);
}



// Method 2 : Overlapping Subproblems 

int cutRod2(int price[], int index, int n, vector<vector<int>> & dp)
{
	if (index == 0)
		return n * price[0];
	if (dp[index][n] != -1)
	{
		return dp[index][n];
	}

	int notCut = cutRod2(price, index - 1, n, dp);
	int cut = INT_MIN;
	int rod_length = index + 1;

	if (rod_length <= n )
	{
		cut = price[index] + cutRod2(price, index, n - rod_length, dp);
	}
	return dp[index][n] = max(notCut, cut);
}
//int cutRod(int price[], int n)
//{
//	// n = 8 
//	int val[8 + 1];
//	val[0] = 0;
//	int i, j;
//
//
//	// Build the table val[] in bottom up manner and return the 
//	// last entry from the table
//
//	for (i = 1; i <= n; i++)
//	{
//		int max_val = INT_MIN;
//		for ( j= 0; j < i; j++)
//		{
//			max_val = max(max_val, price[j] + val[i - j - 1]);
//		}
//		val[i] = max_val;
//	}
//	return val[n];
//}


int main() 
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Obtainable Value is "
		<< cutRod(arr, size - 1, size) << endl;



	vector<vector<int>> dp(size, vector<int>(size + 1, -1));
	cout << "Maximum Obtainable Value is "
		<< cutRod2(arr, size - 1, size, dp) << endl;

	system("pause"); 
	return 0;
}




