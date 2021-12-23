#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;



#define N 4 

void shiftMatrixByK(int m[N][N] , int k){

	if (k> N)
	{
		cout<<"Shifting is not possible " <<endl;
		return;
	}

	int j =0 ;
	while (j < N)
	{
		for (int i = k; i < N; i++)
		{
			cout<< m[j][i] <<" ";
		}
		for (int i = 0; i < k; i++)
		{
			cout<<m[j][i] <<" ";
		}
		cout<<endl;
		j++;
	}
}


int main(){

    int mat[N][N] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    int k = 2;
     
    // Function call
    shiftMatrixByK(mat, k);

	system("pause");
	return 0;
}