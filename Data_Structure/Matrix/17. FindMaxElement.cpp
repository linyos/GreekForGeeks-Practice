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



const int Row = 4;
const int Col = 4;

void printArray(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << endl;
	}
}



void maxelement( int arr[][Row])
{
	int i = 0;
	int max = 0; 
	 int res[Col];
	 while (i < Col)
	 {
		 for (int j = 0; j < Row; j++)
		 {
			 if (arr[i][j] > max)
			 {
				 max = arr[i][j];
			 }
		 }
		 res[i] = max;
		 max = 0;
		 i++;
	 }
	printArray(res, Col);
}


int main() {

	int arr[Col][Row] = { {3, 4, 1, 8},
					   {1, 4, 9, 11},
					   {76, 34, 21, 1},
					   {2, 1, 4, 5} };

	maxelement( arr);
	system("pause");
	return 0;
}




