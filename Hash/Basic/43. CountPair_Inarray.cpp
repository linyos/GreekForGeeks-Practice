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
#include <stack>


using namespace std;


// Method 1: simple 
int countPairs (int arr[] , int n )
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n ; j++)
		{
			int product= arr[i] * arr[j];

			for (int k = 0; k < n; k++)
			{
				if (arr[k] == product)
				{
					cout <<"["<<arr[i] << ","<<arr[j] <<"]" <<endl;
					result ++ ;
					break;
				}
			}
		}
	}
	return result;
}


// Method 2 : efficient
int countPairs2(int arr[] , int n)
{
	int result = 0 ;
	// Create an empty hash-set that store all array element
	set <int> Hash;
	// Insert all array element into set
	for (int i = 0; i < n; i++)
		Hash.insert(arr[i]);
	

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			int product = arr[i]*arr[j];
			if (Hash.find(product) != Hash.end())
			{
				cout <<"["<<arr[i] << ","<<arr[j] <<"]" <<endl;
				result++ ; 
			}
		}
	}
		// return count of pairs whose product exist in array
	return result;

}



int main()
{  

	int arr[] = {6 ,2 ,4 ,12 ,5 ,3} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	//cout << countPairs(arr, n);
	
	cout << countPairs2(arr, n);


	system("pause");
	return 0;
}