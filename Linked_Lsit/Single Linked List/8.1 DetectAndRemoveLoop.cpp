#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

class Node{
public:
	int data;
	Node * next;
};


void removeLoop(Node * loop_node, Node * head);


int detectAndRemoveLoop(Node * node)
{
	Node * slow_p = node;
	Node * fast_p = node;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		
		if (slow_p == fast_p)
		{
			removeLoop(slow_p, fast_p);
			return 1;
		}
	}
	return 0;


}


/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(Node * loop_node, Node * head)
{
	Node * ptr1 = loop_node;
	Node * ptr2 = loop_node;

	// Count the number of nodes in loop
	int k = 1, i;
	while ( ptr1->next != ptr2)
	{
		ptr1 = ptr1->next;
		k++;
	}
	// Fix one pointer to head
	ptr1 = head;
	// And the other pointer to k nodes after head
	ptr2 = head;
	for ( i = 0; i < k ; i++)
	{
		ptr2 = ptr2->next;
	}
	/*  Move both pointers at the same pace,
	 they will meet at loop starting node */
	while ( ptr2 != ptr1)
	{
		ptr1 = ptr1->next; 
		ptr2 = ptr2->next;
	}

	// Get pointer to the last node
	while (ptr2->next != ptr1)
	{
		ptr2 = ptr2->next;
	}
	/* Set the next node of the loop ending node
   to fix the loop */
	ptr2->next = NULL;

}



Node*  newNode( int data)
{
	Node  * temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return  temp;
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

	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);

	cout << "Linked List after removing loop \n";
	printList(head);

	system("pause"); 
	return 0;
}


