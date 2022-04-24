#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>

using namespace std;

void reorder(int arr[], int index[], int n)
{
	
	int temp[5];

	for (int i = 0; i < n; i++)
	{
		temp[index[i]] = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
		index[i] = i;
	}
}

int main() {
	int arr[] = { 50, 40, 70, 60, 90 };
	int index[] = { 3,  0,  4,  1,  2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	reorder(arr, index, n);

	cout << "Reordered array is: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << "\nModified Index array is: \n";
	for (int i = 0; i < n; i++)
		cout << index[i] << " ";

	
	system("pause");
	return 0;
}




