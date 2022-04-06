#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include<unordered_map>
#include <set>
#include <stack>
#include <string>

using namespace std;

void addEdge(vector<int > adj[], int src, int dest)
{
	adj[src].push_back(dest);
}


void displayGraph(vector<int> adj[], int v)
{
	for (int i = 0; i < v; i++)
	{
		cout << i << " --> ";
		for (int j = 0; j < adj[i].size(); j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}

}

void transposeGraph(vector<int> adj[], vector<int> transpose[], int v)
{
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			addEdge(transpose, adj[i][j], i);
		}
	}

}


int main() {

	const int v = 5;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 0, 3);
	addEdge(adj, 2, 0);
	addEdge(adj, 3, 2);
	addEdge(adj, 4, 1);
	addEdge(adj, 4, 3);



	displayGraph(adj, v);

	vector<int> transpose[v];



	transposeGraph(adj, transpose, v);
	cout << "Transpose: " << endl;
	displayGraph(transpose, v);


	system("pause");
	return 0;
}




