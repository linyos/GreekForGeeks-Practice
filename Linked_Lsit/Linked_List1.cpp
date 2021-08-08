#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


//struct node
//{
//	int data;
//	struct  node *prev;
//	struct node * next;
//};
//struct node * head;
//void insertbeginning(int item) {
//	struct node * ptr = (struct node *) malloc(sizeof(node));
//	if (ptr==NULL){
//		cout << "Overflow. \n";
//	}
//	else
//	{
//		if (head==NULL)
//		{
//			ptr->next = NULL;
//			ptr->prev = NULL;
//			ptr->data = item;
//			head = ptr;
//		}
//		else
//		{
//			
//			ptr->data = item;
//			ptr->prev = NULL;
//			ptr->next = head;
//			head = ptr;
//		}
//	}
//}


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
