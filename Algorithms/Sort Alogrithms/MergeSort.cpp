#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
using	namespace std;



/*
Merge two subarray of array[].
First subarray is arr[begin...mid]
Two subarray is arr[mid+1...end]
*/
void merge(int arr[], const int left, const int mid, const int right) {
	
	const int subArrayOne = mid - left + 1;
	const int subArrayTwo = right - mid;
	// Create temp arrays
	int * leftArray = new int[subArrayOne];
	int * rightArray = new int[subArrayTwo];
	// Copy data to temp arrays  leftarray[] and rightarray[]
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = arr[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = arr[mid + 1 + j];
	// Initial index of first sub-array
	// Initial index of second sub-array
	int indexofSubArrayOne = 0, indexofSubArrayTwo = 0;
	// Initial index of merged array
	int indexMergedArray = left;


	// Merge the temp attay back into array[left...right]
	while (indexofSubArrayOne < subArrayOne && indexofSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexofSubArrayOne] <= rightArray[indexofSubArrayTwo])
		{
			arr[indexMergedArray] = leftArray[indexofSubArrayOne];
			indexofSubArrayOne++;
		}
		else
		{
			arr[indexMergedArray] = rightArray[indexofSubArrayTwo];
			indexofSubArrayTwo++;
		}
		indexMergedArray++;
	}
	//Copy the remaining elements of left[], if there are any
	// 如果上一步合併之後leftArray 還有剩餘element還沒合併，
	// 將leftarray 逐一合併array
	while (indexofSubArrayOne < subArrayOne){
		arr[indexMergedArray] = leftArray[indexofSubArrayOne];
		indexofSubArrayOne++;
		indexMergedArray++;
	}
	//Copy the remaining elements of right[] , if there are any.
	while (indexofSubArrayTwo < subArrayTwo){
		arr[indexMergedArray] = rightArray[indexofSubArrayTwo];
		indexofSubArrayTwo++;
		indexMergedArray++;
	}




}





void mergeSort(int arr[], const  int  begin, const int end) {
	if (begin >= end)
	{
		return;
	}
	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

void printArray(int arr[], int size) {
	for (auto i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);

	system("pause");
	return 0;
	
}


