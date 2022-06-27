#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;

// Method 1 
void printDistinct(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int j;
		for ( j	= 0; j < i; j++)
		{
			if (arr[i] == arr[j])
				break;
		}

		if (i == j)
		{
			cout << arr[i] << " ";
		}
	}

}



void printDistinct2(int arr[], int n)
{
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++)
	{
		while (i < n - 1 && arr[i] == arr[i + 1])
			i++;
		cout << arr[i] << " ";
	}
}

void printDistinct3(int arr[], int n)
{
	unordered_set <int> s;
	for (int i = 0; i < n; i++)
	{
		if (s.find(arr[i])==s.end())
		{
			s.insert(arr[i]);
			cout << arr[i] << " ";
		}
	}
}


void printDistinct4(int arr[], int n)
{
	map<int, int> hm;
	map<int, int> hm1;



	//for (int i = 0; i < n; i++)
	//{
	//	hm1[arr[i]] = i;
	//}

	//for (auto &x : hm1)
	//{
	//	cout << x.first << " " << x.second << endl;
	//}



	for (int i = 0; i < n; i++)
	{
		hm.insert({ arr[i] , i });
	}

	cout << "[";
	for (auto const &pair : hm)
	{
		cout << pair.first << ", ";
	}
	cout << "]";


}



int main() 
{
	int arr[] = { 6, 10, 5, 4, 9, 120, 4, 6, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	/*printDistinct(arr, n);

	printDistinct3(arr, n);*/

	printDistinct4(arr, n);
	system("pause"); 
	return 0;
}




