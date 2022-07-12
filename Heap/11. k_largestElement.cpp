#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>

using namespace std;

void swap (int &x , int &y)
{
	int temp = x ;
	x = y ;
	y = temp;
}




class MinHeap
{
private:
	int size;
	int * arr;
public:
	MinHeap(int arr[] ,int size  );

	void heapify( int n , int i);
	void buildHeap();


	void FirstKelements(int arr[] , int size , int k);
};


MinHeap::MinHeap(int arr[] ,int size  )
{
	this->size =size;
	this->arr = arr;
	
	buildHeap();
}

void MinHeap::heapify( int n ,int i )
{


	int smallest = i ;
	int left = 2 * i +1 ;
	int right = 2* i + 2;

	//smallest = arr[left] < arr[i] ? left : i ;

	if (left < n)
	{
		smallest = arr[left] < arr[smallest] ? left :smallest ;
	}



	if (right< n)
	{
		smallest  = arr[right] < arr[smallest] ? right : smallest;
	}


	if (smallest  != i)
	{
		swap(arr[i] , arr[smallest ]);
		heapify(n, smallest);
	}
}



void MinHeap::buildHeap()
{
	for (int i = size/2-1 ; i >= 0  ; i--)
	{
		heapify(size , i);
	}

	for (int i = size-1; i >0 ; i--)
	{
		swap(arr[0] , arr[i]);
		heapify(i , 0);
	}




}




void MinHeap::FirstKelements(int arr[] , int size , int k)
{
	MinHeap *  m = new MinHeap(arr , size );


	for (int i = 0; i < k; i++)
	{
		cout <<arr[i]<<" ";
	}
	cout<<endl;


}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}





int main()
{ 
	 int arr[] = { 11, 3, 2, 1, 15, 5, 4,
                           45, 88, 96, 50, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    // Size of Min Heap
    int k = 3;
 
	MinHeap * m= NULL;

	m->FirstKelements(arr , size , k);

	//MinHeap * m = new MinHeap(arr , size);
	


	printArray(arr , size);
	system("pause");
	return 0;
}