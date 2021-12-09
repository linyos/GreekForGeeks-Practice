#include <iostream>
#include <algorithm>


using namespace std ;

#define SIZE 10





void sortMat (int mat[SIZE][SIZE] , int n ){
	int temp[ 3*3 ];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[k++] = mat[i][j];
		}
	}

	sort(temp  , temp+k);

	k=0 ;
	for (int i = 0; i < n; i++)
	{
		for (int j= 0; j < n; j++)
		{
			mat[i][j] = temp[k++];
		}
	}
}

void printMat(int mat[SIZE][SIZE] , int n ){

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<<mat[i][j] <<" " ;
		}
		cout<<endl;
	}

}




int main ()
{
	 int mat[SIZE][SIZE] = { { 5, 4, 7 },
                            { 1, 3, 8 },
                            { 2, 9, 6 } };
    int n = 3;
 
    cout << "Original Matrix:\n";
    printMat(mat, n);
 
    sortMat(mat, n);
 
    cout << "\nMatrix After Sorting:\n";
    printMat(mat, n);
	system("pause");
	return 0 ;
}