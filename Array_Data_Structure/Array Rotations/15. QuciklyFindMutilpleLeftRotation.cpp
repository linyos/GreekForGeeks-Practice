#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include<cassert>
#include <set>
#include <map>

using namespace std;








void leftRotate(int arr[] , int n , int  k )
{
	// To get the starting point of rotate array;
	int mod =  k % n;
	for (int i = 0; i < n; i++)
	{
		cout << arr[(mod+i) % n ] <<" ";
	}
	cout << endl;
}

void leftRotate1(int arr[] , int n , int  k )
{
	
	for (int i = k; i < k + n; i++)
	{
		cout << arr[i % n] << " " ;
	}
	cout << endl;
}



void leftRotate2(int* arr , int n , int  k )
{
	int mod = k % n;
	for (int i = 0; i < n; i++)
	{
		cout << * (arr+((mod+i)%n)) <<" ";
	}
}

int  main() {
	int arr [] = {1,3,5,7,9};
	int n  = sizeof(arr) / sizeof(arr[0]);

	int k = 2; 

	cout<<"Mtehod1: " <<endl; 

	leftRotate(arr, n, k);


	cout<<"Mtehod2: " <<endl; 
	leftRotate1(arr, n, k);



	int * p = arr;
	cout<< "Method 3 : Using pointer "<<endl;
	leftRotate2(p , n, k );


	system("pause");
	return 0;
}



