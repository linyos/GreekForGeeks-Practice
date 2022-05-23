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
	temp->data=data;
	temp->next = *(head_ref);
	*(head_ref) = temp;
}


void printList(Node * node)
{
	while (node != NULL)
	{
		cout<< node->data <<" ";
		node=  node->next;
	}
	cout<<endl;
}


int countNodes(Node * s)
{
	int count = 0;
	while (s != NULL)
	{
		count++;
		s= s->next;
	}
	return count;
}


void swapKth(Node ** head_ref, int k)
{
	int n = countNodes(*head_ref);

	// check if k is valid
	if (n < k ) return;


	// If x (kth node from start) and y(kth node from end)
    // are same
	if (2 * k -1 == n) return ;
	// Find the kth node from the beginning of the linked list
	// we also find previous of kth node become we need to update next pointer of the prevous
	Node * x = *head_ref;
	Node * x_prev = NULL;
	for (int i = 1; i < k; i++)
	{
		x_prev = x ;
		x = x->next;
	}

	//find the kth node from end and its previous.
	// kth nodes from end is (n-k+1)th node from beginning
	Node * y = *head_ref;
	Node * y_prev = NULL;
	for (int i = 1; i < n-k+1; i++)
	{
		y_prev = y;
		y = y->next;
	}

	if (x_prev)
	{
		x_prev ->next = y;
	}

	if (y_prev)
	{
		y_prev->next =x;
	}

	Node * temp  = x->next;
	x->next = y ->next;
	y->next = temp;

	if (k ==1)
	{
		*head_ref = y ;
	}
	if (k==n)
	{
		*head_ref = x;
	}
}






int main()
{ 
	Node * head= NULL;
	for (int i = 8; i >=1 ; i--)
	{
		push(&head , i);
	}
	 cout << "Original Linked List: ";
    printList(head);

	int k = 2;
	swapKth(&head , k);
	cout << "\nModified List for k = " << k << endl;
	printList(head);


	system("pause");
	return 0;
}