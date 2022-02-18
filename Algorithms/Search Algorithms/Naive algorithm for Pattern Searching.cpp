#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using	namespace std;


void search(char * pat, char * txt) {
	int M = strlen(pat);

	cout << " M " << M << endl;
	int N = strlen(txt);

	cout << " N "<< N << endl;
	for (int i = 0; i <= N-M ; i++)
	{
		int j;
		for ( j = 0; j < M; j++)
		{
			cout << "txt: " << txt[i + j] << i+j << endl;
			if (txt[i+j] != pat[j])
			{
				break;
			}

		}
		if (j==M)
		{
			cout << "Pattern found at index " << i << endl;
		}
	}


}


int main()
{
	char txt[] = "AABAACAADAABAAABAA";
	char pat[] = "AABA";
	search(pat, txt);


	system("pause");
	return 0;
	
}


