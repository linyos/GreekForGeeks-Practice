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
	Node * prev , * next;
};


void deleteNode (Node ** head_ref , Node * delVal){

	if (*head_ref == NULL || delVal ==NULL)
	{
		return ;
	}

	if (*head_ref == delVal)
	{
		*head_ref = delVal->next;
	}

	// Change next only if node to be deleted is NOT the last node
	if (delVal->next != NULL)
	{
		delVal->next->prev= delVal->prev;
	}

	//Change prev only if node to be deleted is NOT the first node
	if (delVal ->prev != NULL)
	{
		delVal->prev->next = delVal->next;
	}
	//Free memory occupied bt del
	free(delVal);
}


void deleteAllOccurOfX (Node ** head_ref , int x ){

	if ((*head_ref)==NULL)
	{
		return ;
	}
	Node * current = *head_ref;
	Node * next ;

	while (current != NULL)
	{
		if (current->data ==x)
		{
			next = current->next;
			deleteNode(head_ref , current);
			current = next;
		}
		else
		{
			current = current->next;
		}
	}
}




void push (Node ** head , int data){
	Node * newNode = new Node();
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = (*head);
	if ((*head) !=NULL)
	{
		(*head)->prev = newNode;
	}
	(*head) = newNode;
}




void printList (Node * head){
	while (head !=NULL)
	{
		cout<<head->data <<" ";
		head= head->next;
	}
	cout<<endl;
}

int main (){
	Node * head = NULL;
	push(&head, 2);
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    push(&head, 2);
    push(&head, 2);

	  cout << "Original Doubly linked list:n";
    printList(head);
   int x = 2;
  
    /* delete all occurrences of 'x' */
    deleteAllOccurOfX(&head, x);
  
    cout << "\nDoubly linked list after deletion of "
         << x << ": ";
    printList(head);


	system("pause");
	return 0 ;
}