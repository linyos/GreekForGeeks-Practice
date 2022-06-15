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
#include <time.h>
#include <stack>


using namespace std;


vector<string>  find(vector<string> &list1, vector<string> &list2)
{
	unordered_map <string , int > map;
	for (int i = 0; i < list1.size(); i++)
	{
		map[list1[i]]++;
	}

	vector<string > res;

	int minsum = INT_MAX;
	for (int j = 0; j < list2.size(); j++)
	{
		
		if (map.count(list2[j]))
		{
			 // j : 2   map[list2[j]]: 1   
			int sum  = j + map[list2[j]];

		
			// If current sum is smaller than minsum
			if (sum < minsum)
			{
				minsum = sum;
				res.clear();
				res.push_back(list2[j]);
			}
			// if index sum is same then put this
			// string in resultant list as well
			else if (sum == minsum)
				res.push_back(list2[j]);
		}
	}
	return res;
}




int main()
{  


	vector<string> list1;
	list1.push_back("GeeksforGeeks");
	list1.push_back("Udemy");
	list1.push_back("Coursera");
	list1.push_back("edX");

	// Creating list2
	vector<string> list2;
	list2.push_back("Codecademy");
	list2.push_back("Khan Academy");
	list2.push_back("GeeksforGeeks");


	vector<string>  res =  find(list1, list2);


	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";


	system("pause");
	return 0;
}