#include <iostream>
#include <queue>
#include <string >


using namespace std;


class Node
{
public:
	int data;
	Node * next;
};



void push (Node ** head_ref , int data){
	Node * ptr1 = new Node();
	ptr1->data = data;
	ptr1->next = * head_ref;

	if (*head_ref != NULL)
	{
		Node * temp = *head_ref;
		while (temp->next != *head_ref)
		{
			temp = temp->next ;
		}
		temp->next = ptr1;
	}
	else
	{
		ptr1->next = ptr1;
	}
	*head_ref = ptr1;
}


void printList (Node * head){
	Node * temp = head;
	if (head != NULL)
	{
		do
		{
			cout<<temp->data <<" ";
			temp = temp->next;
		} while (temp != head);
	}
	cout<<endl;
}


void deleteNode (Node ** head , int key){
	// IF linked list is empty
	if (*head ==NULL)
	{
		return;
	}

	// If the list contains only a single node
	if ((*head)->data ==key && (*head)->next ==*head)
	{
		free(*head);
		*head=NULL;
		return;
	}

	Node * last = * head , *d ;

	// If head is to be deleted. 
	if ((*head)->data == key)
	{
		// Find the last node of the list 
		while (last ->next != *head)
		{
			last = last->next ;
		}
		// Point last node to the next of head the second node of the list
		last ->next = (*head)->next;
		free(*head);
		*head = last->next;
		return;
	}

	// Either the node to be deleted is not found 
	// or the end of list is not reached.
	while (last->next != * head && last->next->data != key)
	{
		last = last->next ;
	}
	if (last->next->data == key)
	{
		d= last->next ;
		last->next = d->next;
		free(d);
	}
	else
	{
		cout<<"No such keyfound";
	}
}


int main(){

	Node * head = NULL;
	push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);
 
    cout << "List Before Deletion: ";
    printList(head);

	
    deleteNode(&head, 7);
 
    cout << "List After Deletion: ";
    printList(head);
	system("pause");
	return 0 ;
}