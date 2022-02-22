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

void push(Node ** head_ref, int d)
{
	Node  * node = new Node();
	node->data = d;
	node->next = (*head_ref);
	(*head_ref) = node;
}
Node * sortedIntersect(Node * a, Node * b)
{
	Node dummy;
	Node * tail = &dummy;
	dummy.next = NULL;

	while (a != NULL && b != NULL)
	{
		if (a->data == b->data)
		{
			push((&tail->next), a->data); 
			tail = tail->next;
			a = a->next;
			b = b->next;
		}
		else if (a->data < b->data)
		{
			a = a->next;
		}
		else
		{
			b = b->next;
		}
	}
	return (dummy.next);
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
	Node* a = NULL;
	Node* b = NULL;
	Node* intersect = NULL;

	/* Let us create the first sorted
	 linked list to test the functions
	 Created linked list will be
	 1->2->3->4->5->6 */
	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	/* Let us create the second sorted linked list
   Created linked list will be 2->4->6->8 */
	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	/* Find the intersection two linked lists */
	intersect = sortedIntersect(a, b);

	cout << "Linked list containing common items of a & b \n";
	printList(intersect);


	system("pause");
	return 0;
}




