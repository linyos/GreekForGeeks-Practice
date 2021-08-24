#include <iostream>
#include <vector>
using namespace std;

void Swap(int &p1,int &p2) {

	int tmp = p1;
	p1 =p2;
	p2 = tmp;
}
void PrintArray(vector<int> &array) {
	for (int i = 0; i < array.size(); i++){
		cout << array[i] << " ";
	}
	cout << endl;
}



void MaxHeapify(vector<int> & array, int root, int length) {
	int left = 2 * root;  // 取得left child
	int right = 2 * root + 1;  // 取得right child
	int largest ;            // largest用來記錄包含root與child, 三者之中Key最大的node
	if (left <= length && array[left] > array[root]){
		largest = left;
	}
	else{
		largest = root;
	}
	if (right<= length && array[right] >array[largest]){
		largest = right;
	}
	if (largest !=root ){                    // 如果目前root的Key不是三者中的最大
		Swap(array[largest], array[root]);   // 就調換root與三者中Key最大的node之位置
		MaxHeapify(array, largest, length);    // 調整新的subtree成Max Heap
	}
}



void BuildMaxHeap(vector<int> & array) {
	
	for  (int i = (int)array.size()/2; i >= 1;  i--){
		
		MaxHeapify(array, i, (int)array.size() - 1); // length要減一, 因為heap從1開始存放資料
	}
}


void HeapSort(vector <int> & array) {
	array.insert(array.begin(), 0);  // 將index(0)閒置
	BuildMaxHeap(array);             // 將array調整成Max Heap

	int size = (int)array.size() - 1;   // size用來記錄「目前要處理的矩陣」之長度
	for (int i = (int)array.size() -1; i >=2 ; i--){
		Swap(array[1], array[i]);// 將最大值放到array的最後一個位置
		size--;
		MaxHeapify(array, 1, size);  // 調整與root的位置 「忽略最後一個位置」的矩陣 
	}
	array.erase(array.begin());  // 將index(0)刪除 
}

int main() {
	int arr[] = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//vector <int> a{ 9, 4, 1, 6, 7, 3, 8, 2, 5 };
	vector<int> array(arr, arr + size);
	cout << "original:\n";
	PrintArray(array);

	HeapSort(array);
	cout << "sorted:\n";
	PrintArray(array);
	system("pause");
	return 0;
}