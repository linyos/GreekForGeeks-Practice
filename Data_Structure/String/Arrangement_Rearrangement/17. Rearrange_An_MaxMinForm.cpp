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

	int temp[6];
	int small = 0, large = n - 1;
	int flag = true;

	for (int i = 0; i < n; i++)
	{
		if (flag) {
			temp[i] = arr[large--];
		}
		else{
			temp[i] = arr[small++];
		}
		flag = !flag;
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}

}



int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original Array\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	rearrange(arr, n);

	cout << "\nModified Array\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	system("pause");
	return 0;
}




