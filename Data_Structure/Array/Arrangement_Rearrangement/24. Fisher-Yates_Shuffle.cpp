#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <ctime>
#include <time.h>


using namespace std;





void printArr (int arr[] ,int n )
{
	for (int i = 0; i < n; i++)
	{
		cout<< arr[i] <<" ";
	}
	cout<<endl;
}




void swap (int *a , int *b)
{
	int temp = *a ;
	*a = *b;
	*b = temp ;
}

void randomize (int arr[] , int n )
{


	  // Use a different seed value so that
    // we don't get same result each time
    // we run this program
    srand (time(NULL));


	for (int i = n-1; i> 0  ; i--)
	{
		int j = rand() % (i+1);
		swap(&arr[j] , &arr[i]);
	}
}




int main()
{  
	int arr[] = {2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	randomize(arr, n);
	printArr (arr , n);
  
	system("pause");
	return 0;
}