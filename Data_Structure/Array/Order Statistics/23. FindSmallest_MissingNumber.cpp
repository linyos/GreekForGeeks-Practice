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


using namespace std;




int findFirstMissing(int arr[] , int start , int end)
{
	if (start> end)
	{
		return end+1;
	}

	if (start != arr[start])
	{
		return start;
	}

	int mid = start+(end - start)/2;

	if (arr[mid]==mid)
	{
		return findFirstMissing(arr , mid +1 , end);
	}
	return findFirstMissing(arr , start , mid);
}

int main()
{  
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Smallest missing element is " << findFirstMissing(arr, 0, n-1) << endl;
	system("pause");
	return 0;
}