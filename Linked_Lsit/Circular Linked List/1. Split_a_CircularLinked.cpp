#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Node
{
public:
	int data;
	Node * next;
};

//  head1_ref and head2_ref are references to head nodes of the resultant linked links
void splitList(Node * head, Node **head1_ref, Node **head2_ref) {

	Node * slow_ptr = head;
	Node *fast_ptr = head;
	if (head == NULL) {
		return;
	}
	// Find  first and second  last node 
	/* If there are odd nodes in the circular list then
	fast_ptr->next becomes head and
	for even nodes fast_ptr->next->next becomes head.
	*/
	while (fast_ptr->next != head && fast_ptr->next->next != head) {
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}

	cout << "Fast: " << fast_ptr->data << " ";
	cout << "Slow: " << slow_ptr->data << " ";
	// If there are even elements in list than move fast_ptr
	if (fast_ptr->next->next == head) {
		fast_ptr = fast_ptr->next;
	}

	// Set the head pointer of first half;
	*head1_ref = head;

	// Set the head pointrt of second half
	if (head->next != head) {
		*head2_ref = slow_ptr->next;
	}
	// Make second half circular.  
	fast_ptr->next = slow_ptr->next;
	// Maek first half circular.
	slow_ptr->next = head;

}

void push(Node **head_ref, int data) {
	Node * ptr1 = new Node();
	Node * temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;
	if (*head_ref != NULL) {
		while (temp->next != *head_ref) {
			temp = temp->next;
		}
		temp->next = ptr1;
	}
	else
	{
		ptr1->next = ptr1;
	}

	*head_ref = ptr1;
}


void printList(Node * head) {
	Node * tmp = head;
	if (head != NULL) {
		do
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		} while (tmp != head);
	}
}

int main() {

	Node * head = NULL;
	Node *head1 = NULL;
	Node *head2 = NULL;
	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);
	push(&head, 16);
	cout << "Contents of Circular Linked List\n ";
	printList(head);
	splitList(head, &head1, &head2);

	cout << "\nFirst Circular Linked List";
	printList(head1);
	cout << "\nSecond Circular Linked List";
	printList(head2);
	system("pause");
	return 0;
}