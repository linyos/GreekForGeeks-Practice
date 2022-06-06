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
	// Find array sum and i*arr[i] with no rotation
	int arrSum = 0 ;  // Stores sum of arr[i]
	int currVal = 0 ; // Stores sum of i*arr[i]


	for (int i = 0; i < n; i++)
	{
		arrSum  += arr[i];
		currVal += (i * arr[i]);
	}

	int maxVal =currVal;
	
	 // Try all rotations one by one and find
    // the maximum rotation sum.
	for (int i = 1; i < n; i++)
	{
		currVal += arrSum - n *arr[n-i];
		if (currVal > maxVal)
		{
			maxVal = currVal;
		}
	}
	return maxVal;
}





int main()
{ 


	int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nMax sum is " << maxSum(arr, n);
 
	
	system("pause");
	return 0;
}