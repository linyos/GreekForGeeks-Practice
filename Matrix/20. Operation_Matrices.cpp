#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include<unordered_map>
#include <set>
#include <stack>
#include <string>

using namespace std;






int main() {
	const int n = 2, m = 2;
	int a[n][m] = { { 2, 5 }, { 1, 7 } };
	int b[n][m] = { { 3, 7 }, { 2, 9 } };


	int c[n][m];
	for (int i = 0; i < n; i++)
	{
		for  ( int j = 0;  j  < n;  j ++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	cout << " ¬Û¥[ " << endl;
	//print matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}


	// Multiplication
	int d[n][m];
	int i, j, k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <n; j++)
		{
			c[i][j] = 0;
			for ( k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	cout << " ¬Û­¼ " << endl;
	//print matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}




	system("pause");
	return 0;
}




