#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};



void push(Node ** head_ref, int data) {
	Node *  node = new Node();
	node->data = data;
	node->next = (*head_ref);
	*head_ref = node;
}


int getCount(Node * head) {
	int count = 0;
	Node * current = head;
	while (current !=NULL)
	{
		count++;
		current = current->next;
	}

	return count;

}

int main() {


	/* Start with the empty list */
	Node* head = NULL;

	/* Use push() to construct below list
	1->2->1->3->1 */
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);

	/* Check the count function */
	cout << "count of nodes is " << getCount(head);

	system("pause");
	return 0;
}