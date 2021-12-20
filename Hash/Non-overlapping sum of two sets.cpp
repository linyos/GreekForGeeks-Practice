#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
#include <unordered_map>
using	namespace std;





int findSum(int A[], int B[], int n) {
	unordered_map <int, int > hash;
	for (int i = 0; i < n; i++)
	{
		hash[A[i]]++;
		hash[B[i]]++;
	}
	int sum = 0;
	for (auto x : hash)
	{
		if (x.second==1)
		{
			sum += x.first;
		}
	}

	return sum;
}



int main()
{
	int A[] = { 5,4,9,2,3 };
	int B[] = { 2, 8, 7, 6, 3 };

	int n = sizeof(A) / sizeof(A[0]);

	// function call
	cout << findSum(A, B, n);
	system("pause");
	return 0;
	
}


