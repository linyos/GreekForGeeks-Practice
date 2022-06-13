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
#include <ctime>
#include <time.h>


using namespace std;



// Method recursive
bool isSubsetSum(int arr[] , int n , int sum)
{
	// Base cases;
	if (sum ==0)
		return true;
	if (n== 0 && sum != 0)
		return false;
	// If last element is greater than sum, then ignore it
	if (arr[n-1] > sum)
	{
		return isSubsetSum(arr ,n-1 , sum);
	}

	return isSubsetSum(arr , n-1 , sum ) || isSubsetSum(arr , n-1 , sum-arr[n-1]);
}


// Return true if arr[] can be partition in two subset of equal sum
bool findPartiion(int arr[] , int n )
{

	int sum = 0 ;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	// If sum is odd, there cannot be two subsets
	// with equal sum
	if (sum %2 != 0)
		return false;
	// Find if there is subset with sum equal to
	// half of total sum
	return isSubsetSum(arr , n , sum/2);
}



// Method 2 : DP 
bool isSubsetSum2 (int arr[] , int n , int sum , vector<vector<int>> &dp)
{
	// Base Cases
	if (sum == 0)
		return true;
	if (n==0 && sum != 0)
		return false;


	if (dp[n][sum] != -1)
	{
		return dp[n][sum];
	}


	if (arr[n-1] > sum)
		return isSubsetSum2(arr , n-1 , sum , dp);
	
	return dp [n][sum] = isSubsetSum2(arr ,n-1 , sum ,dp )|| isSubsetSum2(arr , n-1 , sum-arr[n-1] , dp);
}

bool findPartiion2(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];


	if (sum %2 !=0)
		return false;



	 // To store overlapping subproblems
	vector<vector<int>> dp (n+1 , vector<int> (sum+1 , -1));


	return isSubsetSum2(arr , n , sum/2 , dp);
}



int main()
{  
		int arr[] = { 3, 1, 5, 9, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	if (findPartiion(arr, n) == true)
		cout << "Can be divided into two subsets "
				"of equal sum";
	else
		cout << "Can not be divided into two subsets"
				" of equal sum";


    int arr2[] = { 3, 1, 5, 9, 14 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    if ( findPartiion2(arr2, n2) == true)
        cout << endl
             << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << endl
             << "Can not be divided into two subsets"
                " of equal sum";

	system("pause");
	return 0;
}