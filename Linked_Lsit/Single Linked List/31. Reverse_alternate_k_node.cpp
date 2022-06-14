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

Node  *kAltReverse(Node *head, int k)
{
	Node * current = head;
	Node * next ;
	Node * prev = NULL;
	int count = 0;
	/*1) reverse first k nodes of the linked list */
	while (current !=NULL && count < k)
	{
		next = current->next;
		current->next = prev ;
		prev = current;
		current= next;
		count ++;
	}

	/* 2) Now head points to the kth node.
	So change next of head to (k+1)th node*/
	if (head != NULL)
	{
		head ->next = current;
	}

	/* 3) We do not want to reverse next k nodes.
	So move the current pointer to skip next k nodes */
	count = 0 ;
	while (count< k-1 && current != NULL)
	{
		current= current->next;
		count++;
	}

	/* 4) Recursively call for the list
	starting from current->next. And make
	rest of the list as next of first node */
	if (current != NULL)
	{
		current->next = kAltReverse(current->next , k);
	}


		/* 5) prev is new head of the input list */
	return prev;
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

	cout<<"Given linked list \n";
	printList(head);
	head = kAltReverse(head, 3);

	cout<<"\n Modified Linked list \n";
	printList(head);



	system("pause");
	return 0;
}