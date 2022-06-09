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

using namespace std;



int getRandom (int x , int y)
{
	srand(time(NULL));
	return (x + rand() % (y-x+1));
}


// Method : recursive
int randomizedBinarySearch(int arr[] , int l , int r , int x )
{
	if (r >= l )
	{


		int mid = getRandom(l , r);

		cout <<  getRandom(l , r)<< endl;
		if (arr[mid]==x)
			return mid;

		 if (arr[mid] > x)
			 return randomizedBinarySearch(arr ,l  , mid-1 , x);

		 return randomizedBinarySearch(arr , mid+1 , r , x);
	}
	return -1;
}



int randomizedBinarySearch(int arr[], int l, int r, int x)
{
	if (l <=r )
	{
		int mid = getRandom(l , r);	
		if (arr[mid]==x)
			return mid;
		if (arr[mid] < x)
				l = mid+1;
		else
			r= mid-1;
	}
	return -1;
}





int main()
{  

   int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 10;
    int result = randomizedBinarySearch(arr, 0, n-1, x);

	(result==-1) ? 
		printf("Element is not present in array") : 
		printf("Element is present at index %d", result);


	system("pause");
	return 0;
}