#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
using namespace std;




// Method 1 : Iterative 
//void rvereseArray(int arr[] , int start , int end)
//{
//	while (start< end)
//	{
//		int temp = arr[start];
//		arr[start] = arr[end];
//		arr[end] = temp ;
//		start++;
//		end--;
//	}
//}


void printArray(int arr[] , int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i] <<" ";
	}
	cout<<endl;
}




// Method : recursive
void rvereseArray(int arr[], int start, int end)
{
	if (start >= end) return ;

	int temp  = arr[start];
	arr[start] = arr[end];
	arr[end]  = temp;

	rvereseArray(arr , start+1 , end-1);
}


// Method : Recursive by pointer 



void reverseArray (int *arr , int * l , int *r)
{
	if (*l >= *r) return ;

	int temp = *(arr + *l);
	*(arr + *l) = *(arr + *r);
	*(arr + *r) = temp ; 
	l++ ;
	r-- ;
	reverseArray (arr ,  l , r);

}

int  main() {
	int arr[] = {1, 2, 3, 4, 5, 6};

	int n = sizeof(arr) / sizeof(arr[0]);

	// Metrhod : recursive
	//rvereseArray(arr, 0, n-1);
    


	// Method : revursive by pointer 
	int l = 0 ;
	int r= n-1;
	reverseArray(arr ,&l , &r );
    cout << "Reversed array is" << endl;
     





    // To print the Reversed array
    printArray(arr, n);

	system("pause");
	return 0;
}



