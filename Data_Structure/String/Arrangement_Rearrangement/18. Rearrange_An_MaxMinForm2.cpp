#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>

using namespace std;


void rearrange(int arr[], int n)
{
	int max_idx = n - 1, min_idx = 0;
	int max_elm = arr[n - 1] + 1;

	for (int i = 0; i < n; i++)
	{
		if (i%2==0)
		{
			arr[i] += (arr[max_idx] % max_elm) * max_elm;
			max_idx--;
		}
		else
		{
			arr[i] += (arr[min_idx] % max_elm) * max_elm;
			min_idx++;
		}
	}


	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i] / max_elm;
	}
}


void rearrange2(int arr[], int n)
{
	int max_ele = arr[n - 1];
	int min_ele = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (i%2==0)
		{
			arr[i] = max_ele;
			max_ele--;
		}
		else
		{
			arr[i] = min_ele;
			min_ele++;
		}
	}

}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original Arrayn";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	rearrange(arr, n);

	cout << "\nModified Array\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";



	cout << endl;
	cout << "-------------Method2-------" << endl;
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	cout << "Original Array\n";
	for (int i = 0; i < n2; i++)
		cout << arr2[i] << " ";

	rearrange2(arr2, n2);

	cout << "\nModified Array\n";
	for (int i = 0; i < n2; i++)
		cout << arr2[i] << " ";

	
	system("pause");
	return 0;
}




