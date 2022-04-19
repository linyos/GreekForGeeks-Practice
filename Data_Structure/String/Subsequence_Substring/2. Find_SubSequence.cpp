#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>

using namespace std;




bool isSubSequence(char str1[], char str2[], int m, int n)
{
	int j = 0;

	for (int i = 0; i < n &&  j < m  ; i++)
	{
		if (str1[j]==str2[i])
		{
			j++;
		}

	}
	return (j == m);
}


int main() {

	char str1[] = "gksrek";
	char str2[] = "geeksforgeeks";
	int m = strlen(str1);
	int n = strlen(str2);
	isSubSequence(str1, str2, m, n) ? cout << "Yes "
		: cout << "No";
	system("pause");
	return 0;
}




