#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>


using namespace std;
struct ele {
	int count, index, val;
};

bool mycomp(ele a, ele b) {
	return (a.val < b.val); // �Ѥp�ƨ�j
}

bool mycomp2(ele  a, ele b) {
	if (a.count != b.count) {
		return (a.count < b.count);
	}
	else {
		return a.index > b.index;
	}
}

void sortByFrequency(int arr[], int n) {
	ele element[10];

	for (int i = 0; i < n; i++) {
		// Fill Indexes
		element[i].index = i;
		// Initialize count as 0
		element[i].count = 0;
		// Fill value in structure elements
		element[i].val = arr[i];
	}


	// Sort the structure element
	stable_sort(element, element + n, mycomp);
	/*for (int i = 0; i < n; i++) {
		cout << element[i].val << " ";
	}
	cout << endl;*/

	// Initialize count of first elements as 1.
	element[0].count = 1;

	for (int i = 1; i < n; i++)
	{
		if (element[i].val == element[i - 1].val)
		{
			// �J��ۦP�ƭȮɡA����ncount�n�֥[�_��
			element[i].count += element[i - 1].count + 1;

			//�e�@��element��count�n�ܦ�-1 �A�����ٷ|�A�ƦC�@���ҥH�L���Ƨ�
			element[i - 1].count = -1;

			// �ۦP���ƭȮɡAindex�u�ݰO��a�@�Ӧ�m��index
			element[i].index = element[i - 1].index;
		}
		else
		{
			// If previous element is not equal to current 
			// so set the count to 1 
			element[i].count = 1;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	cout << element[i].count <<" ";

	//}
	//cout << endl;
	//for (int i = 0; i < n; i++) {
	//	cout << element[i].index << " ";
	//}
	//cout << endl;

	// sort on the basis of count and in case of use index to sort
	stable_sort(element, element + n, mycomp2);
	for (int i = n - 1, index = 0; i >= 0; i--) {
		if (element[i].count != -1) {
			for (int j = 0; j < element[i].count; j++)
			{
				arr[index++] = element[i].val;
			}
		}
	}



}


int main() {

	int arr[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sortByFrequency(arr, n);

	//for (int i = 0; i < n; i++)
	//	cout << arr[i] << " ";
	system("pause");
	return 0;
}