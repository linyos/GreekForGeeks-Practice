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

// Method 2 Using Local References. 
Node* sortedIntersect(Node *a  , Node * b )
{
	Node * result = NULL;
	Node ** lastPtrRef = & result;

	while (a!= NULL && b!= NULL)
	{
		if (a->data==b->data)
		{
			push (lastPtrRef , a->data);
			lastPtrRef = &((*lastPtrRef)->next);
			a= a->next;
			b=b->next;
		}
		else if (a->data < b->data)
		{
			a=a->next;
		}
		else
		{
			b=b->next;
		}
	}
	return result;
}

// Method 3 : Uisng Recursive solution
Node * sortedIntersect( Node* a, Node* b)
{
	if (a==NULL || b==NULL)
	{
		return NULL;
	}
	if (a->data < b->data)
	{
		return  sortedIntersect(a->next , b);
	}
	if (a->data > b->data)
	{
		return  sortedIntersect(a , b->next);
	}
	Node * temp = new Node ;
	temp->data =a->data;
	temp->next= sortedIntersect(a->next , b->next);
	return temp;
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



// Method (Using Revise Method 1 
Node * sortedIntersect(Node * a, Node * b)
{
	Node * temp = new Node;
	while (a != NULL && b != NULL)
	{
		if (a->data == b->data)
		{
			push(&temp, a->data); 
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
	// print List
	while (tmpe->next != NULL)
	{
		cout<<temp->data << " ";
		temp = temp->next;
	}
	cout<<endl;


	return temp;
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

/*
Linked list containing common items of a & b 
2 4 6 
*/



