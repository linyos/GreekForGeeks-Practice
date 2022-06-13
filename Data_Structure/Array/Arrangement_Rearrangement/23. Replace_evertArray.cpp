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



void modify(int arr[] , int n)
{
	if ( n <=1)
	{
		return ;
	}
	int prev = arr[0];
	arr[0] = arr[0] * arr[1];

	// arr[1...n-1]
	// arr[3,4,5]
	
	for (int i = 1; i < n-1; i++)
	{
		int curr = arr[i];

		arr[i] = prev * arr[i+1];

		prev = curr;
	}

	arr[n-1] = prev * arr[n-1];
}


void printArr (int arr[] ,int n )
{
	for (int i = 0; i < n; i++)
	{
		cout<< arr[i] <<" ";
	}
	cout<<endl;
}

int main()
{  
	int arr[] = {2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	modify(arr, n);
	printArr (arr , n);
  
	system("pause");
	return 0;
}