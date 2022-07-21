#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include<unordered_map>
#include <set>

using namespace std;


class Graph
{
private:
	int V;
	list<int> * adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

//void Graph::BFS(int s)
//{
//	bool * visited = new bool[V];
//	for (int i = 0; i < V; i++)
//	{
//		visited[i] = false;
//	}
//	list<int> queue;
//	visited[s] = true;
//	queue.push_back(s);
//
//	list<int> ::iterator itr;
//	while (!queue.empty())
//	{
//		s = queue.front();
//		cout << s << " ";
//		queue.pop_front();
//
//		for  (itr=adj[s].begin(); itr!=adj[s].end() ; ++itr )
//		{
//			if (!visited[*itr])
//			{
//				visited[*itr] = true;
//				queue.push_back(*itr);
//			}
//		}
//	}
//}



void Graph::BFS(int s)
{
	bool * visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	queue<int> q;


	visited[s] = true;
	q.push(s);
	while (!q.empty())
	{
		s = q.front();
		cout << s << " ";
		q.pop();
		for (list<int>::iterator itr = adj[s].begin();  itr!= adj[s].end(); ++itr)
		{
			if (!visited[*itr])
			{
				visited[*itr] = true;
				q.push(*itr);
			}
		}
	}

}

//Following is Breadth First Traversal (starting from vertex 2)
//2 0 3 1
int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);
	system("pause");
	return 0;
}




