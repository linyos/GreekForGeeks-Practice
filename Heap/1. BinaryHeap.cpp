#include <iostream>
#include<queue>
#include<climits>

using namespace std;


void swap (int *x , int *y);

class MinHeap
{
	int * harr;    // pointer to array of elements in heap
	int capacity;  // maximum possible size of min heap
	int head_size; // Current number of elements in min heap
public:
	MinHeap(int capacity);

	 void MinHeapify(int );

	 int parent(int i )
	 {
		 return (i-1)/2;
	 }
	 int left(int i )
	 {
		 return (2*i+1);
	 }
	 int right (int i )
	 {
		 return (2*i+2);
	 }

	 int extractMin();

	 void decreaseKey(int i , int new_val);

	 int getMin()
	 {
		 return harr[0];
	 }

	 void deleteKey(int i);

	 void insertKey(int k);


};

//Constructor : Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
	head_size = 0;
	capacity =cap;
	harr =new int[cap];
}


// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
	if (head_size==capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
        return;
	}
	 // First insert the new key at the end
	head_size++;
	int i  =  head_size-1;
	harr[i] = k;

	// Fix the min head property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i] , &harr[parent(i)]);
		i= parent(i);
	}
}

//Decrease value of key at index 'i' to new_value .
//It is assumed that new value is smaller than harr[i]
void MinHeap::decreaseKey(int i , int new_val)
{
	harr[i] = new_val;
	while (i !=0 && harr[parent(i)] >harr[i])
	{
		swap(&harr[i] , &harr[parent(i)]);
		i= parent(i);
	}
}

// Method to remove minimun element (or root) from min heap;
int MinHeap::extractMin()
{
	if (head_size <=0 )
	{
		return INT_MAX;
	}
	if (head_size==1)
	{
		head_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from head.
	int root = harr[0];
	harr[0] = harr[head_size-1];
	head_size--;
	MinHeapify(0);

	return root;
}



void MinHeap::deleteKey(int i )
{
	 decreaseKey(i, INT_MIN);
	 extractMin();
}


void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	 int r = right(i);
    int smallest = i;
	if (l < head_size && harr[l] < harr[i])
	{
		smallest = l;
	}
	if (r <head_size && harr[r] < harr[smallest])
	{
		smallest=r;
	}
	if (smallest != i)
	{
		  swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
	}
}

void swap(int *x , int *y)
{
	int temp = *x ;
	*x = *y;
	*y = temp ;
}

int main() {
	 MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
	system("pause");
	return 0;
}







