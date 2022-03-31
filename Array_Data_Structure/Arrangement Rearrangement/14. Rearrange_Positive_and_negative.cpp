#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include<unordered_map>
#include <set>
#include <stack>
#include <string>

using namespace std;





void printArray(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}



void RearrangePosNeg(int arr[], int n)
{
	int key, j; 
	for (int i = 1; i < n; i++)
	{
		key = arr[i];


		if (key > 0)  continue;
		


		
		j = i - 1;
		cout << arr[j] << endl;
		while (j >=0 && arr[j]>0)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		
		arr[j + 1] = key;
	}
}


int main() {
	int arr[] = { -12, 11, -13, -5, 4, -7, 5, -3, -6 };
	int n = sizeof(arr) / sizeof(arr[0]);



	RearrangePosNeg(arr, n);
	printArray(arr, n);
	system("pause");
	return 0;
}




