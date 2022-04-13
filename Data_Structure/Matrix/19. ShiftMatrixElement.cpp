#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int Size = 26;


#define N 4 

void shiftMatrixByK(int mat[N][N], int  k)
{
	if (k > N)
	{
		cout << "shifting is not possible" << endl;
		return;
	}

	int j = 0;
	while (j < N )
	{
		// print element form index k
		for (int i = k; i < N; i++)
		{
			cout << mat[j][i] << " ";
		}

		// print elements before index k
		for (int i = 0; i < k; i++)
		{
			cout << mat[j][i] << " ";
		}

		cout << endl;
		j++;
	}
}






int main() {
	
	int mat[N][N] = { {1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {9, 10, 11, 12},
				   {13, 14, 15, 16} };
	int k = 1;

	//// Function call
	shiftMatrixByK(mat, k);




	system("pause");
	return 0;
}




