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
	int left = 2 * root;  // ���oleft child
	int right = 2 * root + 1;  // ���oright child
	int largest ;            // largest�ΨӰO���]�troot�Pchild, �T�̤���Key�̤j��node
	if (left <= length && array[left] > array[root]){
		largest = left;
	}
	else{
		largest = root;
	}
	if (right<= length && array[right] >array[largest]){
		largest = right;
	}
	if (largest !=root ){                    // �p�G�ثeroot��Key���O�T�̤����̤j
		Swap(array[largest], array[root]);   // �N�մ�root�P�T�̤�Key�̤j��node����m
		MaxHeapify(array, largest, length);    // �վ�s��subtree��Max Heap
	}
}



void BuildMaxHeap(vector<int> & array) {
	
	for  (int i = (int)array.size()/2; i >= 1;  i--){
		
		MaxHeapify(array, i, (int)array.size() - 1); // length�n��@, �]��heap�q1�}�l�s����
	}
}


void HeapSort(vector <int> & array) {
	array.insert(array.begin(), 0);  // �Nindex(0)���m
	BuildMaxHeap(array);             // �Narray�վ㦨Max Heap

	int size = (int)array.size() - 1;   // size�ΨӰO���u�ثe�n�B�z���x�}�v������
	for (int i = (int)array.size() -1; i >=2 ; i--){
		Swap(array[1], array[i]);// �N�̤j�ȩ��array���̫�@�Ӧ�m
		size--;
		MaxHeapify(array, 1, size);  // �վ�Proot����m �u�����̫�@�Ӧ�m�v���x�} 
	}
	array.erase(array.begin());  // �Nindex(0)�R�� 
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