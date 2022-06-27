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

void pairWiseSwap(Node * head)
{
	Node * temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		swap(temp->data, temp->next->data);
		temp = temp->next->next;
	}


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
	Node* start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5 */
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	cout << "Linked list "
		<< "before calling pairWiseSwap()\n";
	printList(start);

	pairWiseSwap(start);

	cout << "\nLinked list "
		<< "after calling pairWiseSwap()\n";

	//2 1 4 3 5
	printList(start);
	system("pause");
	return 0;
}




