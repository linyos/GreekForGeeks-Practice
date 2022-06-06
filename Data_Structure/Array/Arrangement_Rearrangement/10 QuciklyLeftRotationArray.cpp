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



void preprocess (int arr[] , int n , int temp[])
{
	// Store arr[] elements at i and i + n
	for (int i = 0; i < n; i++)
	{
		/*temp[i] = arr[i];
		temp[i + n ] = arr[i];*/
		temp[i] = temp[i+n] = arr[i];
	}
}


void leftRotate(int arr[] , int n , int k , int temp[])
{
	int start = k % n ;
	for (int i = start; i < start +  n ; i++)
	{
		cout << temp[i] <<" ";
	}
	cout <<endl;
}



int main()
{ 
	  int arr[] = {1, 3, 5, 7, 9};
    const int n = sizeof(arr) / sizeof(arr[0]);
 
    int temp[2*n];
    preprocess(arr, n, temp);
	 int k = 2;
    leftRotate(arr, n, k, temp);
 
    k = 3;
    leftRotate(arr, n, k, temp);
 
    k = 4;
    leftRotate(arr, n, k, temp);
 

	system("pause");
	return 0;
}