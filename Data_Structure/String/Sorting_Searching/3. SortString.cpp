#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

// Method 1 
//void sortString(string & str)
//{
//	sort(str.begin(), str.end());
//	cout << str << " ";
//}


const int MAX_CHAR = 26;
// Method 2
void sortString(string &str)
{
	int charCount[MAX_CHAR] = { 0 };
	for (int i = 0; i < str.length(); i++)
	{
		charCount[str[i] - 'a']++;
	}

	// print
	for (int i = 0; i < MAX_CHAR; i++)
	{
		cout << charCount[i] << " ";
		//for (int j = 0; j< charCount[i]; j++)
		//{
		//	cout << (char)('a' + i);
		//}
	}

}
int main() 
{
	
	string s = "geeksforgeeks";
	sortString(s);
	system("pause"); 
	return 0;
}


