#include <iostream>

using namespace std;




// Method simple 
//void reorder(int arr[], int inder[], int n) {
//
//	int temp[5];
//
//	// arr[i] should to reorder elements of arr[] according
//	for (int i = 0; i < n; i++)
//	{
//		temp[inder[i]] = arr[i];
//	}
//
//	// copy temp[] to arr[]
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = temp[i];
//		inder[i] = i;
//	}
//
//}



//
//void reorder(int *arr,int index[], int n) {
//
//	int  temp[5];
//	for (int i = 0; i < n; i++)
//	{
//		temp[index[i]] = *(arr+i);
//	}
//	
//	//int * ptemp = temp;
//	// 指標函數寫入
//	/*for (int i = 0; i < n; i++)
//	{
//		cout << *(ptemp + i) << " ";
//	}
//	cout << endl;*/
//
//	for (int i = 0; i < n; i++)
//	{
//		*(arr+i) = temp[i];
//		index[i] = i;
//	}
//}


// Without Auxiliary Array
void reorder(int arr[], int index[], int n) {
	// Fix all elements one by one
	for (int i = 0; i < n; i++)
	{
		//While index[i] and arr[i] are not fixed
		while (index[i] != i)
		{
			// Store value of the target position before placing arr[i]
			int oldTargetI = index[index[i]];
			int oldTargetE = arr[index[i]];


			cout << "oldTargetI: " << oldTargetI << endl;
			cout << "oldTargetE: " << oldTargetE << endl;


			//place arr[i] at its target position. Alse copy corrected index for new position

			cout << arr[i] << endl;
			cout << index[i] << endl;

			arr[index[i]] = arr[i];
			index[index[i]] = index[i];

			index[i] = oldTargetI;
			arr[i] = oldTargetE;
		}
	}

}


int main() {
	int arr[] = { 50, 40, 70, 60, 90 };
	int index[] = { 3,  0,  4,  1,  2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	//cout << index[1] << endl;


	reorder(arr, index, n);
	cout << "Reordered array is: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << "\nModified Index array is: \n";
	for (int i = 0; i < n; i++)
		cout << index[i] << " ";






	system("pause");
	return 0;
}