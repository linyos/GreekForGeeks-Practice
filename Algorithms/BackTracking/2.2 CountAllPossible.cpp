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


// Method : recursive
int numberOfPaths(int m, int n)
{
	if (m==1 || n==1)
	{
		return 1;
	}
	return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
}


// Method : DP
int numberOfPathsDP(int m, int n)
{
	int count[3 + 1][3 + 1];

	for (int i = 0; i < m; i++)
	{
		count[i][0] = 1;
	}
	for (int j = 0; j < n; j++)
	{
		count[0][j] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			count[i][j] = count[i - 1][j] + count[i][j - 1];
		}
	}
	return count[m - 1][n - 1];
}


int numberOfPathsDP2(int n, int m, int DP[4][4]) {
	if (n==1 || m==1)
	{
		return DP[n][m] = 1;
	}
	if (DP[n][m]==0)
	{
		DP[n][m] = numberOfPathsDP2(n - 1, m, DP) + numberOfPathsDP2(n, m - 1, DP);
	}
	return DP[n][m];
}
int main()
{


	cout << numberOfPaths(3, 3) << endl;
	cout << numberOfPathsDP(3, 3) << endl;

	int DP[4][4] = { 0 };
	memset(DP, 0, sizeof(DP));

	cout << numberOfPathsDP2(3, 3, DP);

	system("pause");
	return 0;
}
