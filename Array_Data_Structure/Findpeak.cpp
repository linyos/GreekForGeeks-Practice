#include<iostream>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>


using namespace std;

// Method 1
//int findPeak (int arr[] , int n){
//
//	// check first or last element is peak element
//	if (n==1){
//		return 0;
//	}
//	if (arr[0] >=arr[1]){
//		return 0;
//	}
//	if (arr[n-1] >= arr[n-2]){
//		return n-1;
//	}
//
//
//	for (int i =1; i < n-1; i++){
//		if (arr[i] >= arr[i-1] && arr[i]>= arr[i+1]){
//			return i;
//		}
//	}
//
//
//}


//Method 2 : Divide and conquer

int findPeakUtil(int arr[] , int low ,int high , int n){

	int mid = low + (high-low)/2;

	if ((mid==0 ||arr[mid-1] <= arr[mid]) && 
		 (mid==n-1 || arr[mid+1] <<arr[mid]))
	{
		return mid;
	}
	else if (mid > 0 && arr[mid-1] >arr [mid])
	{
		return findPeakUtil(arr, low , (mid-1) , n);
	}
	else
	{
		return findPeakUtil (arr, mid+1 , high , n);
	}



}



int findPeak(int arr[] , int n ){
	return findPeakUtil(arr, 0 , n-1 , n);
}






int main(){
	 int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is "
         << findPeak(arr, n);

	system("pause");
	return 0 ;
}
