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

#define MAX 1000
bool has[MAX + 1][2];


bool search(int x) {
	// searching if X is Present in the given array  or not.
	if (x >= 0 )
	{
		if (has[x][0]==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// If x is negative take the asbsolue value of x
	x = abs(x);
	if (has[x][1]==1)
	{
		return true;
	}
	return false;

}



void insert(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i]>=0)
		{
			has[arr[i]][0] = 1;
		}
		else
		{
			has[abs(arr[i])][1] = 1;
		}
	}
}

int main() {
	int a[] = { -1, 9, -5, -8, -5, -2 };
	int n = sizeof(a) / sizeof(a[0]);
	insert(a, n);

	int X = -5;
	if (search(X) == true)
		cout << "Present";
	else
		cout << "Not Present";

	system("pause");
	return 0;
}




