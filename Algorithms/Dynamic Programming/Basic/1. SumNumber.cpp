#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <unordered_map>

using namespace std;


int rec_opt(int arr[], int i)
{
	if (i == 0) return arr[0];
	else if (i == 1) return max(arr[0], arr[1]);
	else
	{
		int a = rec_opt(arr, i - 2) + arr[i];
		int b = rec_opt(arr, i - 1);
		return max(a, b);
	}


}

int dp_opt(int arr[], int n )
{

	
	int opt[5] ={0};
	opt[0] = arr[0];
	opt[1] = max(arr[0] , arr[1]);

	for (int i = 2; i < n; i++)
	{
		int a = opt[i - 2] + arr[i];
		int b = opt[i - 1];
		opt[i] = max(a, b);
	
	}

	return opt[n-1];
}
int main() 
{

	//int arr[] = { 1,2,4,1,7,8,3 };
	int arr[] = {4,1,1,9,1};
	int n = sizeof(arr) / sizeof(arr[0]);

	//cout<<rec_opt(arr, n) << endl;





	cout << dp_opt(arr, n) << endl;



	system("pause");
	return 0;
}


