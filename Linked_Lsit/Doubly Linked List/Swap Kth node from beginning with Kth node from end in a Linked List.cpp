#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *  next;
};


void push(Node ** head_ref, int data) {

	Node * node = new Node;
	node->data = data;
	node->next = (*head_ref);
	(*head_ref) = node;
}

void printList(Node * node) {

	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

int countNode(Node * node) {
	int count = 0;
	while (node!= NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}


void swapKth(Node ** head_ref, int k) {
	// Count nodes in linked list
	int n = countNode(*head_ref);

	// Check if k is valid
	if (n < k)
	{
		return;
	}

	// If x and y are same
	if (2 * k - 1 == n)
	{
		return;
	}

	// Find the kth node from the beginning of linked list.
	//We also find previous of kth node become we need to update next  pointer of the previous
	Node * x = (*head_ref);
	Node * x_prev = NULL;

	for (int i = 0; i < k; i++)
	{
		x_prev = x;
		x = x->next;
	}


	//Similarly, find the kth node from end and its previous.
	//kth node from end is (n-k+1)th node from beginning
	Node * y = (*head_ref);
	Node * y_prev = NULL;
	for (int i = 0; i < n-k+1; i++)
	{
		y_prev = y;
		y = y->next;
	}

	if (x_prev)
	{
		x_prev->next = y;
	}
	if (y_prev)
	{
		y_prev->next = x;
	}



	// Sawp next pointer of x and y .
	Node * temp = x->next;
	x->next = y->next;
	y->next = temp;

	// Change head pointer when k is 1 or n 
	if (k==1)
	{
		*head_ref = y;

	}
	if (k==n)
	{
		*head_ref = x;
	}

}


int main() {


	Node * head = NULL;
	for (int i = 8; i >= 1; i--)
	{
		push(&head, i);
	}

	cout << "Original Linked List: ";
	printList(head);

	int k = 2;
	swapKth(&head, k);
	cout << "Modified  List for k = " <<  k<< endl;
	
	printList(head);

	system("pause");
	return 0;
}