#include <iostream>


using namespace std;

void Qswap(int *a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp; 
}


/* The function takes last element as pivot ;

*/
int partiotion(int arr[], int l, int h) {
	int x =arr[h];
	int i = (l - 1);

	for (int j = l; j < h -1 ; j++){
		if (arr[j] <= x){
			i++;
			Qswap(&arr[i], &arr[j]);
		}
	}
	Qswap(&arr[i + 1], &arr[h]);
	return i + 1;
}

void quickSort(int arr[], int l, int h) {
	if (l < h){
		int p = partiotion(arr, l, h);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, h);
	}
}


int main() {
	const int n = 5;
	int arr[n] = { 4, 2, 6, 9, 2 };

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}