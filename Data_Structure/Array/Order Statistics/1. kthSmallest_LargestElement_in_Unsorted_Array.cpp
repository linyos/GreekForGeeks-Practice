#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
using namespace std;



// Method 1 
int kthSmallest(int arr[], int n, int k)
{
	sort(arr , arr+ n );
	return arr[k-1];
}









void Swap (int * a , int * b)
{
	int temp = *a;
	*a = * b;
	*b = temp;
}


int partition (int arr[] , int l ,int r)
{
	int x = arr[r] ;
	int i = l;

	for (int j = l; j < r; j++)
	{
		if (arr[j] <= x)
		{
			Swap(&arr[i] ,&arr[j]);
			i++;
		}
	}
	Swap(&arr[i] , &arr[r]);
	return i ;

	
}


class MaxHeap
{
private:
	// pointer to array of elements in heap
	int *harr;
	// maximum possible size to max heap
	int capacity;
	// Current number of elements in max heap
	int heap_size;
public:
	// Constructor
	MaxHeap(int arr[], int size);
	// To maxHeapify subtree rooted with index i
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
	// extract roots element
	int extractMax();
	// return maximum
	int getMax() {
		return harr[0];
	}
	// To replace root with new node x and heapify() new root
	void replaceMax(int x)
	{
		harr[0] = x;
		maxHeapify(0);
	}

};


MaxHeap::MaxHeap(int arr[], int size)
{
	heap_size = size;
	harr = arr;
	int i = (heap_size - 1) / 2;
	while (i >= 0)
	{
		maxHeapify(i);
		i--;
	}
}
// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
	if (heap_size == 0)
	{
		return INT_MAX;
	}
	int root = harr[0];

	if (heap_size > 1)
	{
		harr[0] = harr[heap_size - 1];
		maxHeapify(0);
	}
	heap_size--;
	return root;
}
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::maxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;

	if (l < heap_size && harr[l]> harr[i])
	{
		largest = l;
	}
	if (r < heap_size && harr[r]> harr[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(&harr[i], &harr[largest]);
		maxHeapify(largest);
	}
}

int  kthSmallest(int arr[], int n, int k)
{
	//Build a heap of first k elements O(k) time
	MaxHeap mh(arr, k);
	for (int i = k; i < n; i++)
	{
		if (arr[i] < mh.getMax())
		{
			mh.replaceMax(arr[i]);
		}
	}

	return mh.getMax();
}
// Method 5 :quickSort
int kthSmallest(int arr[], int l, int r, int k)
{
	//               Length: R-L+1 , R:L-1
	if (k > 0 && k <= r-l+1)
	{
		int pos = partition(arr,l , r);
		if (pos -l== k -1)
		{
			return arr[pos];
		}
		if (pos-l > k-1)
		{
			return kthSmallest(arr  , l ,pos-1 , k);
		}                                  // k - pos+R(L-1)
		return kthSmallest(arr, pos+1 , r , k-pos+l -1);
	}

	return INT_MAX;
}


// Method 6 : Map
int Kth_smallest(map<int, int> m, int k)
{
	int freq = 0;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		// if at any point frequency becomes
		// greater than or equal to k then
		 // return that element
		freq += (it->second);
		if (freq >= k)
		{
			return it->first;
		}
	}
	return -1;
}

int  main() {
	// Method 1. 
	/* int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k);*/
 

	// Method 2
	/*int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

	set<int> s (arr, arr+n);
	set<int> ::iterator itr= s.begin();

	advance(itr , k-1);
	cout<< * itr<< " \n";*/




	//int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
 //   int n = sizeof(arr) / sizeof(arr[0]), k = 3;
 //   cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);

	// Method 6
	int n = 5;
	int k = 2;
	vector<int> arr = { 12, 3, 5, 7, 19 };
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[arr[i]] += 1; // mapping every element with it's
						// frequency
	}

	int ans = Kth_smallest(m, k);
	if (k == 1)
	{
		cout << "The " << k << "st smallest element is " << ans
			<< endl;
	}
	else if (k == 2) {
		cout << "The " << k << "nd smallest element is " << ans
			<< endl;
	}
	else if (k == 3) {
		cout << "The " << k << "rd smallest element is " << ans
			<< endl;
	}
	else {
		cout << "The " << k << "th smallest element is " << ans
			<< endl;
	}
	system("pause");
	return 0;
}



