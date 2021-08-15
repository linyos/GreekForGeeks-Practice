//// Maximum sum such that no two elements are adjacenet
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int FindMaxSum(vector <int> arr, int n) {
//	int incl = arr[0];
//	int excl = 0;
//
//	int new_excl;
//	
//	for (int i = 1; i < n; i++)
//	{
//		//current max includeing i 
//		new_excl=(incl > excl) ? incl : excl;
//		// current max index 
//		incl = (excl + arr[i]);
//		excl = new_excl;
//	}	
//
//	// return max of incl and  excl
//	return ((incl > excl) ? incl : excl);
//}
//
//
//
//int main(void ) {
//	vector<int> arr = { 5,5,10,100,10,5 };	
//	cout << FindMaxSum(arr, arr.size()) << " ";
//	system("pause");
//	return 0;
//}