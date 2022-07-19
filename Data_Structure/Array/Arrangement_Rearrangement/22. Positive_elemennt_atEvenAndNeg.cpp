#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>

using namespace std;



void rearrange(int arr[], int size)
{
	int pos = 0, neg = 1;

	while (true){
		while (pos< size && arr[pos] >= 0 ){
			pos += 2;
		}
		while (neg < size && arr[neg] <= 0){
			neg += 2;
		}
		if (pos < size && neg < size){
			swap(arr[pos], arr[neg]);
		}
		else {
			break;
		}	
	}
}

int main()
{
	int arr[] = { 1, -3, 5, 6, -3, 6, 7, -4, 9, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	rearrange(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	
	system("pause");
	return 0;
}
