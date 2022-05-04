#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
using namespace std;



// Method 1 
int kthSmallest(int arr[], int n, int k)
{
	sort(arr , arr+ n );
	return arr[k-1];
}









void Swap (int * a , int * b)
{
	int temp = *a;
	*a = * b;
	*b = temp;
}


int partition (int arr[] , int l ,int r)
{
	int x = arr[r] ;
	int i = l;

	for (int j = l; j < r; j++)
	{
		if (arr[j] <= x)
		{
			Swap(&arr[i] ,&arr[j]);
			i++;
		}
	}
	Swap(&arr[i] , &arr[r]);
	return i ;

	
}


int kthSmallest(int arr[], int l, int r, int k)
{


	if (k > 0 && k <= r-l+1)
	{
		int pos = partition(arr,l , r);
		if (pos -l== k -1)
		{
			return arr[pos];
		}
		if (pos-l > k-1)
		{
			return kthSmallest(arr  , l ,pos-1 , k);
		}
		return kthSmallest(arr, pos+1 , r , k-pos+l -1);
	}

	return INT_MAX;
}




int  main() {
	// Method 1. 
	/* int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k);*/
 

	// Method 2
	/*int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

	set<int> s (arr, arr+n);
	set<int> ::iterator itr= s.begin();

	advance(itr , k-1);
	cout<< * itr<< " \n";*/




	   int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);

	
	system("pause");
	return 0;
}



