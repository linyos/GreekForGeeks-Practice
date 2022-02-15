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
int main (){

	int arr[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	fixArray(arr, n);
	system("pause");
	return 0 ;
}