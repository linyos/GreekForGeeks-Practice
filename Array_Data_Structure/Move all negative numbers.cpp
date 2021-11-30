#include<iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>





using namespace std;

//void rearrange(int arr[], int n){
//	int j = 0 ;
//	for (int i = 0; i < n; i++)
//	{
//		// negative number 
//		if (arr[i] < 0 )
//		{
//			if (i != j )
//			{
//				swap (arr[i] , arr[j]);
//			}
//			j++;
//		}
//	}
//}
//void printArray(int arr[], int n)
//{
//    for (int i = 0; i < n; i++)
//        printf("%d ", arr[i]);
//}
 



void  shiftall (int arr[] , int left ,int right){
	while (left <= right)
	{
		if (arr[left] < 0 && arr [right] < 0  )
		{
			left ++ ;
		}
		else if (arr[left] > 0 && arr[right] < 0)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right]= temp ;
			left ++ ;
			right-- ;
		}
		else if (arr[left] > 0 && arr[right] > 0)
		{
			right--;
		}
		else
		{
			left ++ ;
			right -- ;
		}

	}





}



void display (int arr[] , int right ){

	for (int i = 0; i <= right ; i++)
	{
		cout<<arr[i] <<" " ;
	}
	cout<<endl;
}



int main()
{
	//int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
 //   int n = sizeof(arr) / sizeof(arr[0]);
 //   rearrange(arr, n);
	//printArray(arr, n);
	//

	  int arr[] = {-12, 11, -13, -5,
               6, -7, 5, -3, 11};
  int arr_size = sizeof(arr) /
                sizeof(arr[0]);
   
  // Function Call
  shiftall(arr,0,arr_size-1);
  display(arr,arr_size-1);
  
	system("pause");
    return 0;                           
}