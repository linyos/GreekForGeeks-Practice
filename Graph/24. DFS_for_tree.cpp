#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>

using namespace std;

void dfs(vector<int> list[], int node, int arrival)
{
	cout << node << '\n';
	for (int i = 0; i < list[node].size(); i++)
	{
		if (list[node][i] != arrival)
		{
			dfs(list, list[node][i], node);
		}
	}
}



int main()
{
	int nodes = 5;

	vector<int> list[10000];

	list[1].push_back(2);
	list[1].push_back(3);

	//list[2].push_back(1);
	list[2].push_back(4);

	//list[3].push_back(1);
	list[3].push_back(5);

	//list[4].push_back(2);
	//list[5].push_back(3);
	

	dfs(list, 1, 0);
	system("pause");
	return 0;
}
