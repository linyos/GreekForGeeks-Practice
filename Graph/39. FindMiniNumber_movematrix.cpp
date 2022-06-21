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



# define N 4

class Graph
{
	int V;
	list <int> *adj;
public:
	Graph(int V);
	void addEdge(int v ,int w);
	int BFS(int s , int d);
};



Graph::Graph(int V)
{
	this->V= V;
	adj= new list<int>[V];
}


void Graph :: addEdge ( int v, int w)
{
	adj[v].push_back(w);
}

bool isSafe (int i , int j , int M[][N])
{
	if ((i < 0 || i>= N) || (j<0 || j>=N) || M[i][j]==0) 
		return false;
	
	return true;
}




int Graph:: BFS (int s , int d)
{
	// Base Case
	if (s==d)
		return 0;
	// make initial distance of all vertex -1 from source
	int * level = new int [V];
	for (int i = 0; i < V; i++)
		level[i] = -1;

	// Create a queue for BFS
	list<int> q;
	// Mark the source node level[s] ='0'
	level[s] = 0;
	q.push_back(s);

	while (!q.empty())
	{
		// Dequeue a  vertex from queue
		s =q.front();
		cout << s << " " ;
		q.pop_front();

		for (list<int>::iterator itr = adj[s].begin() ; itr!= adj[s].end() ; itr++)
		{
			// Else ,continue to do  BFS
			if (level[*itr] < 0 || level[*itr] > level[s]+1 )
			{
				// add level count 
				level[*itr] = level[s] +1;
				q.push_back(*itr);
			}
		}
	}
	// return mini moves from source to sink
	return level[d];
}


// Return mini numebr of moves from a source to a destination
int MinimumPath(int M[][N])
{
	 // source and destination
	int s , d ;
	int V = N*N+2;
	Graph g(V);

	// Create graph with  n*n node
	// each cell consider as node.
	int k=1;// Number of current vertex

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (M[i][j]!=0)
			{
				// connect all 4 adjacent cell to
				// current cell
				if (isSafe(i , j+1 , M))
				{
					g.addEdge(k , k+1);
				}
				if (isSafe(i , j-1 , M))
				{
					g.addEdge(k , k-1);
				}
				if (j < N-1 && isSafe(i+1 ,j , M))
				{
					g.addEdge(k , k+N);
				}
				if (i>0 && isSafe(i-1 , j , M))
				{
					g.addEdge(k , k-N);
				}
			}

			// source index
			if (M[i][j]==1)
			{
				s = k;
			}
			// Destination index
			if (M[i][j]==2)
			{
				d = k;
			}
			k++;
		}
	}
		// find minimum moves
	return g.BFS (s, d) ;
}



int main()
{  
	int M[N][N] = 
		{{ 3 , 3 , 1 , 0 },
		{ 3 , 0 , 3 , 3 },
		{ 2 , 3 , 0 , 3 },
		{ 0 , 3 , 3 , 3 }
	};

		cout << MinimumPath(M) << endl;
	
	system("pause");
	return 0;
}