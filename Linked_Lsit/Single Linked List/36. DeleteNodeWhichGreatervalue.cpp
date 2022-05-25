#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>

using namespace std;



class Node
{
public:
	int data;
	Node * next;

};


void push (Node ** head_ref , int data)
{
	Node * temp = new Node;
	temp ->data= data;
	temp->next = *head_ref;
	*head_ref = temp;
}



// Utility function to reverse a linked list
void reversList (Node ** head)
{
	Node * current = *head;
	Node * prev = NULL;
	Node * next;

	while (current != NULL)
	{
		next = current->next;
		current->next= prev;
		prev = current;
		current= next;	
	}

	*head = prev;

}





void printList (Node * node)
{
	while (node != NULL)
	{
		cout << node->data<<" ";
		node= node->next;
	}
	cout<<endl;
}







// Delete nodes which have greater value nodes on left side.
void  _delLesserNodes( Node* head)
{
	Node * current = head;
	Node * maxnode = head;
	Node * temp ;

	while ( current != NULL && current ->next != NULL)
	{
		// If current is smaller than max then delete current 
		if (current->next->data < maxnode->data)
		{
			temp = current->next;
			current->next= temp->next;
			free(temp);
		}
		else
		{
			 /* If current is greater than max,
            then update max and move current */
			current= current->next;
			maxnode= current;
		}
		
	}

}



void delLesserNodes(Node ** head_ref)
{


	  /* 1) Reverse the linked list */
	reversList(head_ref);


	/*
	2) in the reversed list, delete nodes which have a node with greater value node on left side. 
		Note that head node is never deleted because it is the leftmost node.
	*/
	_delLesserNodes(*head_ref);
	/* 3) Reverse the linked list again to
    retain the original order */



	reversList(head_ref);



}




int main()
{  
	 Node* head = NULL;


	    /* Create following linked list
    12->15->10->11->5->6->2->3 */
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);


	  cout << "Given Linked List \n" ;
    printList(head);
 
    delLesserNodes(&head);
 
    cout << "Modified Linked List \n" ;
    printList(head);
 

	system("pause");
	return 0;
}