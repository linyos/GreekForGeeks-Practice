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



// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char * pat, int M, int * lps)
{
	int len = 0;
	lps[0] = 0;// lps[0] is always 0
	int  i = 1;
	// the loop calculates lps[i] for i = 1 to M-1
	while (i < M)
	{
		//cout << "pat[i]: "<<" " << i << " "<< pat[i] << " pat[len] "<<" " << len << " "<< pat[len] << endl;
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else  // (pat[i] != pat[len])
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPsearch(char * pat, char * txt)
{
	int N = strlen(txt);
	int M = strlen(pat);
	

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	// M = 4;
	int lps[5];
	
	computeLPSArray(pat, M, lps);
	int i = 0;
	int j = 0; 

	//while (j < M )
	//{
	//	cout << lps[j] << endl;
	//	j++;
	//}
	//i = 0;
	//j = 0;

	while (i < N)
	{
		if (pat[j]== txt[i])
		{
			i++;
			j++;
		}
		if (j==M)
		{
			printf("\nFound pattern at index %d ", i - j);
			j = lps[j - 1];
		}
		// mismatch after j matches
		else if (i < N && pat[j] != txt[i])
		{
			// Do not match lps[0...lps[j-1]] character.
			// they will match anyway.
			if (j !=0)
			{
				j = lps[j - 1];
			}
			else
			{
				i = i + 1;
			}
		}
	}
	
	


}




int main() 
{
	char txt[] = "AABAACAADAABAABA";
	char pat[] = "AABAA";
	KMPsearch(pat, txt);
	system("pause"); 
	return 0;
}


