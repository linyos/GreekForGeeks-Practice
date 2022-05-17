#include<iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;



class Node
{
public:
	int data;
	Node * next ;
};



void push (Node ** head , int data)
{
	Node * str1 = new Node ;
	Node * temp = *head;

	str1->data=data;
	str1->next = *head;

	if (*head != NULL)
	{
		while (temp->next != * head)
		{
			temp = temp->next;
		}
		temp->next = str1;
	}
	else
	{
		str1->next= str1;
	}
	*head = str1;

}


void traverse (Node * head)
{
	Node * current = head;
	if (head != NULL)
	{
		do
		{
			cout<< current->data<<" ";
			current= current->next;
		} while (current != head);
		cout<<endl;
	}
}



Node * exchangeNode (Node * head)
{
	// list is of length 2
	if (head->next->next == head)
	{
		head =head->next;
		return head;
	}

	Node * p = head;
	while (p->next->next != head)
	{
		p = p->next;
	}

	p->next->next = head->next;
	head->next = p->next;
	p->next = head;
	head = head->next;
	return head;
}






 

/*
1 2 3 4 5 6
6 2 3 4 5 1
*/
int main()
{


	Node * head = NULL;	
	 push(&head , 6);
	 push(&head , 5);
	 push(&head , 4);
	 push(&head , 3);
	 push(&head , 2);
	 push(&head , 1);

	 traverse(head);

	 head = exchangeNode(head);

	 traverse(head);
	system("pause");
    return 0;                           
}