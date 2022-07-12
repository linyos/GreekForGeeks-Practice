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
#include <bitset>

using namespace std;


// QuickSelect

void swap(int * a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int r)
{
	int x = arr[r]; 
	int j = l - 1;
	for (int i = l; i < r-1; i++)
	{
		if (arr[i] <= x)
		{
			swap(&arr[j], &arr[i]);
			j++;
		}
	}
	swap(&arr[j], &arr[r]);
	return j;
}



int kthSmallest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r-l+1)
	{
		int pos = partition(arr, l, r);

		if (pos-l == k-1)
		{
			return arr[pos];
		}
		if (pos-l > k-1)
		{
			return kthSmallest(arr, l, pos - 1, k);
		}
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}
	return INT_MAX;
}





int Kth_smallest(map<int, int> m, int k)
{
	int freq = 0;
	for (auto it= m.begin(); it != m.end() ; it++)
	{
		freq += it->second;
		
		if (freq >= k)
		{
			return it->first;
		}
	}
	return -1;
}





int kthSmallest1(int arr[], int n, int k)
{
	priority_queue <int> pq;
	for (int i = 0; i < k; i++)
	{
		pq.push(arr[i]);
	}
	for (int i = k; i < n; i++)
	{
		if (arr[i] < pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}
	return pq.top();
}

int main()
{
	int n = 5;
	int k = 2;
	vector<int> arr = { 12, 3, 5, 7, 19 };
	map<int, int> m;
	for (int i = 0; i < arr.size(); i++)
	{
		m[arr[i]]++;
	}

	int ans = Kth_smallest(m, k);
	if (k == 1) {
		cout << "The " << k << "st smallest element is " << ans
			<< endl;
	}
	else if (k == 2) {
		cout << "The " << k << "nd smallest element is " << ans
			<< endl;
	}
	else if (k == 3) {
		cout << "The " << k << "rd smallest element is " << ans
			<< endl;
	}
	else {
		cout << "The " << k << "th smallest element is " << ans
			<< endl;
	}

	int n1 = 10;
	int arr1[] ={ 10, 5, 4 , 3 ,48, 6 , 2 , 33, 53, 10 };
	int k1 = 4;
	cout << "Kth Smallest Element is: " << kthSmallest1(arr1, n1,  k1);



	system("pause");
	return 0;
}
