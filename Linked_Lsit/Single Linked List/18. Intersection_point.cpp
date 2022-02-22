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



int getCount(Node * head)
{
	Node * current = head;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return count;
}


/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */

int _getIntesectionNode(int d, Node * head1, Node * head2)
{

	Node * current1 = head1;
	Node * current2 = head2;

	// Move the pointer forward
	for (int i = 0; i < d; i++)
	{
		if (current1 == NULL)
		{
			return -1;
		}
		current1 = current1->next;
	}

	// Move both pointers of both list till they
	// intersect with each other


	while (current1 != NULL && current2 != NULL)
	{
		if (current1 == current2)
		{
			return current1->data;
		}

		current1 = current1->next;
		current2 = current2->next;
	}

	return -1;
}



int getIntesectionNode(Node * head1, Node * head2)
{
	int c1 = getCount(head1);
	int c2 = getCount(head2);

	int d;
	if (c1 > c2)
	{
		d = c1 - c2;
		return _getIntesectionNode(d, head1, head2);
	}
	else
	{
		d = c2 - c1;
		return _getIntesectionNode(d, head2, head1);
	}


}


Node* intersectPoint(Node* head1, Node* head2)
{
	Node * ptr1 = head1;
	Node * ptr2 = head2;

	if (ptr1 == NULL || ptr2 == NULL)
	{
		return NULL;
	}

	// Traverse through the lists until they
	// reach Intersection node
	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		// If at any node ptr1 meets ptr2, then it is
	   // intersection node.Return intersection node.

		if (ptr1 == ptr2)
		{
			ptr1 = head2;
		}
		// When ptr1 reaches the end of a list, then
	   // reassign it to the head2.
		if (ptr1 == NULL)
		{
			ptr1 = head2;
		}
		// When ptr2 reaches the end of a list, then
		// redirect it to the head1.
		if (ptr2 == NULL)
		{
			ptr2 == head1;
		}
	}

	return ptr1;
}



void printList(Node * node)
{
	if (node == NULL)
	{
		cout << "NULL";
		while (node->next != NULL)
		{
			cout << node->data << " ";
			node = node->next;
		}
	}
	cout << node->data << endl;

}


int main() {

	Node* newNode;

	// Addition of new nodes
	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	cout << "The node of intersection is " << getIntesectionNode(head1, head2);
	system("pause");
	return 0;
}




