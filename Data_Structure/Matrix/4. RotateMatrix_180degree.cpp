#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
using namespace std;

# define N 3

#define R 4
#define C 4

// Method 1 (Only prints rotated matrix)
void rotateMatrix(int mat[][N])
{
	for (int i = N-1; i >= 0  ; i--)
	{
		for (int j = N-1; j >=0 ; j--)
		{
			printf("%d " , mat[i][j]);
		}
		printf("\n");
	}

}



// Method 2 
void reverseColumns(int arr[R][C])
{
	for (int i = 0; i < C; i++)
	{
		for (int j = 0 , k = C-1; j < k ; j++ , k--)
		{
			swap(arr[j][i] , arr[k][i]);
		}
	}
}



void transpose(int arr[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = i; j < C; j++)
		{
			swap(arr[i][j] , arr[j][i]);
		}
	}
}

void printMatrix(int arr[R][C])
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
 



void rotate180(int arr[R][C])
{
	transpose(arr); //90 degree
	reverseColumns(arr);
	transpose(arr); //90 degree
	 reverseColumns(arr);
}






/// Method 

/**
 * Reverse Row at specified index in the matrix
 * @param data matrix
 * @param index row index
 */
void reverseRow(vector <vector<int>> & data , int index)
{
	int cols =data[index].size();
	for (int i = 0; i < cols/2; i++)
	{
		int temp  =data[index][i];
		data[index][i] = data[index][cols-i-1];
		 data[index][cols-i-1] = temp;
	}
}


void printMatrxi (vector<vector<int>> & data)
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data.size(); j++)
		{
			cout<< data[i][j] <<" ";
		}
		cout<<endl;
	}

}



void rotateMatrix180(vector<vector<int>>& data)
{
	int row = data.size();
	int col = data[0].size();


	if (row % 2 != 0)
	{
		// If N is odd reverse the middle
		// row in the matrix
		 // 先轉中間列，中間列只需要reverse 一次
		reverseRow(data, data.size()/2);
	}
	// Swap the value of matrix [i][j] with
    // [rows - i - 1][cols - j - 1] for half    
    // the rows size.
	for (int i = 0; i <= (row/2)-1; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int temp = data[i][j];
			data[i][j] = data[row-i-1][col-j-1];
			data[row-i-1][col-i-1] = temp;
		}
	}


}


int main ()
{
	 //int mat[N][N] = {
  //      { 1, 2, 3 },
  //      { 4, 5, 6 },
  //      { 7, 8, 9 }
  //  };
 
  //  rotateMatrix(mat);

	//int arr[R][C] = { { 1, 2, 3, 4 },
 //                     { 5, 6, 7, 8 },
 //                     { 9, 10, 11, 12 },
 //                     { 13, 14, 15, 16 } };
 //   rotate180(arr);
 //   printMatrix(arr);


	  vector<vector<int>> data{ { 1, 2, 3, 4, 5 },
                              { 6, 7, 8, 9, 10 },
                              { 11, 12, 13, 14, 15 },
                              { 16, 17, 18, 19, 20 },
                              { 21, 22, 23, 24, 25 } };


	 rotateMatrix180(data);
 
    // Print Matrix
    printMatrix(data);


	system("pause");
	return 0 ;
}
