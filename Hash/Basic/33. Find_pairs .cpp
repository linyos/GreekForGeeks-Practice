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
#include <ctime>
#include <time.h>
#include <stack>


using namespace std;
const int MAX = 100;



// Method : Function to find pair for given sum in matrix 
// mat[][] --> given matrix
// n --> order of matrix
// sum --> given sum for which we need to find pair
void pairSum(int mat[][MAX], int n, int sum)
{
	for (int i = 0; i < n; i++)
		sort(mat[i] , mat[i]+n);
	
	/*
	1 2 3 4
	5 6 7 8
	9 10 11 13
	0 12 14 15
	*/
	// Select i'th row and find pair for element in i'th
	// row in j'th row whose summation is equal to given sum


	for (int i = 0; i < n-1; i++)
	{
		for (int j =  i+1; j < n; j++)
		{
			int left=0 , right = n-1;
			while (left < n && right >= 0 )
			{
				if ((mat[i][left] + mat[j][right]) == sum )
				{
					cout << "(" << mat[i][left] << ", "<< mat[j][right] << "), ";
					left++, right-- ;
				}
				else
				{
					if ((mat[i][left] + mat[j][right] ) < sum )
					{
						left ++;
					}
					else
					{
						right--;
					}
				}
			}
		}
	}

}



// Function to find pair for given sum in matrix
// mat[][] --> given matrix
// n --> order of matrix
// sum --> given sum for which we need to find pair
void pairSum3(int mat[][MAX], int n, int sum)
{
	unordered_map <int , int > hm;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int remSum = sum- mat[i][j];
			auto it = hm.find(remSum);

			// If an element with value equal to remaining sum exists
			if (it != hm.end())
			{
				// Find row numbers of element with
				// value equal to remaining sum.
				int row = hm[remSum];
				// If row number of pair is not same as current
				// row, then print it as part of result.
				// Second condition is there to make sure that a
				// pair is printed only once.
				if (row < i)
				{
					cout << "(" << mat[i][j] << ", " << remSum << "), ";
				}
			}
			hm[mat[i][j]]= i;
		}
	}


}

int main()
{  

	int n = 4, sum = 11;
	int mat[][MAX] = {{1, 3, 2, 4},
					{5, 8, 7, 6},
					{9, 10, 13, 11},
					{12, 0, 14, 15}};

	cout << "Using Hash: " << endl;
	pairSum(mat, n, sum);
	cout<<endl;


	cout << "Using Hash: " << endl;
		pairSum3(mat, n, sum);
	system("pause");
	return 0;
}