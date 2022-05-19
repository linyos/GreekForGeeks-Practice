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

using namespace std;






string secMostRepeated(vector<string> seq)
{
	 // Store all the words with its occurence
	unordered_map < string , int > map;
	for (int i = 0; i < seq.size(); i++)
	{
		map[seq[i]]++;
	}


	 // find the second largest occurrence
	int first_max = INT_MIN  , sec_max = INT_MIN;
	for (auto it = map.begin() ; it !=map.end() ; it++ )
	{
		if (it->second > first_max)
		{
			sec_max = first_max;
			first_max = it->second;
		}
		else if (it->second  > sec_max && it->second != first_max)
		{
			sec_max = it->second;
		}
	}

	// return string with occurrence equals to sec_max
	for (auto it = map.begin() ; it != map.end() ; it++)
	{
		if (it->second == sec_max)
		{
			return it->first;
		}
	}

}










int main()
{


	/* vector<string> seq = { "ccc", "aaa", "ccc",
                          "ddd", "aaa", "aaa" };
*/
	//vs 2012
	vector<string > seq ;

	seq.push_back("ccc");
	seq.push_back("aaa");
	seq.push_back("ccc");
	seq.push_back("ddd");
	seq.push_back("aaa");
	seq.push_back("aaa");

	for (auto i = seq.begin() ; i!= seq.end() ; i++)
	{
		cout << *i << " ";
	}
	cout<<endl;


	 cout << secMostRepeated(seq);
	system("pause");
	return 0;
}