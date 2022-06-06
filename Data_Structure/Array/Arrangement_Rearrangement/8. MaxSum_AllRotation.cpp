#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>

using namespace std;




int maxSum (int arr[] , int n )
{
	int res = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		int curr_sum =0 ;

		for (int j = 0; j < n; j++)
		{
			int index = (i+j)%n;
			curr_sum += j*arr[index];
		}
		res = max(res , curr_sum);
	}
	return res; 
}

int maxSum1(int arr[] , int n )
{
	int cum_sum = 0 ;

	for (int i = 0; i < n; i++)
	{
		cum_sum += arr[i];
	}
	
	// cum_sum = 14
	int curr_val = 0 ;
	for (int i = 0; i < n; i++)
	{
		curr_val += i * arr[i];
	}
	
	// curr_val = 11;
	int res = curr_val;

	for (int i =1; i < n; i++)
	{

		int next_val = curr_val - (cum_sum - arr[i-1]) + arr[i-1] * (n-1);
		cout << curr_val <<" " 
			<< next_val << endl;
		curr_val = next_val;
		res = max(res , next_val);
	}
	return res;
}





int findPivot(int arr[] , int n )
{
	int i ;
	for (i = 0; i < n; i++)
	{
		if (arr[i] > arr[(i+1)%n])
		{
			return i;
		}
	}
}
int maxSum2 (int arr[] , int n )
{
	int sum = 0 ;
	int i ;
	int pivot = findPivot(arr , n );
	//cout << pivot ;
	  // difference in pivot and index of
    // last element of array
	int diff = n-1-pivot;


	for (int i = 0; i < n; i++)
	{
		sum = sum +((i + diff) %n ) * arr[i];
		cout << sum << endl; ;
	}
	return sum;
}



int main()
{ 



	 int arr[] = {8, 3, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
	
    //cout << maxSum(arr, n) << endl;
	//cout << maxSum1(arr, n) << endl;

	cout << maxSum2(arr, n) << endl;
	system("pause");
	return 0;
}