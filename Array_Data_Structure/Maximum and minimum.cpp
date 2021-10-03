#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Pair
{
public:
	int min;
	int max;
	Pair getminmax(int arr[], int n);
};

Pair getminmax(int arr[], int n) {
	Pair minmax;
	int i;

	if (n==1){
		minmax.max = arr[0];
		minmax.min = arr[0];
		cout << "only one element  value: " << arr[0];
		return minmax;
	}
	// If there are more than one elements,
	// then initialize min and max 
	if (arr[n] >arr[1]){
		minmax.max = arr[0];
		minmax.min = arr[1];
	}else{
		minmax.max = arr[1];
		minmax.min = arr[0];
	}

	for ( i = 2;i < n; i++){
		if (arr[i] > minmax.max){
			minmax.max = arr[i];
		}
		else if (arr[i] < minmax.min) {
			minmax.min = arr[i];
		}
	}
	return minmax;
}



int main(){

	int arr[] = { 1000, 11, 445,
					1, 330, 3000 };
	int arr_size = 6;
	Pair minmax= getminmax(arr, arr_size);
	cout << "Minimum element is "
		<< minmax.min << endl;
	cout << "Maximum element is "
		<< minmax.max;
	system("pause");
	return 0;
}