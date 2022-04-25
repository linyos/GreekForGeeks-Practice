#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;



class Node
{
public:
	int data;
	Node * next;
	Node * prev;
};



void push(Node ** head_ref, int data)
{
	Node * temp = new Node;
	temp->data = data;
	temp->prev = NULL;
	temp->next = *head_ref;

	if (*head_ref!=NULL )
	{
		(*head_ref)->prev = temp;
	}
	*head_ref = temp;
}




int findSize(Node * node)
{
	int res = 0;
	while (node != NULL)
	{
		res++;
		node = node->next;
	}

	return res;
}




void printList(Node * head)
{
	Node * temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() 
{
	Node * head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	printList(head);
	cout << "find list size: " << findSize(head) << endl;
	system("pause");
	return 0;
}




