#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>


using namespace std;

//
//int maxLen(int arr[] , int n )
//{
//	// Initialize result
//	int max_len = 0 ;
//	 // Pick a starting point
//	for (int i = 0; i < n; i++)
//	{
//		//Initialize current sum for every starting point
//		int curr_sum =0 ;
//		for (int j = i; j < n; j++)
//		{
//			curr_sum += arr[j];
//
//			if (curr_sum==0)
//			{
//				/*
//				If curr_sum becomes 0 , 
//				then update max_len if required
//				subarray length : j-i + 1
//				*/
//				max_len =max(max_len , j- i+1);
//			}
//		}
//	}
//	 return max_len;
//}
//


int maxLen(int arr[] , int n )
{
	unordered_map<int , int> presum; 
	
	int sum = 0 ;
	int max_len = 0;



	for (int i = 0; i < n; i++)
	{
		sum	 += arr[i];
		if (arr[i]==0 && max_len==0)
		{
			max_len =1;
		}
		if (sum==0)
		{
			max_len = i+1;
		}

		if (presum.find(sum)!= presum.end())
		{
			max_len = max(max_len , i - presum[sum]);
		}
		else
		{
			presum[sum] = i ;
		}
	}

	return max_len;
}


int maxSubArrayLen(vector<int> arr)
{
	map<int ,int> hm ;
	hm[0] = 0 ;
	int length = -1;
	int cumSum = 0 ;

	for (int i = 0; i < arr.size(); i++)
	{
		cumSum = cumSum + arr[i];
		if (hm.find(cumSum) != hm.end())
		{
			length = max(length , i + 1 - hm[cumSum]);
		}
		else
		{
			
			hm[cumSum] = i+1;
			cout << cumSum<<" "<< hm[cumSum] << " " ; 
		}
	}
	return length;
}



int main ()
{	   int arr[] = { 15, 5,-2, 2, -8, 1, 7, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest 0 sum subarray is "
         << maxLen(arr, n);

	 system("pause");
	return 0 ;
}
