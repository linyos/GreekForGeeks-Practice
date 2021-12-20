#include <iostream>
#include <queue>
#include<unordered_map>
using namespace std;



void groupElemnets(int arr[] , int n ){

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i]= false;
	}

	// Travesal all elements
	for (int i = 0; i < n; i++)
	{
		// Check if this is first occurrence
		if (! visited[i])
		{
			// If yes, print it and all subsequent occurrence
			cout << arr[i] <<" ";
			for (int j =  i+1; j < n; j++)
			{
				if (arr[i] ==arr[j])
				{
					cout<<arr[i]<<" ";
					visited[j] =true;
				}
			}
		}
	}
	delete [] visited;

}


int main(){
	
	int arr[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    groupElemnets(arr, n);
	system("pause");
	return 0;
}