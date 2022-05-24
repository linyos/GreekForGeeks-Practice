#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>

using namespace std;



#define N 4

void  multiply(int mat1[][N],int mat2[][N],int res[][N])
{
	int i , j , k ;
	for (i = 0; i < N; i++)
	{
		for (j  = 0;  j< N; j++)
		{
			res[i][j] = 0 ;
			for ( k = 0; k < N; k++)
			{
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

}





void multiply(int m1, int m2, int mat1[][2], int n1, int n2, int mat2[][2])
{
	int x , i , j ;
	// m1 :2 , m2 : 2
	int res[2][2];

	for (i = 0; i < m1; i++)
	{
		for ( j = 0; j < m2; j++)
		{
			res[i][j] = 0 ; 
			for (x = 0 ; x < m2 ; x++)
			{
				*( *(res+ i) +j) += *(* ( mat1+i) + x )  *  *(*(mat2+x)  +j );
			}
		}
	}

	for ( i = 0; i < m1; i++)
	{
		for ( j = 0; j < n2; j++)
		{
			cout << * (*(res+i)+j) <<" ";
		}
		cout<<endl;
	}

}




int main()
{  

	 //int i, j;
  //  int res[N][N]; // To store result
  //  int mat1[N][N] = { { 1, 1, 1, 1 },
  //                     { 2, 2, 2, 2 },
  //                     { 3, 3, 3, 3 },
  //                     { 4, 4, 4, 4 } };
 
  //  int mat2[N][N] = { { 1, 1, 1, 1 },
  //                     { 2, 2, 2, 2 },
  //                     { 3, 3, 3, 3 },
  //                     { 4, 4, 4, 4 } };
 
  //  multiply(mat1, mat2, res);
 
  //  cout << "Result matrix is \n";
  //  for (i = 0; i < N; i++) {
  //      for (j = 0; j < N; j++)
  //          cout << res[i][j] << " ";
  //      cout << "\n";
  //  }



	int mat1[][2] = { { 2, 4 }, { 3, 4 } };
    int mat2[][2] = { { 1, 2 }, { 1, 3 } };
    int m1 = 2, m2 = 2, n1 = 2, n2 = 2;
   
    // Function call
    multiply(m1, m2, mat1, n1, n2, mat2);


	system("pause");
	return 0;
}