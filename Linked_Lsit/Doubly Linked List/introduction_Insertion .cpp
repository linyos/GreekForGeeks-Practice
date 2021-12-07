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


void push (Node ** head_ref , int newdata){
	// 1. allocate node
	Node * new_node = new Node();
	// 2. put in the data
	new_node->data = newdata;

	// 3. Make next of new node as head and prevous as null
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	//4. Change prev of head node to new node. 
	if ((*head_ref)!= NULL)
	{
		(*head_ref)->prev = new_node;
	}

	// 5. move the head to print to the new node.
	(*head_ref) = new_node;
}


void insertAfter(Node * pre_node , int new_data){
	
	if (pre_node == NULL)
	{
		 cout<<"the given previous node cannot be NULL";
        return;
	}
	// 2. allocate new node
	Node * new_node = new Node();
	// 3. put in the data
	new_node->data = new_data;
	// 4. Make next of new node as next of prev_node
	new_node->next = pre_node->next;
	// 5. Make the next of prevnode as new node 
	pre_node->next = new_node;
	// 6. Make prev_node as previous of new node.
	new_node->prev = pre_node;

	// 7. change previous of new node next node 
	if (new_node->next != NULL)
	{
		new_node->next->prev = new_node;
	}
	
}


void append (Node ** head_ref  , int data){
	Node * new_node = new Node();
	Node * last = * head_ref;
	new_node->data = data;

	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		new_node->prev =NULL;
		*head_ref = new_node;
		return ;
	}

	while (last->next !=NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	new_node->prev = last;

	return ;


}



void printList (Node * node){

	Node * last ;
	cout<<"\nTraversal in forward direction \n";

	while (node != NULL)
	{
		cout<<" " <<node->data <<" ";
		last = node;
		node = node->next;
	}

	   cout<<"\nTraversal in reverse direction \n";
	   while (last != NULL)
	   {
		   cout<<" " << last->data <<" ";
		   last = last->prev;
	   }
}




int main(){
	Node * head= NULL;
	append(&head , 6);
	 // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
 
    // Insert 7 at the beginning. So
    // linked list becomes 7->6->NULL
    push(&head, 7);
 
    // Insert 1 at the beginning. So
    // linked list becomes 1->7->6->NULL
    push(&head, 1);
 
    // Insert 4 at the end. So linked
    // list becomes 1->7->6->4->NULL
    append(&head, 4);
 
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
 
    cout << "Created DLL is: ";
    printList(head);
 

	
	system("pause");
	return 0;
}