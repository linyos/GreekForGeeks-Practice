#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include<cassert>

using namespace std;

class Graph
{
private:
	 int  V;
	list<int> * adj;
public:
	Graph(int V);
	void addEdge(int v ,int w);
	int BFS(int s ,  int l);
};


Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}


void Graph:: addEdge(int v , int w)
{
	// Add w to v��s list.
	adj[v].push_back(w);
	// Add v to w's list.
	adj[w].push_back(v);
}


int Graph::BFS(int s  ,int l)
{
	bool * visited = new bool[V];
	int * level= new int [V];

	for (int i = 0; i < V; i++)
	{
		visited[i] =false;
		level[i] = 0;
	}
	  // Create a queue for BFS
	list<int> queue;
	// Mark the current node as
    // visited and enqueue it
	visited[s] =true;
	queue.push_back(s);
	level[s] = 0 ;

	while (!queue.empty())
	{
		s =queue.front();
		queue.pop_front();

		for (auto i =adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				level[*i] = level[s]+1;
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	int count =0;
	for (int i = 0; i < V; i++)
	{
		if (level[i]==l)
		{
			count++;
		}
	}
	return count;

}

int  main() {
	 Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
 
    int level = 2;
 
    cout << g.BFS(0, level);
 
	system("pause");
	return 0;
}



