#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *  next;
	Node * prev;
};

void Swapp(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

Node * lastNode(Node * root) {
	while (root && root->next)
	{
		root = root->next;
	}
	return root;
}

// Last element as pivot, places the pivot element at its correct position.

Node * partition(Node * l, Node * h) {
	int x = h->data;

	Node * i = l->prev;

	for (Node * j = l ; j != h ; j =j->next)
	{
		if (j->data <= x )
		{
			i = (i == NULL) ? l : i->next;
			Swapp(&(i->data), &(j->data));
		}
	}
	i = (i == NULL) ? l : i->next; // similar to i++
	Swapp( &(i->data) , &(h->data));

	return i;

}


void _quickSort(Node * l, Node * h) {
	if (h != NULL && l != h && l != h->next)
	{
		Node * p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}



void quickSort(Node * head) {
	// Find last node
	Node * h = lastNode(head);

	// Call the recursive QuickSort
	_quickSort(head, h);
}




void push(Node ** head_ref, int data) {
	Node * newnode = new Node();
	newnode->data = data;

	newnode->prev = NULL;
	newnode->next = (*head_ref);

	if ((*head_ref) != NULL)
	{
		(*head_ref)->prev = newnode;
	}

	(*head_ref) = newnode;
}

void printList(Node * head) {
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node * a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);
	cout << "Linked List before sorting \n";
	printList(a);

	quickSort(a);

	cout << "Linked List after sorting \n";
	printList(a);
	
	system("pause");
	return 0;
}