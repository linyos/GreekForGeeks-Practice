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
int  main() {
	int arr[] = {1, 2, 3, 4, 5, 6};

	int n = sizeof(arr) / sizeof(arr[0]);

	rvereseArray(arr, 0, n-1);
     
    cout << "Reversed array is" << endl;
     
    // To print the Reversed array
    printArray(arr, n);

	system("pause");
	return 0;
}



