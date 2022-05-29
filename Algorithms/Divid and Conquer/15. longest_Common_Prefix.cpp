#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;





string commonPrefixUtil(string str1, string str2)
{
	string result;
	int n1 = str1.length(), n2 = str2.length();

	for (int i = 0 , j = 0  ; i <= n1-1 && j <=n2-1; i++ , j++)
	{
		if (str1[i] != str2[j])
		{
			break;
		}
		result.push_back(str1[i]);
	}
	return result;
}




string commonPrefix(string arr[], int low, int high)
{
	if (low== high)
	{
		return arr[low];
	}

	if (low  < high)
	{
		int mid = low + (high - low) / 2;

		string str1 = commonPrefix(arr, low, mid);
		cout << "str1 " << str1 << endl;
		string str2 = commonPrefix(arr, mid + 1, high);
		cout << "str2 " << str2 << endl;


		

		return commonPrefixUtil(str1, str2);
	}

}

int main() 
{
	
	string arr[] = { "geeksforgeeks", "geeks",
					"geek", "geezer" };
	int n = sizeof(arr) / sizeof(arr[0]);

	string ans = commonPrefix(arr, 0, n - 1);

	if (ans.length())
		cout << "The longest common prefix is "
		<< ans;
	else
		cout << "There is no common prefix";
	system("pause"); 
	return 0;
}


