#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>


using namespace std;

class Node
{
public:
	int data;
	Node * next;
};

void push (Node ** head  , int data)
{
	Node * ptr1 = new Node;
	Node * temp = *head;

	ptr1->data=data;
	ptr1->next= *head;

	if (*head != NULL)
	{
		while (temp->next != *head)
		{
			temp=	temp ->next ;
		}
		temp->next = ptr1;
	}
	else
	{
		ptr1->next= ptr1;
	}
	*head = ptr1;
}



void reverse(Node ** head)
{
	if (*head==NULL)
	{
		return;
	}

	Node * prev = NULL;
	Node * current =*head;
	Node * next;

	do
	{
		next = current->next;
		current->next= prev;
		prev= current;
		current= next;
	} while (current != *head);

	(*head)->next =prev;
	(*head)  = prev;
}
void printList (Node * node)
{
	Node * current = node;
	if (node != NULL)
	{
		do
		{
			cout<<current->data<<" ";
			current= current->next;
		} while (current != node);
		cout<<endl;
	}


}



int main()
{
	Node  * node = NULL;
	push(&node , 5);
	push(&node , 4);
	push(&node , 3);
	push(&node , 2);
	push(&node , 1);


	printList(node);


	reverse(&node);
	printList(node);
	
	system("pause");
	return 0;
}