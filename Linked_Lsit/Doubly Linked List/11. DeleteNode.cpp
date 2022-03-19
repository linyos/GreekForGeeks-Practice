#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include <set>


using namespace std;

class Node
{
public:
	int data;
	Node * next, *prev;
};

void deleteNode(Node ** head_ref, Node * del)
{
	if (* head_ref == NULL || del==NULL)
	{
		return;
	}
	if (*head_ref== del)
	{
		*head_ref = del->next;
	}

	// Change next noly if ndoe to be deleted is NOT 
	// the last node.
	if (del->next != NULL)
	{
		del->next->prev = del->prev;
	}

	if (del->prev != NULL)
	{
		del->prev->next = del->next;
	}
	free(del);
}

void deleteNodeAtGivenPos(Node ** head_ref, int  n)
{
	if (*head_ref == NULL || n <= 0)
	{
		return;
	}
	Node * current = *head_ref;
	int i;

	for (int i = 1; current != NULL && i < n; i++)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		return;
	}

	deleteNode(head_ref, current);
}

void push(Node ** head_ref, int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = *head_ref;

	if ((*head_ref)!= NULL)
	{
		(*head_ref)->prev = newNode;
	}
	*head_ref = newNode;
}

void printList(Node * head)
{
	Node * temp = head;

	while (temp!= NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}



int main() {
	Node * head = NULL;
	push(&head, 5);
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);
	cout << "Doubly linked list before deletion:n\t";
	printList(head);

	int n = 2;
	deleteNodeAtGivenPos(&head, n);
	cout << "\nDoubly linked list after deletion:n\t";
	printList(head);


	system("pause");
	return 0;
}




