#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include<queue>
#include <set> 
#include <iomanip>
#include <unordered_set>
using namespace std;


// Method1 : Native
//void Swap(int & a , int & b){
//
//	int temp = a ;
//	a = b;
//	b= temp;
//
//}
//
//void fixArray(int arr[] , int n ){
//
//	int i , j , temp;
//
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[j] ==i)
//			{
//				Swap(arr[j] , arr[i]);
//			break;
//			}
//		}
//	}
//
//
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] != i)
//		{
//			arr[i] = -1;
//		}
//	}
//
//
//	cout<<"Array After Rearranging " <<endl;
//	// Print
//	for (int i = 0; i < n; i++)
//	{
//		cout<<arr[i] <<" ";
//	}
//	cout<<endl;
//
//}


// Method2
//void fixArray (int arr [] , int n){
//
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] != -1 && arr[i] !=i)
//		{
//			int x = arr[i];
//			
//			while (arr[x] != -1 && arr[x] != x)
//			{
//				// Store the value from desire place
//				int y = arr[x];
//				// place the x to its correct position
//				arr[x] = x;
//				// now y will become x , now search the place for x 
//				x= y;
//			}
//
//			// place the x to its correct position
//			arr[x] = x;
//
//			// Check if while loop has't set the correct value at arr[i]
//			if (arr[i] != i)
//			{
//				// put -1 at the vacated place
//				arr[i] =-1;
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++){
//		cout << arr[i] << " ";
//	}
//        
//}



// Method3: set

void fixArray (int arr[] , int n ){
	 unordered_set<int> s;

	 // Enter each element which is not -1 in set
	 for (int i = 0; i < n; i++)
	 {
		 s.insert(arr[i]);
	 }

	  // Navigate through array,
	 // and put A[i] = i,
	// if i is present in set

	 for (int i = 0; i < n; i++)
	 {
		 cout <<  s.find(i) << endl;
		 if (s.find(i) != s.end())
		 {
			 arr[i] = i;
		 }
		 else
		 {
			 arr[i]=-1;
		 }
	 }

}


int main (){

	int n , arr [] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	n = sizeof(arr) / sizeof(arr[0]);

	
	 fixArray(arr, n);
	system("pause");
	return 0 ;
}