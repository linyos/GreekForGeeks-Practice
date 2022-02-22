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

void moveToFront(Node ** head_ref)
{
	if ((* head_ref) == NULL || (*head_ref)->next ==NULL)
	{
		return;
	}

	Node * secLast = NULL;
	Node  * last = *head_ref;


	while (last->next != NULL)
	{
		secLast = last;
		last = last->next;
	}

	secLast->next = NULL;
	last->next = *head_ref;
	*head_ref = last;



}



void push(Node ** head_ref, int d)
{
	Node  * node = new Node();
	node->data = d;
	node->next = (*head_ref);
	(*head_ref) = node;
}


void printList(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}


int main() {
	Node *start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5 */
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	cout << "Linked list before moving last to front\n";
	printList(start);

	moveToFront(&start);
	/* The constructed linked list is:
	5->1->2->3->4- */
	cout << "\nLinked list after removing last to front\n";
	printList(start);
	system("pause");
	return 0;
}




