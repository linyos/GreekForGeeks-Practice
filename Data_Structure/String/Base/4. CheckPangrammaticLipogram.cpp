#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>

using namespace std;

const int MAX_CHAR = 26;

string missingChars(string str)
{
	bool persent[MAX_CHAR] = { false };
	for (int i = 0; i < str.length(); i++)
	{
		if ('a' <= str[i]&& str[i] <= 'z')
		{
			persent[str[i] - 'a'] = true;
		}
		else if ('A' <= str[i]&& str[i]<='Z')
		{
			persent[str[i] - 'A'] = true;
		}
	}

	string res = "";
	for (int i = 0; i <MAX_CHAR; i++)
	{
		if (persent[i]==false)
		{
			res.push_back((char)(i + 'a'));
		}
	}
	return res;

}

int main() 
{
	string str = "The quick brown fox jumps "
		"over the dog";
	cout << missingChars(str);

	system("pause");
	return 0;
}


