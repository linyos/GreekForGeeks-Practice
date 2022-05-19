#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>

using namespace std;

# define R 3
#define C 3



int min(int x, int y, int z)
{
	if (x <y )
	{
		return (x < z) ? x : z;
	}
	else
	{
		return (y < z) ? y : z;
	}
}


int minCost(int cost[R][C], int m, int n)
{
	if (n < 0 || m < 0) return INT_MAX;
	else if (m == 0 && n == 0) return cost[m][n];
	else
	{
		return cost[m][n] + min(minCost(cost, m - 1, n - 1), minCost(cost,m - 1, n), minCost(cost,m, n - 1));
	}
}




int minCostDP(int cost[R][C], int m, int n)
{
	int i, j;
	int tc[R][C];
	tc[0][0] = cost[0][0];

	for ( i = 1; i <= m  ; i++)
	{
		tc[i][0] = tc[i - 1][0] + cost[i][0];
	}
	for ( j = 1; j <= n; j++)
	{
		tc[0][j] = tc[0][j - 1] + cost[0][j];
	}
	for ( i = 1; i <=m ; i++)
	{
		for ( j = 1; j <= n ; j++)
		{
			tc[i][j] = min(tc[i - 1][j - 1], tc[i - 1][j], tc[i][j - 1]) + cost[i][j];
		}
	}
	return tc[m][n];
}
int main() 
{
	int cost[R][C] = { { 1, 2, 3 },
					   { 4, 8, 2 },
					   { 1, 5, 3 } };
	cout << minCost(cost, 2, 2) << endl;

	cout << minCostDP(cost, 2, 2) << endl;

	system("pause");
	return 0;
}


