#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>

using namespace std;


int f(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1; 

	return f(n - 2) + f(n - 1);
}





int fib(int n)
{
	int F[10] = { 0 };
	F[0] = 0;
	F[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		F[i] = F[i - 2] + F[i - 1];
		
	}
	return  F[n];
}



int main() 
{
	cout << f(6) << endl;

	cout << fib(6) << endl;
	
	system("pause");
	return 0;
}


