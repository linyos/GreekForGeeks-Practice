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


class Graph
{
	int V;
	list<int> *adj;
	bool isCycleUtil(int v , bool visited[] , bool *rs);
public:
	Graph(int V);
	void addEdge(int v , int w);
	bool isCyclic();
};


Graph::Graph(int V)
{
	this->V = V;
	adj= new list<int>[V];
}

void Graph::addEdge(int v , int w)
{
	adj[v].push_back(w);
}

// This function is a variation of DFSUtil()
bool Graph::isCycleUtil(int v , bool  visited[] , bool * recStack)
{
	if (visited[v] == false)
	{
		 // Mark the current node as visited and part of recursion stack
		visited[v]=true;
		recStack[v] = true;	

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i ; 
		for (i = adj[v].begin();  i !=  adj[v].end(); i++)
		{
			if (!visited[*i] && isCycleUtil(*i , visited , recStack))
			{
				return true;
			}
			else if (recStack[*i])
			{
				return true;
			}
		}
	}
	// remove the vertex from recursion stack
	recStack[v] = false;
	return false;
}




bool Graph::isCyclic()
{
	bool * visited = new bool[V];
	bool * recStack = new bool [V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}
	 // Call the recursive helper function to detect cycle in different
    // DFS trees
	for (int i = 0; i < V; i++)
	{
		if (!visited[i] && isCycleUtil(i , visited , recStack))
		{
			return true;
		}
	}
	return false;

}

int main()
{  
	    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
   

	system("pause");
	return 0;
}