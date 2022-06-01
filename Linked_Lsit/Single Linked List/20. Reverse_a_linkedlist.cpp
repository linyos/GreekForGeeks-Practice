#include <iostream>
#include<queue>

using namespace std;

// Introduction
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
void printList(Node * head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void reverse(Node ** head_ref)
{
	Node * current = *head_ref;
	Node * next = NULL;
	Node * prev = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;

	}
	*head_ref = prev;
}

int main() {

	Node * head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printList(head);


	reverse(&head);
	printList(head);

	system("pause");
	return 0;
}




