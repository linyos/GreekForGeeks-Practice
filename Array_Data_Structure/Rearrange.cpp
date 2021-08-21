#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void rearrangeArr(int arr[], const  int n) {
	int evenPos = n / 2;
	int oddPos = n - evenPos;
	int tmpArr[7]; // copy array


	//copy
	for (int i = 0; i < n; i++)
	{
		tmpArr[i] = arr[i];
	}

	sort(tmpArr, tmpArr + n);
	int j = oddPos - 1;



	for (int i = 0; i < n; i += 2)
	{
		arr[i] = tmpArr[j];
		j--;

	}

	j = oddPos;
	for (int i = 1; i < n; i += 2)
	{
		arr[i] = tmpArr[j];
		j++;
	}
	// display array
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	rearrangeArr(arr, size);

	system("pause");
	return 0;
}