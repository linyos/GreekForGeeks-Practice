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


bool isReversible(string &str)
{
	int i = 0, j = str.length()-1;

	while (i < j )
	{
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}



int main() 
{
	string str = "aba";
	if (isReversible(str))
		cout << "YES";
	else
		cout << "NO";


	system("pause"); 
	return 0;
}


