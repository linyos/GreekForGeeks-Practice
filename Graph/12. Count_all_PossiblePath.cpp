#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include<cassert>

using namespace std;

class Graph
{
public:
	Graph(int v);
	void add_edge(int src , int dst);
	int count_paths(int src , int dst ,int  v);

private:
	int m_vertices;
	list<int> * m_neig;
	void path_counter (int src , int dst , int & path_count , vector<bool> & visited);
};


Graph::Graph(int v)
{
	m_vertices = v;
	m_neig = new list<int>[v];
}


void Graph::add_edge(int src , int dst)
{
	m_neig[src].push_back(dst);
}


int Graph::count_paths(int src , int dst , int v)
{
	int path_count= 0;
	vector<bool> visited (v ,false);
	path_counter(src , dst  , path_count , visited);
	return path_count;
}




void Graph::path_counter(int src , int dst , int & path_count , vector<bool> & visited)
{
	visited[src] = true;
	if (src==dst)
	{
		cout<<s <<endl;
		path_count++;
	}
	else
	{cout<< s << " -> ";
		for (auto i = m_neig[src].begin() ; i!= m_neig[src].end() ; i ++ )
		{
			if (!visited[*i])
			{
				path_counter( *i ,dst , path_count , visited);
			}
		}
	}
	visited[src]= false;
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



