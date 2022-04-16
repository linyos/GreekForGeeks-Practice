#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include "memory.h"
using namespace std;

class Graph
{
private:
	int V;
	list<int> * adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	// Modify
	void DFS(); // print all vertices in DFS manner
	// prints all not yet visited 
	void DFSUtil(int s, vector<bool> &visited);


};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}



// Modification of the above Sol:
void Graph::DFSUtil(int s, vector<bool> &visited)
{
	stack<int> st;
	st.push(s);
	while (!st.empty())
	{
		int s = st.top();
		st.pop();
		if (!visited[s])
		{
			cout << s << " ";
			visited[s] = true;
		}


		for (auto i = adj[s].begin() ; i != adj[s].end() ; i++ )
		{
			if (!visited[*i])
			{
				st.push(*i);
			}
		}
	}
}



void Graph::DFS()
{
	vector<bool > visited (V, false);
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			DFSUtil(i, visited);
		}
	}
}

int main() {
	Graph g(5);  // Total 5 vertices in graph
	//g.addEdge(1, 0);
	//g.addEdge(2, 1);
	//g.addEdge(3, 4);
	//g.addEdge(4, 0);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 4);
	cout << "Following is Depth First Traversal\n";
	//g.DFS(0);
	g.DFS();
	system("pause");
	return 0;
}




