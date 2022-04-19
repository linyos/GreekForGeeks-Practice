#include <iostream>
#include <vector>


using namespace std;


const int Size= 26;



void  longestSubseqWithK(string str , int k )
{
	int n = str.size();

	int freq[Size] = {0};
	for (int i = 0; i < n; i++)
	{
		freq[str[i]-'a']++;
	}



	for (int i = 0; i < n; i++)
	{
		if (freq[str[i]-'a'] >=k)
		{
			cout<< str[i] ; 
		}
	}
}



int  main() {
	
	string str = "geeksforgeeks";
    int k = 2;
    longestSubseqWithK(str, k);     
	
	system("pause");
	return 0;
}



