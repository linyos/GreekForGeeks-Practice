#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using	namespace std;



//Method 1 (Simple) 
//void findMissing(int a[], int b[], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		int j; 
//		for ( j = 0; j < m; j++)
//		{
//			if (a[i]==b[j])
//			{
//				break;
//			}
//		}
//		if (j==m)
//		{
//			cout << a[i] << " ";
//		}
//	}
//}


void findMissing(int a[], int b[], int n, int m) {
	unordered_set<int> s;
	for (int i = 0; i < m; i++)
	{
		s.insert(b[i]);
	}
	
	for (int i = 0; i < n; i++)
	{
		if (s.find(a[i])==s.end())
		{
			cout << a[i] << " ";
		}
	}

}



int main()
{
	int a[] = { 1, 2, 6, 3, 4, 5 };
	int b[] = { 2, 4, 3, 1, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	int m = sizeof(b) / sizeof(b[1]);
	findMissing(a, b, n, m);
	system("pause");
	return 0;
	
}


