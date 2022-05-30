#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;



// method : simple
void splitArr(int arr[], int n, int k)
{
	for (int i = 0; i < k; i++)
	{
		int x = arr[0];
		for (int j = 0; j < n-1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[n - 1] = x;
	}

}

// Function to split array and
// move first part to end
void splitArr1(int arr[], int n, int k)
{
	// n = 6;
	int temp[12] = { 0 };
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
		temp[i + n] = arr[i];
	}
	for (int i = k; i <n+k ; i++)
	{
		arr[i - k ] = temp[i];
	}
}


// Method 3 : reverse 

void reverseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void splitArr3(int arr[], int k, int n)
{
	reverseArray(arr, 0, n - 1);  // 36 52 6 5 10 12


	reverseArray(arr, 0, n - k - 1); // [5 6 52 36]  10 12


	reverseArray(arr, n - k, n - 1); // 5 6 52 36 [ 10 12]
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() 
{

	int arr[] = { 12, 10, 5, 6, 52, 36 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int position = 2;

	splitArr1(arr, 6, position);

	for (int i = 0; i < n; ++i)
		cout << " " << arr[i];

	system("pause"); 
	return 0;
}


