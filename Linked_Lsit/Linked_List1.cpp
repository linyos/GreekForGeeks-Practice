#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class  Node
{
public:
	int data;
	Node *next;
};
void push(Node ** head_ref, int data) {

	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void InsertAfter(Node * prev, int data) {
	if (prev == NULL)
	{
		cout << "List is empty. \n";
		return;
	}

	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = prev->next;

	// Make next of new node as next of prev node
	new_node->next = prev->next;
	// Move the next node of prev node 
	// as new node
	prev->next = new_node;



}

void printList(Node * head) {
	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	if (head == NULL)
	{
		cout << "NULL";
	}
}

void Push_back(Node ** head, int data) {
	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;

	// If the Linked List is empty.
	// the new node as head.
	if (*head == NULL)
	{

		*head = new_node;
		return;
	}

	Node *last = *head;
	// Travers all the node when the last node
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}



int main() {

	Node * head = NULL;
	push(&head, 1);
	InsertAfter(head, 2);


	Push_back(&head, 3);


	printList(head);

	system("pause");
	return 0;
}
