#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Node
{
public:
	int data;
	Node * next ;
	Node * prev;
};


void push (Node ** head_ref , int data){
	Node * tmp = new Node();
	tmp->data = data;
	
	tmp->prev = NULL;	
	
	tmp->next = (*head_ref);

	if ((*head_ref) != NULL)
	{
		(*head_ref)->prev = tmp;
	}
	(*head_ref) = tmp;
}





void reverse (Node ** head_ref){

	Node * temp = NULL;
	Node * current = *head_ref;

	// swap next and prev for all nodes of doubly linked list
	while (current != NULL)
	{
		temp = current->prev;
		current ->prev = current->next;
		current->next = temp ;
		current= current->prev;
	}


	// ->prev : reverse direction 
	if (temp != NULL)
	{
		*head_ref = temp->prev;
	}

}

void printList (Node * node){
	while (node != NULL)
	{
		cout<< node->data<<" ";
		node = node->next;
	}

}
int main(){
	Node * head = NULL;
	push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
     
    cout << "Original Linked list" << endl;
    printList(head);
     
    /* Reverse doubly linked list */
    reverse(&head);
     
    cout << "\nReversed Linked list" << endl;
    printList(head);        




	system("pause");
	return 0;
}