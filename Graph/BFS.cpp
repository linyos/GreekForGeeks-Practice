#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using	namespace std;


class Graph
{
	int V;
	list <int > * adj;

public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);
};

 Graph::Graph(int V) {
	this->V = V;
	adj = new list<int >[V];
}


 void Graph::addEdge(int v, int w) {
	 adj[v].push_back(w);
 }


 void Graph::BFS(int s) {
	 // Mark all the vertices as not visited
	 bool *visited = new bool[V];
	 for (int i = 0; i < V; i++)
	 {
		 visited[i] = false;
	 }

	 // Create a queue for BFS
	 list<int > queue;
	 // Mark the current node as visited and enqueue it
	 visited[s] = true;
	 queue.push_back(s);
	 // "i" will be used to get all adjacent vertices of a vertex 
	 list <int > ::iterator i;
	 while (!queue.empty())
	 {
		 s = queue.front();
		 cout << s << " ";
		 queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited, then mark it visited and enqueue it.
		 for ( i = adj[s].begin() ; i != adj[s].end() ; i++)
		 {
			 cout << "*i" << *i << endl;
			 if (! visited[*i])
			 {
				 visited[*i] = true;
				 queue.push_back(*i);
			 }
		 }


	 }

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

	//Graph g(9);
	//g.addEdge(0, 1);g.addEdge(0, 2); g.addEdge(0, 3);
	//g.addEdge(1, 0); g.addEdge(1, 4);
	//g.addEdge(2, 0); g.addEdge(2, 4); g.addEdge(2, 5); g.addEdge(2, 6), g.addEdge(2, 7);
	//g.addEdge(3, 0); g.addEdge(3, 7);
	//g.addEdge(4, 1);g.addEdge(4, 2); g.addEdge(4, 5);
	//g.addEdge(5, 2); g.addEdge(5, 2); g.addEdge(5, 8);
	//g.addEdge(6, 2); g.addEdge(6, 7); g.addEdge(6, 8);
	//g.addEdge(7,2); g.addEdge(7, 3); g.addEdge(7, 6);
	//g.addEdge(8, 5); g.addEdge(8, 6);



	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);



	system("pause");
	return 0;

}

