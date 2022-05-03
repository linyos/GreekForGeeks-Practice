#include <iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};




void swapNodes(Node ** head_ref, int x, int y)
{
	if (x == y) return;

	// Search for x 
	Node * prevX = NULL;
	Node * currX = *head_ref;
	while (currX && currX->data != x)
	{
		prevX = currX;
		currX = currX->next;
	}

	// Search for y 
	Node * prevY = NULL;
	Node * currY = *head_ref;
	while (currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	// If either x or y is not present, nothing to do.
	if (currX == NULL || currY == NULL)
	{
		return;
	}
	// If x is not head of linked list
	if (prevX != NULL)
	{
		prevX->next = currY;
	}
	else // else make y as new head
	{
		*head_ref = currY;
	}
	if (prevY != NULL)
	{
		prevY->next = currX;
	}
	else
	{
		*head_ref = currX;
	}

	// Swap next pointer
	Node * temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

void push(Node ** head_ref, int data)
{
	Node * node = new Node;
	node->data = data;
	node->next = *head_ref;
	*head_ref = node;
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


int main() 
{
	Node * start = NULL;
	/* The constructed linked list is:
	1->2->3->4->5->6->7 */
	push(&start, 7);
	push(&start, 6);
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);
	cout << "Linked list before calling swapNodes() ";
	printList(start);

	swapNodes(&start, 4, 3);

	cout << "\nLinked list after calling swapNodes() ";
	printList(start);

	system("pause");
	return 0;
}


