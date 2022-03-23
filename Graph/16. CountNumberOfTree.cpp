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

class Graph
{
private:
	int V;
	list<int> * adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFSUtil(int s, vector<bool> &visited);
	int countTrees();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}




void Graph::DFSUtil(int s, vector<bool> &visited)
{
	visited[s] = true;
	for (auto i = adj[s].begin(); i!=adj[s].end(); ++i)	
	{
		if (!visited[*i])
		{
			DFSUtil(*i , visited);
		}
	}
}

int Graph::countTrees()
{
	vector<bool> visited(V, false);
	int res = 0;
	for (int u = 0; u < V; u++)
	{
		if (visited[u] == false)
		{
			DFSUtil(u,visited);
			res++;
		}
	}
	return res;

}



//void Graph::DFSUtil(int s,vector<bool> &visited)
//{
//	visited[s] = true;
//	for (int i = 0; i < adj[s].size(); i++)
//	{
//		if (!visited[adj[s][i]]==false)
//		{
//			DFSUtil(adj[s][i],adj, visited);
//		}
//	}
//
//}
//
//int Graph::countTrees(vector<int> adj[], int V)
//{
//	vector<bool> visited(V, false);
//	int res = 0;
//	for (int u = 0; u < V; u++)
//	{
//		if (visited[u] == false)
//		{
//			DFSUtil(u, adj, visited);
//			res++;
//		}
//	}
//	return res;
//}



int main() {


	Graph g(5);

	int const V = 5;
	vector<int> adj[V];
	g.addEdge( 0, 1);
	g.addEdge( 0, 2);
	g.addEdge( 3, 4);
	cout << g.countTrees();


	system("pause");
	return 0;
}




