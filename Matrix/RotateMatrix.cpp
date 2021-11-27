#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using	namespace std;

//#define N 4

#define R 4
#define C 4 




// Method 1.
void rotateMatrix(int mat[N][N]) {
	for (int i = N-1; i >=0  ; i--){
		for (int j = N-1; j  >=0 ; j--)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


// Method 2.

// Function to rotate the matrix by 180 degree.
void reverseColumn(int arr[R][C]) {
	for (int i = 0; i < C; i++){
		for (int j = 0 , k = C-1; j < k ; j++ , k -- )
		{
			swap(arr[j][i], arr[k][i]);
		}
	}
}
void transpose(int arr[R][C]) {
	for (int i = 0; i < R; i++){
		for (int j = i; j < C; j++){
			swap(arr[i][j], arr[j][i]);
		}
	}
}
void printMatrix(int arr[R][C]) {
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}
void rotate180(int arr[R][C]) {
	transpose(arr);
	reverseColumn(arr);
	transpose(arr);
	reverseColumn(arr);
}



//Method 3. 

void  reverseRow(vector<vector <int>> & data, int index) {
	int cols = data[index].size();
	for (int i = 0; i < cols / 2; i++) {
		int temp = data[index][i];
		data[index][i] = data[index][cols - i - 1];
		data[index][cols - i - 1] = temp;
	}
}

void printMatrix(vector<vector<int>>& data) {
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}


void rotateMatrix180(vector<vector<int>> & data) {
	int rows = data.size();
	int cols = data[0].size();

	if (rows % 2 != 0)
	{
		// If N is odd reverse the middle row in hthe matrix 
		reverseRow(data, data.size() / 2);
	}

	for (int i = 0; i <= (rows / 2) - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int tmp = data[i][j];
			data[i][j] = data[rows - i - 1][cols - j - 1];
			data[rows - i - 1][cols - j - 1] = tmp;
		}
	}


}


int main()
{
	/*int mat[N][N] = {
	   { 1, 2, 3 },
	   { 4, 5, 6 },
	   { 7, 8, 9 }
	};*/


	//int arr[R][C] = {
 //  { 1, 2, 3, 4},
 //  { 5, 6, 7, 8},
 //  { 9, 10, 11, 12},
	//{13, 14, 15, 16}
	//};
	////rotateMatrix(mat);

	//rotate180(arr);
	//printMatrix(arr);




	vector <vector <int>> data{ { 1, 2, 3, 4, 5 },
							  { 6, 7, 8, 9, 10 },
							  { 11, 12, 13, 14, 15 },
							  { 16, 17, 18, 19, 20 },
							  { 21, 22, 23, 24, 25 } };
	// Rotate Matrix
	rotateMatrix180(data);

	// Print Matrix
	printMatrix(data);


	system("pause");
	return 0;
}