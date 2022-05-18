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

		// IF current element is positive, then do nothing
		if (key > 0)  continue;



		// Modified insertion sort 
		//IF current element is negative, shift positive element of arr[0..i-1],
		// to one position to their right.
		j = i - 1;
		//cout << arr[j] << endl;
		while (j >= 0 && arr[j] > 0)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		// Put negative element at its right position
		arr[j + 1] = key;
	}
}



// 延伸題

//[1,2,3,4,5,6] -> [1,3,2,4,6]
void RearrangePosNeg2(int arr[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{

		key = arr[i];
		if (key % 2 == 0) continue;
		j = i - 1;

		while (j >= 0 && arr[j] % 2 == 0)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

}







void merge(int arr[], const int l, const int m, const int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	// 要修改一下

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + j + 1];
	}

	i = 0;
	j = 0;
	k = l;



	// Copy negative element of left subarray
	while (i < n1 && L[i] < 0)
	{
		arr[k++] = L[i++];
	}


	//Copy negative element of right subarray
	while (j < n2 && R[j] < 0)
	{
		arr[k++] = R[j++];
	}

	// copy positive elements of left subarray
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	// copy positive elements of right subarray
	while (j < n2)
	{
		arr[k++] = R[i++];
	}


}




void RearrangePosNeg(int  arr[], const int l, const int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoid overflow for large l and h .
		const int m = l + (r - l) / 2;

		// Sort first and second halves
		RearrangePosNeg(arr, l, m);
		RearrangePosNeg(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}





int main() {
	int arr[] = { -12, 11, -13, -5, 4, -7, 5, -3, -6 };
	int n = sizeof(arr) / sizeof(arr[0]);



	RearrangePosNeg(arr, n);
	printArray(arr, n);


	RearrangePosNeg(arr, 0, n);

	printArray(arr, n);



	system("pause");
	return 0;
}




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

		// IF current element is positive, then do nothing
		if (key > 0)  continue;



		// Modified insertion sort 
		//IF current element is negative, shift positive element of arr[0..i-1],
		// to one position to their right.
		j = i - 1;
		//cout << arr[j] << endl;
		while (j >= 0 && arr[j] > 0)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		// Put negative element at its right position
		arr[j + 1] = key;
	}
}


void merge(int arr[], const int l, const int m, const int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	// 要修改一下

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + j + 1];
	}

	i = 0;
	j = 0;
	k = l;



	// Copy negative element of left subarray
	while (i < n1 && L[i] < 0)
	{
		arr[k++] = L[i++];
	}


	//Copy negative element of right subarray
	while (j < n2 && R[j] < 0)
	{
		arr[k++] = R[j++];
	}

	// copy positive elements of left subarray
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	// copy positive elements of right subarray
	while (j < n2)
	{
		arr[k++] = R[i++];
	}


}




void RearrangePosNeg(int  arr[], const int l, const int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoid overflow for large l and h .
		const int m = l + (r - l) / 2;

		// Sort first and second halves
		RearrangePosNeg(arr, l, m);
		RearrangePosNeg(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}





int main() {
	int arr[] = { -12, 11, -13, -5, 4, -7, 5, -3, -6 };
	int n = sizeof(arr) / sizeof(arr[0]);



	RearrangePosNeg(arr, n);
	printArray(arr, n);


	RearrangePosNeg(arr, 0, n);

	printArray(arr, n);



	system("pause");
	return 0;
}




