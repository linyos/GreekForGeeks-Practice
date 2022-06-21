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

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int v , vector<bool> &visited );
public:
	Graph(int V);
	void addEdge(int v , int w);
	int findMother();
};

Graph::Graph(int V)
{
	this->V= V;
	adj = new list<int>[V];
}



void Graph::addEdge(int v , int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v , vector<bool> &visited)
{
	visited[v] = true;

	for (list<int> :: iterator  itr = adj[v].begin();  itr != adj[v].end() ; itr++ )
	{
		if (!visited[*itr])
		{
			DFSUtil(*itr , visited);
		}
	}
}



int  Graph::findMother()
{


	// Visited [] is used for DFS.
	// Initially all are initialized as not visited
	vector<bool> visited (V , false);


	// To store last finished vertex (or mother vertex)
	int v = 0;



	// Do DFS traversal and find the last finished vertex.
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
		{
			DFSUtil(i , visited);
			v = i ;
		}
	}


	// Reset all values in visited as fasle and do DFS beginning from v to check if all
	// vertices are reachable from it or not .
	fill(visited.begin() , visited.end() , false);

	DFSUtil(v , visited);
	for (int i = 0; i < V; i++)
	{
		if (visited[i]==false)
		{
			return -1;
		}
	}
	return v;
 }


int main()
{  
		Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(6, 4);
	g.addEdge(5, 6);
	g.addEdge(5, 2);
	g.addEdge(6, 0);

	cout << "A mother vertex is " << g.findMother();
	system("pause");
	return 0;
}