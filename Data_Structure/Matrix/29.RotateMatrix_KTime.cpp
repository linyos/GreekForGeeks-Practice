#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>

using namespace std;

#define M 3
#define N 3
 



void rotateMatrix (int matrix[][M] , int k)
{
	int temp [M]; 
	k =k % M;


	for (int i = 0; i < N; i++)
	{
		// Copy first M-k elements to temporary array
		for (int t = 0; t < M-k ; t++)
		{
			temp[t] =matrix[i][t];
		}

		// Copy the elements from k to end to starting
		for (int j = M-k ; j < M; j++)
		{
			matrix[i][j-M+k] =matrix[i][j];
		}
		 // copy elements from temporary array to end
		for (int j = k; j < M; j++)
		{
			matrix[i][j] = temp[j-k];
		}
	}

}


void displayMatrix(int matrix[][M]) {
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout<<matrix[i][j] <<" ";
		}
		cout<<endl;
	}

}


int  main() {


	 int matrix[N][M] = {{12, 23, 34},
                     {45, 56, 67},
                     {78, 89, 91}};
  int k = 2;
 
  // rotate matrix by k
  rotateMatrix(matrix, k);
 
  // display rotated matrix
  displayMatrix(matrix);

	system("pause");
	return 0;
}



