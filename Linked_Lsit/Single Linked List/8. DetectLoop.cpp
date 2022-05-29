#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;


//class Node
//{
//public:
//	int data;
//	Node * next;
//};
//
//
//void push(Node ** head_ref, int data)
//{
//	Node  *  temp = new Node;
//	temp->data = data;
//	temp->next = *head_ref;
//	*head_ref = temp;
//}
//
//
//// Method 1 : using hash
//bool detectLoop(Node * h)
//{
//	unordered_set <Node *> s;
//
//	while ( h!= NULL)
//	{
//		if (s.find(h) != s.end())
//		{
//			return true;
//		}
//
//		s.insert(h);
//		h = h->next;
//	}
//	return false;
//}
//
//

// Method 2 : modifying the linked list data structure. 
//class Node 
//{
//public:
//	int data;
//	Node * next;
//	int flag;
//};
//
//void push(Node ** head_ref, int data)
//{
//	Node * node = new Node;
//	node->data = data;
//	node->flag = 0;
//	node->next = *head_ref;
//	*head_ref = node;
//}
//
//bool detectLoop2(Node * h)
//{
//	while (h != NULL)
//	{
//		if (h->flag ==1)
//		{
//			return 1;
//		}
//		h->flag = 1;
//		h = h->next;
//	}
//	return false;
//}


// Method 3 : floyd's cycle 
class Node
{
public:
	int data;
	Node * next;
};

void push(Node ** head_ref, int data)
{
	Node * temp = new Node;
	temp->data = data;
	temp->next = *head_ref;
	*head_ref = temp;
}


int detectLoop(Node * node)
{
	Node * slow_p = node;
	Node  * fast_p = node;

	while (slow_p && fast_p && fast_p->next != NULL)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if (slow_p == fast_p)
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	Node* head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	head->next->next->next->next = head;


	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";
	system("pause");
	return 0;
}


