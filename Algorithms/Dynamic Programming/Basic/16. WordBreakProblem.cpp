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
#include <bitset>

using namespace std;



// Method : Recursive
int dictionaryContains(string word)
{
	string dictionary[] = { "mobile","samsung","sam","sung",
							"man","mango","icecream","and",
							 "go","i","like","ice","cream" };

	int size = sizeof(dictionary) / sizeof(dictionary[0]);

	for (int i = 0; i < size; i++)
	{
		if (dictionary[i].compare(word) == 0)
			return true;
	} 
	return false;
}

bool wordBreak(string s)
{
	int size = s.size();
	if (size == 0)  return true;
	for (int i = 1; i <= size; i++)
	{
		if (dictionaryContains(s.substr(0, i)) &&
			wordBreak(s.substr(i, size - i)))
			return true;
	}
	return false;
}





// Method:  DP

// Return true if string can be segmented into space separated word.
// otherwise return false;
bool wordBreakDP(string s )
{
	int size = s.size();
	if (size == 0) return true;
	// size =12


	// Create the DP table to stroe result of subproblem
 	bool wb[12+1];

	memset(wb, 0, sizeof(wb));  // Initialize all values as false.


	for (int i = 1; i <= size ; i++)
	{
		// if wb[i] is false, then check if current prefix can make it true.
		// Current prefix is "str.substr(0, i)"
		if (wb[i] == false && dictionaryContains(s.substr(0, i)))
			wb[i] = true;

		// wb[i] is true, then check for all substrings starting from
		// (i+1)th character and store their results.
		if (wb[i] == true)
		{
			// If we reached the last prefix
			if (i==size)
				return true;

			for (int j = i+1; j <= size; j++)
			{
				if (wb[j]==false && dictionaryContains(s.substr(i , j-1)))
				{
					wb[j] = true;
				}

				// If we reached the last character
				if (j==size && wb[j]== true)
				{
					return true;
				}
			}

		}

	}

	return false;

	
}






int main()
{
	wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";


	wordBreakDP("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";


	//wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
	//wordBreak("") ? cout << "Yes\n" : cout << "No\n";
	//wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
	//wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
	//wordBreak("samsungandmangok") ? cout << "Yes\n" : cout << "No\n";

	system("pause");
	return 0;
}
