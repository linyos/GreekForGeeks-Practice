#include <iostream>
#include <string>
#include <vector>
using namespace std;



void sort(string s[], int n)
{
	for (int i = 1;  i < n;  i++)
	{
		string temp = s[i];
		int j = i - 1;
		while (j >=0 && temp.length()< s[j].length())
		{
			s[j + 1] = s[j];
			j--;
		}
		s[j+ 1] = temp;
	}
}

void printArray(string str[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << " ";
	}
}

int main() {
	
	string arr[] = { "GeeksforGeeks", "I", "from", "am" };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function to perform sorting
	sort(arr, n);

	printArray(arr, n);
	system("pause");
	return 0;
}




