#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Recursion
//int fib(int n)
//{
//	if (n <=1)
//	{
//		return n;
//	}
//	return fib(n - 1) + fib(n - 2);
//}



// Dyanmic programming

//const int n = 9;
//
//class GFG
//{
//public:
//	int fib(int m)
//	{
//		int f[n + 2];
//		int i;
//
//		f[0] = 0;
//		f[1] = 1;
//
//		for (i = 2;  i<= n  ;i ++)
//		{
//			f[i] = f[i - 1] + f[i - 2];
//		}
//		return f[n];
//	}
//
//};
//


// Method 3 (Space Optimized Method2 )


int fib(int n)
{
	int a = 0, b = 1, c, i;
	if (n==0)
	{
		return a;
	}
	for ( i = 2; i <= n ; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}


int main() 
{

	/*int n = 9;
	cout << fib(n);
	getchar();*/
	

	/*GFG g;
	
	cout << g.fib(n);*/

	int n = 9;
	cout << fib(n);

	system("pause");
	return 0;
}


