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

// Find the sum of all non-repeated elements
// in an array
int findSum(int arr[], int n)
{
    // sort all elements of array
    sort(arr, arr + n);
 
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        if (arr[i] != arr[i+1])
            sum = sum + arr[i];
    }
 
    return sum;
}
 



int findSum2 (int arr[] , int n )
{
	int sum =0 ;

	unordered_set <int> s ;

	for (int i = 0; i < n; i++)
	{
		// «D­«½Æªº
		if (s.find(arr[i]) == s.end())
		{
			sum += arr[i];
			s.insert(arr[i]);
		}
	}

	return sum ;
}



int main()
{
	
	
	int arr[] = {1, 2, 3, 1, 1, 4, 5, 6};
    int n = sizeof(arr)/sizeof(int);
    cout << findSum(arr, n) <<endl;
	 cout << findSum2(arr, n) << endl;
	system("pause");
	return 0;
}