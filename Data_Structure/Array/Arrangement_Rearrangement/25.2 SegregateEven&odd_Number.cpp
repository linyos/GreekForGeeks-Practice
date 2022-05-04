#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
using namespace std;




void arrayEvenAndOdd(int arr[], int n) {
	int b[8];
	int k = 0 , l = n-1 , i , j ;
	for (i = 0 , j =n-1; i < j ; i++ , j--)
	{
		if (arr[i]%2==0){
			//even number 
			b[k] =arr[i];
			k++;
		}
		else{
			// odd number 
			b[l]=arr[i];
			l--;
		}

		if (arr[j] %2==0){
			b[k] =arr[j];
			k++;
		}
		else
		{
			b[l] =arr[j];
			l--;
		}
	}

	 // for i == j in case of odd length
	b[i]==arr[i];



	 // Printing segregated array
  for (int i = 0; i < n; i++)
     cout << b[i] << " "; 

}

int  main() {

	 int arr[] = {1, 3, 2, 4, 7, 6, 9, 10};
  int n = sizeof(arr) / sizeof(int);
  arrayEvenAndOdd(arr, n);
	system("pause");
	return 0;
}



