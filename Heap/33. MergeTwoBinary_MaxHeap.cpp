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




void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



void maxHeapify(int arr[] , int n , int i)
{
	if (i > n ) return ;

	int l = 2 * i +1 ;
	int r = 2* i + 2;
	int max = i ;

	if (l < n && arr[l] > arr[max])
	{
		max = l ;
	}

	if (r<n && arr[r]> arr[max])
	{
		max = r;
	}

	if (max != i)
	{
		swap(arr[i],arr[max]);
		maxHeapify(arr ,n , max);
	}

}


void buildMaxHeap(int arr[] , int n )
{
	for (int i = n/2-1; i >=0 ; i--)
	{
		maxHeapify(arr , n , i );
	}

	for (int i = n-1; i > 0; i-- )
	{
		swap(arr[0] , arr[i]);
		maxHeapify(arr  , i , 0);
	}


}



void mergeHeaps(int merged[] , int a[] , int b [] , int n , int m)
{
	for (int i = 0; i < n; i++)
	{
		merged[i] = a[i];
	}
	for (int i = 0; i < m; i++)
	{
		merged[n+i] = b[i];
	}
	
	buildMaxHeap(merged ,n+m);
}



int main()
{ 
	 
	int a[] = { 10, 5, 6, 2 };
    int b[] = { 12, 7, 9 };
 
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
 




	////n = 4 , m=3
   int merged[7];

    mergeHeaps(merged, a, b, n, m);
	
	printArray(merged , (n+m));

 /*

    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";*/
 


	
	system("pause");
	return 0;
}