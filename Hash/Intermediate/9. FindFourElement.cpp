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

using namespace std;


bool findPairs(int arr[] , int n )
{
	// Create an empty Hash to store mapping from sum to pair index.
	map < int , pair<int ,int>> Hash;

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			int sum = arr[i] + arr[j];
			if (Hash.find(sum)==Hash.end())
			{
				Hash[sum] = make_pair(i ,j);
				//cout<<"i: " << i <<" " << j << endl;			
			}
			else
			{
				pair<int , int> aPair = Hash[sum];


				cout << aPair.first<< " "  << aPair.second << " " <<endl;
				cout<< arr[i] <<" " <<arr[j] << " "<< endl;
				cout << "(" << arr[aPair.first]<<" , " << arr[aPair.second]<< ") and ( " <<arr[i] <<", "<<arr[j]<<")n";
				return true;
			}
		}
	}
	
	cout << "No pairs found";
    return false;
}



int main()
{ 
	
	
	int arr[] = {3, 4, 7, 1, 2, 9, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	findPairs (arr , n );

	system("pause");
	return 0;
}