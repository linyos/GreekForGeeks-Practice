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

#define N 4


void transpose(int A[][N], int B[][N])
{
	int i, j; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			B[i][j] = A[j][i];
		}
	}

}


int main() {

	int A[N][N] = { {1, 1, 1, 1},
					{2, 2, 2, 2},
					{3, 3, 3, 3},
					{4, 4, 4, 4} };

	int B[N][N] , i, j;


	transpose(A, B);

	cout << "Result matrix is: " << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j	 = 0; j < N; j++)
		{
			cout << B[i][j] << " ";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}




