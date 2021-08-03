#include <iostream>
using namespace std;

/*
Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
1) Store the first d elements in a temp array
   temp[] = [1, 2]
2) Shift rest of the arr[]
   arr[] = [3, 4, 5, 6, 7, 6, 7]
3) Store back the d elements
   arr[] = [3, 4, 5, 6, 7, 1, 2]
 */


// Method1  (Using temp array) 
void leftRotatebyOne(int arr[]  ,int size) {

	int tmp = arr[0];
	for (int i = 0; i < size-1; i++)
	{
		/*
		[0  1   2   3   4 ]
		1<-2 <-3 <-4 <-5
	    
		*/	
		arr[i] = arr[i + 1];   
	}

	arr[size - 1] = tmp;    // arr[last_index]=arr[0]
}

void leftRotate(int arr[], int key, int size) {
	for (int i = 0; i < key; i++){
		leftRotatebyOne(arr, size);
	}
}


void printArray(int arr[], int size) {
	for (int  i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

}



int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);




	leftRotate(arr, 2, size);
	printArray(arr, size);

	system("pause");
	return 0;
}