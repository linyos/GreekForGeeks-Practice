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


void search(char * pat, char * txt)
{
	int M = strlen(pat); // "AABA";
	int N = strlen(txt); // "AABAACAADAABAAABAA";
	
	for (int i = 0; i <= N-M ; i++)
	{
		int j;
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;
		if (j == M)
			cout << "Pattern found at index " << i << endl;
	}
}


int main() 
{
	char pat[] = "AABA";
	char txt[] = "AABAACAADAABAAABAA";
	
	search(pat, txt);
	system("pause"); 
	return 0;
}



