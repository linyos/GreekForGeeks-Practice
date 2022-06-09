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

using namespace std;




int findMinLength(string arr[] , int n )
{
	int min = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (arr[i].length() < min)
		{
			min = arr[i].length();
		}
	}
	return min;
}



bool allContainsPrefix(string arr[], int n, string str,int start, int end)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = start; j <= end ; j++)
		{
			if (arr[i][j] != str[j])
			{
				return false;
			}
		}
	}
	return false;
}


string commonPrefix(string arr[], int n)
{
	int index = findMinLength(arr, n);
	string prefix;

	int low = 0 , high = index;

	while (low<= high)
	{
		int mid = low + (high-low)/2;
		if (allContainsPrefix(arr  , n , arr[0] , low , mid ))
		{
			prefix = prefix  + arr[0].substr(low , mid-low+1);
			low = mid+1;
		}
		else
		{
			high = mid -1;
		}

		
	}
	return prefix;
}




int main()
{  
	 string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof (arr) / sizeof (arr[0]);
 
    string ans = commonPrefix(arr, n);
 
    if (ans.length())
        cout << "The longest common prefix is "
             << ans;
    else
        cout << "There is no common prefix";
	

	system("pause");
	return 0;
}