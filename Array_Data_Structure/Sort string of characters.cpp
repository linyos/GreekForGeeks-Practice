#include <iostream>
#include <string>
#include<algorithm>



using namespace std ;


const int MAX_CHAR = 26;

void sortString (string &str){
	int charCount[MAX_CHAR] ={0};

	for (int i = 0; i < str.length(); i++)
	{
		charCount[str[i]-'a']++;
	}


	for (int i = 0; i < MAX_CHAR; i++)
	{
		for (int j = 0; j < charCount[i]; j++)
		{
			cout<<(char)('a' + i);
		}
	}
}




int main(){



	string s ="geeksforgeeks";
	 sortString(s);
	system("pause");
	return 0;
}