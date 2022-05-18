#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>

using namespace std;

void reorder(int arr[], int index[], int n)
{
	
	int temp[5];

	for (int i = 0; i < n; i++)
	{
		temp[index[i]] = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
		index[i] = i;
	}
}




void reorder (int arr[] , int index [] , int n)
{
	for (int i = 0; i < n; i++)
	{
		while (index[i] != i)
		{
			int oldTargetI = index[index[i]];
			int oldTargetE = arr[index[i]];

			arr[index[i]] = arr[i];
			index[index[i]] = index[i];


			arr[i] =oldTargetE ;
			index[i] = oldTargetI;
		}
	}
}



int heapSize;
void swap(int &a , int &b)
{
	int temp= a ;
	a= b;
	b= temp;
}


void heapify(int arr[] , int index[] , int i)
{
	int largest = i ;
	int left = 2 * i +1 ;
	int right = 2 * i +2 ;

	if (left< heapSize && index[left] > index[largest])
	{
		largest = left;
	}
	if (right <heapSize && index[right] > index[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(arr[largest] , arr[i]);
		swap(index[largest] , index[i]);
		heapify(arr , index , largest);
	}
}



void heapSort(int arr[] , int index[] , int n )
{
	for (int i = (n-1)/2; i >= 0 ; i--)
	{
		heapify(arr , index , i);
	}

	for (int i =  n-1; i >0  ; i--)
	{
		swap(index[0] , index[i]);
		swap(arr[0] , arr[i]);
		heapSize--;
		heapify(arr, index , 0);

	}
}




int main() {
	int arr[] = { 50, 40, 70, 60, 90 };
	int index[] = { 3,  0,  4,  1,  2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	reorder(arr, index, n);

	cout << "Reordered array is: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << "\nModified Index array is: \n";
	for (int i = 0; i < n; i++)
		cout << index[i] << " ";

	
	system("pause");
	return 0;
}




