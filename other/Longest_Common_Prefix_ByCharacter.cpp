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
	int min = arr[0].length();
	
	for (int i = 1; i < n; i++)
	{
		if (arr[i].length() < min)
		{
			min = arr[i].length();
		}
	}
	return min;
}

string commonPrefix(string arr[] , int n )
{
	int minlen = findMinLength(arr,  n);

	string result;
	char current ;

	for (int i = 0; i < minlen; i++)
	{
		current = arr[0][i];
		
		for (int j = 1; j < n; j++)
		{
			if (arr[j][i] != current)
			{
				return result;
			}
		}
		result.push_back(current);
	}
	return result;
}




// Method 2 ( STL 

int shortest_string (string s[] , int n )
{
	int minLength = INT_MAX , min_index;

	for (int i = 0; i < n; i++)
	{
		if (s[i].length() < minLength)
		{
			minLength = s[i].length();
			min_index = i ; 
		}
	}
	return min_index;
}


string findprefix(string s[], int n)
{
	  // index of the smallest string
	int  shortest_string_index = shortest_string(s, n);


	while ( s[shortest_string_index].length() > 0 )
	{
		int count = 0 ;
		for (int i = 0; i < n; i++)
		{
			 // checking whether all strings have prefix which is equal to smallest string 

			cout << s[i]<<endl;
			if (s[i].find(s[shortest_string_index])==0 )
			{
				count++;
			}
		}
		if (count==n)
		{
			  cout << "longest common prefix is: " << endl;
			  return s[shortest_string_index];
			  break;
		}
		// deleting the last character of the smallest string 
		s[shortest_string_index].pop_back();
	}

	return "no common prefix among all strings";

}






int main()
{  

	  string s[]= { "geeksforgeeks", "geeks", "geek", "geezer" };
    int n = sizeof(s) / sizeof(s[0]);
    // function call
    cout << findprefix(s, n);



	system("pause");
	return 0;
}