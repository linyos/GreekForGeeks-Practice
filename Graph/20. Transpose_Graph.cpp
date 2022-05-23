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

// function to add an edge from vertex source to vertex dest
void addEdge (vector<int> adj[] , int src ,int dest)
{
	adj[src].push_back(dest);
}

// function to print adjacency list of a graph
void displayGraph(vector<int> adj[] , int v)
{
	for (int i = 0; i < v; i++)
	{
		cout<< i <<" --> ";
		for (int j = 0; j < adj[i].size(); j++)
		{
			cout<< adj[i][j]<<" -> ";
		}
		cout<<endl;
	}
	cout << endl;
}


// function to get Transpose of a graph taking adjacency
// list of given graph and that of Transpose graph
void transposeGraph(vector<int> adj[] , vector<int> transpose[] ,int v)
{
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			addEdge(transpose , adj[i][j] , i );
		}
	}
	
}


int main() {

		int v = 5 ;
	vector<int> adj[5];
	addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);
  

	displayGraph(adj , v);

	vector<int> transpose[5];
    transposeGraph(adj, transpose, v);


    displayGraph(transpose, v);

	system("pause");
	return 0;
}




