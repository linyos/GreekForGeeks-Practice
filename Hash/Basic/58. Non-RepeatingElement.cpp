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
#include <ctime>
#include <time.h>
#include <stack>


using namespace std;


 
int firstNonRepeating(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int j ; 
		for (j = 0; j < n; j++)
		{
			if (i != j && arr[i]==arr[j])
				break;
		
		}
		if (j == n)
			return arr[i];
	}

	return -1;
}



// Method : using hash

int firstNonRepeating2(int arr[], int n)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		mp[arr[i]]++;
	}


	for (int i = 0; i < n; i++)
	{
		if (mp[arr[i]]==1)
		{
			return arr[i];
		}
	}




	return -1;
}





void firstNonRepeating3(int arr[], int n)
{
	unordered_map<int , int > mp ;
	for (int i = 0; i < n; i++)
		mp[arr[i]] ++;

	for (auto x : mp)
		if (x.second==1)
			cout << x.first << " ";


}


int main()
{
	
	int arr[] = { 9, 4, 9, 6, 7, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << firstNonRepeating(arr, n) <<endl; 

	cout << firstNonRepeating2(arr, n)<<endl;


	firstNonRepeating3(arr, n);


	system("pause");
	return 0;
}