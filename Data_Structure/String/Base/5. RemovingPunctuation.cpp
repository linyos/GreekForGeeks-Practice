#include <iostream>
#include <string>
#include <vector>
using namespace std;




int main() {
	string str= "Welcome???@@##$ to#$% Geeks%$^for$%^&Geeks";
	for (int i = 0 ,len=str.size(); i < len  ;i++)
	{
		if (ispunct(str[i]))
		{
			str.erase(i--, 1);
			len = str.size();
		}
	}

	cout << str << endl;

	string str1 = "ABCD";
	str1.erase(1, 1);
	cout << str1;
	system("pause");
	return 0;
}




