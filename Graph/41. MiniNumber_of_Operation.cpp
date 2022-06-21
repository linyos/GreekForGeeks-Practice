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

struct  node
{
	int val;
	int level;
};


// Method 1 : BFS
int minOperations (int x , int y)
{
	// To keep track of visited numbers in BFS
	set<int> visit;

	// Create a queue and enqueue x into it.
	queue<node> q;
	node n = {x , 0};
	q.push(n);

	// Do DFS starting from x  
	while (!q.empty())
	{
		// Remove an item from queue;
		node t  = q.front();
		q.pop();
		// If the removed item is target 
		// number y , return its level
		if (t.val == y)
			return t.level;

		// Make dequeued number as visited
		visit.insert(t.val);
		// If we can reach y in one more step
		if (t.val * 2 == y || t.val-1==y)
			return t.level+1;


		// Insert children of t if not visited already
		if (visit.find(t.val *2 ) == visit.end())
		{
			n.val = t.val*2;
			n.level = t.level+1;
			q.push(n);
		}

		if (t.val-1 >=0 && visit.find(t.val-1) == visit.end())
		{
			n.val = t.val-1;
			n.level= t.level+1;
			q.push(n);
		}

	}

}





int main()
{  
	int x = 2, y = 5;
	cout << minOperations(x, y);

	system("pause");
	return 0;
}