#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;


string missingChars(string str)
{
	bool present[MAX_CHAR] = { false };
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >='a' && str[i]<='z')
		{
			present[str[i] - 'a'] = true;
		}
		else if (str[i]>= 'A' && str[i]<='Z')
		{
			present[str[i] - 'A'] = true;
		}
	}
	// Store missing characters in alphabetic order.
	string res = "";
	for (int i = 0; i < MAX_CHAR; i++)
	{
		if (present[i]==false)
		{
			res.push_back((char)(i + 'a'));
		}
	}
	return res;
}



int main() {

	string str = "The quick brown fox jumps "
		"over the dog";
	cout << missingChars(str);
	system("pause");
	return 0;
}




