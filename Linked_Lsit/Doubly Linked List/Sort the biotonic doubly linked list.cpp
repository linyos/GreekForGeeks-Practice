#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include<queue>
#include <set> 
#include <iomanip>
#include <unordered_set>
using namespace std;


class Node
{
public:
	int data;
	Node * next;
	Node * prev;

};




void reverse (Node ** head_ref){

	Node * temp = NULL;
	Node * current = *head_ref;

	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
	{
		*head_ref = temp->prev;
	}

}



Node * merge (Node * first , Node * second){

	if (!first)
	{
		return second;
	}
	if (! second)
	{
		return first;
	}

	if (first->data < second->data)
	{
		first->next = merge(first->next , second);
		first->next->prev = first ;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first , second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}

}


//Function to sort a biotonic doubly linked list 
Node * sort (Node * head){
	if (head==NULL || head->next == NULL)
	{
		return head;
	}

	Node * current  = head->next;
	while (current != NULL)
	{
		if (current->data < current->prev->data)
		{
			break;
		}
		current= current->next;
	}


	if (current ==NULL)
	{
		return head;
	}

	current->prev ->next = NULL;
	current->prev = NULL;

	 // reverse the list starting with 'current'
	reverse(& current);
	return merge(head, current);
}



void push (Node **head_ref , int data){

	Node * node = new Node();
	node->data= data ;
	node->prev =NULL;

	node->next = *head_ref;

	if ((*head_ref ) != NULL)
	{
		(*head_ref)->prev = node;
	}

	*head_ref = node;

}

void printList (Node * head){

	while (head != NULL)
	{
		cout<<head->data<<" ";
		head= head->next;
	}
	cout<<endl;

}


int main (){

	struct Node* head = NULL;
 
    // Create the doubly linked list:
    // 2<->5<->7<->12<->10<->6<->4<->1
    push(&head, 1);
    push(&head, 4);
    push(&head, 6);
    push(&head, 10);
    push(&head, 12);
    push(&head, 7);
    push(&head, 5);
    push(&head, 2);
 
    cout << "Original Doubly linked list:n";
    printList(head);
 
    // sort the biotonic DLL
    head = sort(head);
 
    cout << "\nDoubly linked list after sorting:n";
    printList(head);
	system("pause");
	return 0 ;
}