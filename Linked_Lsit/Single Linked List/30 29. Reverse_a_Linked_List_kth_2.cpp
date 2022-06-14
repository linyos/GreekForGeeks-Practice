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
#include <ctime>
#include <time.h>
#include <stack>


using namespace std;


class Node
{
public:
	int data;
	Node * next ;
};



void push (Node ** head_ref , int data)
{
	Node * temp = new Node;
	temp->data=data;
	temp->next = *head_ref;
	*head_ref  = temp;
}



void printList (Node * head)
{
	while (head != NULL)
	{
		cout << head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

/* Reverses the linked list in groups of size k
and returns the pointer to the new head node. */
Node * Reverse (Node * head , int k )
{
	stack< Node * > mystack;
	Node * curr = head;
	Node * prev = NULL;

	while (curr != NULL)
	{
		int count = 0 ;
		// Terminate the loop whichever comes first
		// either current == NULL or count >= k
		while (curr != NULL && count < k )
		{
			mystack.push (curr);
			curr= curr->next;
			count++;
		}
		
		// Now pop the elements of stack one by one
		while (mystack.size() > 0)
		{
			// If final list has not been started yet.
			if (prev == NULL)
			{
				prev= mystack.top();
				head = prev;
				mystack.pop();
			}
			else
			{
				prev ->next = mystack.top();
				prev = prev->next;
				mystack.pop();
			}
		}
	}

	// Next of last element will point to NULL 
	prev->next = NULL;
	return head;
}


int main()
{  
	Node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("\nGiven linked list \n");
	printList(head);
	head = Reverse(head, 3);

	printf("\nReversed Linked list \n");
	printList(head);



	system("pause");
	return 0;
}