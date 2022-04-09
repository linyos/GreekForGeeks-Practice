#include <iostream>
#include <queue>
using namespace std;







void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}





void swap (int arr[] , int fi , int si , int d )
{
	int i ,  temp ;
	for ( i = 0; i < d; i++)
	{
		temp = arr[fi + i];
		arr[fi + i] = arr[si + i];
		arr[si + i ]= temp ;
	}
}




void leftRotate(int arr[], int d, int n)
{
	if (d==0 || d == n)
	{
		return ;
	}
	// If number of elements to be rotated is more than array size
	if (d>n)
	{
		d = d % n ;
	}

	// If number of elements to be rotated is exactly half of array size
	if (n-d ==d)
	{
		swap (arr , 0 , n-d , d);
		return ;
	}
	// If A is shorter
	if (d < n-d)
	{
		swap(arr, 0 , n-d , d);
		leftRotate(arr , d , n-d);
	}
	else// If B is shorter
	{
		swap(arr , 0 , d ,n-d);
		leftRotate(arr + n-d , 2*d -n ,d);/*This is tricky*/
	}



}
int  main() {
	 int arr[] = {1, 2, 3, 4, 5, 6, 7,8};
    leftRotate(arr, 2, 8);
    printArray(arr, 8);
	system("pause");
	return 0;
}






