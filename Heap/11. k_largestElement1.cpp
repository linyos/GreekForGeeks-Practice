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

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


class MaxHeap
{
	int *harr;
	int capacity;
	int heap_size;
public:
	MaxHeap(int arr[], int size);
	void maxHeapify(int i);
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return (2 * i + 1);
	}
	int right(int i) {
		return (2 * i + 2);
	}
	int extractMax();
	int getMax() {
		return harr[0];
	}
	void replaceMax(int x) {
		harr[0] = x;
		maxHeapify(0);
	}
};



void MaxHeap::maxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;

	if (i < heap_size && harr[l] > harr[i]) {
		largest = l;
	}
	if (i < heap_size && harr[r] > harr[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(&harr[i], &harr[largest]);
		maxHeapify(largest);
	}
}

MaxHeap::MaxHeap(int arr[], int n) {
	heap_size = n;
	harr = arr;
	int i = (heap_size - 1) / 2;
	while (i >=0){
		maxHeapify(i);
		i--;
	}
}


int MaxHeap::extractMax()
{
	if (heap_size == 0)
		return INT_MAX;
	
	int root = harr[0];
	if (heap_size > 1)
	{
		harr[0] = harr[heap_size - 1];
		maxHeapify(0);
	}
	heap_size--;
	return root;
}



int kthSmallest(int arr[], int n, int k)
{
	MaxHeap mh(arr, k);

	for (int i = k; i < n; i++)
	{
		if (arr[i] <mh.getMax())
		{
			mh.replaceMax(arr[i]);
		}
	}
	return mh.getMax();
}



int main()
{
	
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " << kthSmallest(arr, n, k);

	
	system("pause");
	return 0;
}
