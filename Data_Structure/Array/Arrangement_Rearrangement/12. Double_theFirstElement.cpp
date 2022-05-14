#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <unordered_map>

using namespace std;




// function which pushes all zeros to end of
// an array.
void pushZeroToEnd(int arr[], int n)
{
	int count = 0;
	// Traverse the array. If element encountered
	// is non-zero, then replace the element at
	// index 'count' with this element
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			// here count is incremented
			arr[count++] = arr[i];
		}
	}
	// Now all non-zero elemnts have been shifted to front 
	while (count < n )
	{
		arr[count++] = 0;
	}


}

void modifyAndRearrangeArr(int arr[], int n)
{
	if (n == 1)
	{
		return ;
	}

	for (int i = 0; i < n-1; i++)
	{
		if ((arr[i] != 0)  &&  (arr[i]==arr[i+1]))
		{
			arr[i] = 2 * arr[i];
			arr[i + 1] = 0;
			i++;
		}
	}
	// push all the zero at the end of 'arr[]'
	pushZeroToEnd(arr, n);
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int main() 
{
	int arr[] = { 0, 2, 2, 2, 0, 6, 6, 0, 0, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original array: ";
	printArray(arr, n);
	cout << endl;
	pushZeroToEnd(arr, n);
	printArray(arr, n);

	system("pause");
	return 0;
}


