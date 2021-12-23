#include <iostream>
#include <string>
#include <list>
using namespace std;


const int MAX= 100;

void middlesum(int mat[][MAX] , int n){
	
	int row_sum = 0 , col_sum = 0;

	for (int i = 0; i < n; i++)
	{
		row_sum += mat[n/2][i];

	}

	cout<<"Sum of middle row = " << row_sum<<endl;


	for (int i = 0; i < n; i++)
	{
		col_sum += mat[i][n/2];
	}
	cout <<"Sum of middle column= " <<col_sum <<endl;
}







int main(){

	 int mat[][MAX] = {{2, 5, 7},
                     {3, 7, 2},
                     {5, 6, 9}};
     
    middlesum(mat, 3);
	
	system("pause");
	return 0;
}