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
	int V;
	list <int> * adj;

public:
	Graph(int v);
	void  add_edge(int src, int dst);
	int count_paths(int src, int dst, int v);
	void path_counter(int src, int dst, int & path_count, vector<bool> & visited);
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int>[v];
}
void Graph::add_edge(int v, int w)
{
	adj[v].push_back(w);
}

int Graph::count_paths(int s, int d, int v)
{
	int path_count = 0;
	vector<bool> visited(v, false);
	path_counter(s, d, path_count, visited);
	return path_count;
}



void Graph::path_counter(int s, int d, int & path_count, vector < bool> & visited)
{
	visited[s] = true;
	if (s == d)
	{
		cout << s << endl;
		path_count++;
	}
	else
	{
		cout << s << " --> ";
		for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (!visited[*i])
			{
				path_counter(*i, d, path_count, visited);
			}
		}
	}
	visited[s] = false;
}


//
//void Graph::path_counter(int src , int dst , int & path_count , vector<bool> & visited)
//{
//	visited[src]=true;
//	if (src==dst)
//	{
//		path_count ++ ;
//	}
//	else
//	{
//		for (auto neighbor : m_neig[src])
//		{
//			if (!visited[neighbor])
//			{
//				path_counter(neighbor , dst , path_count,visited);
//			}
//		}
//	}
//	visited[src] =false;
//}
//




int  main() {
	 Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(2, 1);
    g.add_edge(3, 2);
    // Validate it...
    cout << g.count_paths(0, 4, 5);
 
	system("pause");
	return 0;
}



