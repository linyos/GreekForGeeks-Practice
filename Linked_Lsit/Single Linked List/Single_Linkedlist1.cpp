#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};


void push(Node ** head_ref, int data){

	Node * new_node = new Node();
	new_node->data = data;
	
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


void insertAfter(Node * prev, int data) {
	
	if (prev == NULL)
	{
		return;
	}

	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = prev->next;
	prev->next = new_node;
}

void append(Node ** head_ref, int data) {
	// allocate node
	Node * newNode = new Node();
	// Used in step 5.
	Node * last = *head_ref;

	newNode->data = data;
	newNode->next = NULL;

	if (*head_ref ==NULL)
	{
		*head_ref = newNode;
		return;
	}
	// 5. Else traverse till the last node
	while (last ->next !=NULL)
	{
		last = last->next;
	}

	last->next = newNode;
	return;

}

void deleteNode(Node ** head_ref, int key)
{
	Node* temp = *head_ref;
	Node * prev = NULL;

	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;
		delete temp;
		return;
	}
	else
	{
		while (temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;

		delete temp;
	}
}


void printList(Node * node) {
	while (node != NULL)
	{
		cout << node->data << " -> ";
		node = node->next;
	}
	cout << endl; 

}

int main() {
	/* Start with the empty list */
	Node* head = NULL;

	// Insert 6. So linked list becomes 6->NULL
	append(&head, 6);

	// Insert 7 at the beginning.
	// So linked list becomes 7->6->NULL
	push(&head, 7);

	// Insert 1 at the beginning.
	// So linked list becomes 1->7->6->NULL
	push(&head, 1);

	// Insert 4 at the end. So
	// linked list becomes 1->7->6->4->NULL
	append(&head, 4);

	// Insert 8, after 7. So linked
	// list becomes 1->7->8->6->4->NULL
	insertAfter(head->next, 8);

	cout << "Created Linked list is: ";
	printList(head);

	system("pause");
	return 0;
}