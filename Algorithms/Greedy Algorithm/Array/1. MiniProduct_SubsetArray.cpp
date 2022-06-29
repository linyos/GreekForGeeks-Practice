#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;


int minProductSubset(int a[], int n)
{
	if (n == 1)
		return a[0];

	int max_neg = INT_MIN, min_pos = INT_MAX;
	int count_neg = 0, count_zero = 0, prod = 1;

	for (int i = 0; i < n; i++)
	{
		// If number is 0, we don't multiply it with
	   // product.
		if (a[i]==0)
		{
			count_zero++;
			continue;
		}
		// Count negatives and keep track of maximum valued  negative.
		if (a[i] < 0 )
		{
			count_neg++;
			max_neg = max(max_neg, a[i]);
		}
		// Track mini positive number of array.
		if (a[i] > 0 )
		{
			min_pos = min(min_pos, a[i]);
		}
		prod = prod * a[i];
	}
	// If there are all zeros or no negative number present
	if (count_zero ==n || (count_neg==0) )
	{
		return 0;
	}
	// If there are all positive
	if (count_neg==0)
	{
		return min_pos;
	}

	cout << !(count_neg & 1) << endl;

	// count_neg ¬°°¸¼Æ 
	if (!(count_neg & 1) && count_neg!= 0 )
	{
		prod = prod / max_neg;
	}
	return prod;

}


int main()
{
	int a[] = { -1, - 1,- 2 ,-3, 4,3 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << minProductSubset(a, n) << endl; 


	
	system("pause");
	return 0;
}
