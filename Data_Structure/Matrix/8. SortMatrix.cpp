#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


const int M = 3;


void sortMat(int mat[M][M])
{
	
	int temp[M * M];
	int k = 0; 

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp[k++] = mat[i][j];
		}
	}


	sort(temp, temp + k);

	// Copy the element of temp[] one by one in mat[][]
	k = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			mat[i][j] = temp[k++];
		}
	}


}

void printMat(int mat[M][M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}



/*
----------------------<補充>二維指標陣列用法------------------
*/

// Method 1: 
void printMat1(int *mat)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << *(mat+i+j) << " ";
		}
		cout << endl;
	}
}

// Method 2: 
void printMat2(int (&mat)[M][M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout <<mat[i][j] << " ";
		}
		cout << endl;
	}
}
// Method 3: 
void printMat3(int** mat)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}






int main() {
	
	int mat[M][M] = { { 5, 4, 7 },
					  { 1, 3, 8 },
					  { 2, 9, 6 } };



	printf("%s", "Original Matrix:\n");
	printMat(mat);
	sortMat(mat);
	printf("%s", "Matrix After Sorting:\n");
	printMat(mat);


	cout << "========================" << endl;
	// 一維指標
	cout << "One Dimensional array " << endl;
	
	int a1[3] = { 1,2,3 };
	int * ptr = &a1[0];
	for (int i = 0; i < 3; i++)
	{
		cout << *(ptr + i) << " ";
	}
	cout << endl;


	// 二維指標
	cout << "Two Dimensional array " << endl;
	int a2[2][3] = { {1,2,3},{4,5,6} };
	
	ptr = &a2[0][0];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *(ptr + i + j) << " ";
		}
		cout << endl;
	}
	cout << endl;





	printf("%s", " Method 1:\n");
	// Method 1 單指標
	//int *p1= &mat[0][0];
	printMat1(&mat[0][0]);

	// Method 2: // 地址接收
	//int (&mat)[M][M] = mat
	printf("%s", " Method 2:\n");
	printMat2(mat);

	// Method 3:   雙指標
	// int** mat=int *p[3] = { mat[0],mat[1] , mat[2] };
	

	printf("%s", " Method 3:\n");
	 // p有兩個元素，每個元素都是一個指標(從右邊看)
				// *p[2]= {v[0] , v[1]}
				// *p[2]= {&v[0][0] , v[1][0]}
	           // (int **) = (int * [2])  
			//&p[0] // (int **) = (int **)
	int *p[3] = { mat[0],mat[1] , mat[2] };
	printMat3(p);
	




	system("pause");
	return 0;
}




