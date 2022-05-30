#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;




int binomialCoeff(int n, int k)
{
	if (k > n) return 0;

	if (k == 0 || k == n) return 1;


	return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}


int min(int a, int b)
{
	return (a < b) ? a : b;
}


int  binomialCoeffDP(int n, int k)
{
	// n = 5 k =2
	int C[5 + 1][2 + 1];
	int i, j;

	for  (i = 0; i <= n; i++)
	{
		for ( j = 0; j <=  min(i , k); j++)
		{
			if (j==0 || j==i)
			{
				C[i][j] = 1;
			}
			else
			{
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}
	return C[n][k];
}



int binomialCoeffDP1(int n, int k)
{
	// k =2
	int C[2 + 1];

	//C畐ㄧ计 void *memset(void *str, int c, size_t n)
	//狡籹才cunsigned char摸把计str才﹃玡n才
	memset(C, 0, sizeof(C));

	C[0] = 1; 

	for (int i = 1; i <= n  ; i++)
	{
		for (int j = min(i , k); j > 0 ; j--)
		{
			cout <<"i: "<<i << " j: "<< j;
			C[j] = C[j] + C[j - 1];
			cout << " C[j]  " << C[j] << endl;
			
		}
	}
	return C[k];
}


int main() 
{

	int n = 5, k = 2;
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k) << endl;
	
	
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeffDP1(n, k) << endl;
	system("pause"); 
	return 0;
}


