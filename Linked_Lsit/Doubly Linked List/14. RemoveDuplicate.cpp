#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
	Node * prev;
};




void deleteNode(Node ** head_ref, Node * del)
{
	if (*head_ref==NULL || del==NULL)
	{
		return;
	}

	if (* head_ref == del)
	{
		*head_ref = del->next;
	}
	
	if (del->next  != NULL)
	{
		del->next->prev = del->prev;
	}
	if (del->prev != NULL)
	{
		del->prev->next = del->next;
	}

	free(del);
}




void removeDuplicates(Node ** head_ref)
{
	if (* head_ref==NULL)
	{
		return;
	}
	Node * current = *head_ref;
	Node * next;

	while (current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			deleteNode(head_ref, current->next);
		}
		else
		{
			current = current->next;
		}
	}
}

void push(Node  ** head_ref, int data)
{
	Node * node = new Node();
	node->data = data;
	node->prev = NULL;
	node->next = *head_ref;

	if ((*head_ref) != NULL)
	{
		(*head_ref)->prev = node;
	}

	*head_ref = node;

}

void printList(Node * node)
{

	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}



int main() {
	Node* head = NULL;
	push(&head, 12);
	push(&head, 12);
	push(&head, 10);
	push(&head, 8);
	push(&head, 8);
	push(&head, 6);
	push(&head, 4);
	push(&head, 4);
	push(&head, 4);
	push(&head, 4);


	cout << "Original Doubly linked list: ";
	printList(head);

	/* remove duplicate nodes */
	removeDuplicates(&head);

	cout << "\nDoubly linked list after"
		" removing duplicates: ";
	printList(head);

	system("pause");
	return 0;
}




