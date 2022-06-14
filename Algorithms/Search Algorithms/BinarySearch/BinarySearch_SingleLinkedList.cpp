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

class Node
{
public:
	int data;
	Node * next;
};


Node *newNode (int data)
{
	Node * temp = new Node;
	temp->data=data;
	temp->next=NULL;
	return temp;
}

Node * middle(Node * start , Node * last)
{
	if (start == NULL)
		return NULL;

	Node * slow= start;
	Node * fast = start->next;

	while (fast != last)
	{
		fast = fast->next;
		if (fast != last)
		{
			slow = slow->next;
			fast= fast->next;

		}
	}

	return slow;
}

 Node* binarySearch(Node *head, int value)
 {
	 Node * start = head;
	 Node * last = NULL;

	 do
	 {
		 // Fimd middle
		 Node * mid = middle(start , last);

		 if (mid == NULL)
			 return NULL;

		 if (mid ->data == value)
			return mid;

		 else if (mid->data < value)
			 start = mid->next;
		 else 
			 last = mid;

	 } while (last == NULL || last != start);
	 return NULL;
 }



int main()
{  
	


	system("pause");
	return 0;
}