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
#include <vector>

using namespace std;


void Swap (int *a , int *b){
	int temp = *a;
	*a =*b;
	*b= temp;
}

void  fixArray(int arr[] , int n) {
	int i, j , tmp ;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[j]==i)
			{
				Swap(&arr[i] , &arr[j]);
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i]!= i )
		{
			arr[i]=-1;
		}
	}


	cout << "Array after Rearranging" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}


//Method2 
void fixArray2(int arr[] , int n ){

	for (int i = 0; i < n; i++)
	{
		if (arr[i] != -1 && arr[i] != i)
		{
			int x = arr[i];
			//Check if desired place is not vacate
			while (arr[x] !=-1 &&  arr[x] !=x)
			{
				// Store the value from desired place
				int y = arr[x];
				//Store the x to its correct position
				arr[x] = y;
				//now y will become x, now search the place for x 
				x=y;

			}
			 // place the x to its correct
            // position
			arr[x] =x;

			// check if while loop hasn't set the correct value at arr[i]
			if (arr[i] != i)
			{
				//put -1 at the vacated plae
				arr[i]=-1
			}
		}

	}
}


int main (){

	int arr[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	fixArray2(arr, n);
	system("pause");
	return 0 ;
}