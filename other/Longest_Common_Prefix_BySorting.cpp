#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;


string longestCommonPrefix(string ar[], int n)
{
 
    // If size is 0, return empty string
    if (n == 0) return "";
 
    if (n == 1) return ar[0];



	sort (ar , ar+ n);

	int en = min (ar[0].size() , ar[n-1].size());

	// the common prefix in first and last string is the longest common prefix 
	string first =ar[0]  , last = ar[n-1];

	int i = 0 ;

	while ( i < en && first[i] == last[i])
	{
		i++;
	}

	string pre = first.substr(0 , i);
	return pre;
}





int main()
{  

	string ar[] = {"geeksforgeeks", "geeks",
                           "geek", "geezer"};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "The longest common prefix is: " << longestCommonPrefix(ar, n);


	system("pause");
	return 0;
}