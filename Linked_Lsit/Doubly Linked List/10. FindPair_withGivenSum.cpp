#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include <set>


using namespace std;

class Node
{
public:
	int data;
	Node * next, *prev;
};

void pairSum(Node * head, int x)
{
	// Set two pointer, first to the beginning of DLL
	// and second to the end of DLL
	Node * first = head;  // head of tthe node list.
	Node * second = head; // last of the node list.
	// Move second to last node
	while (second->next != NULL)
	{
		second = second->next;
	}

	bool found = false;
	// The loop terminates when two pointers cross each other
	// (second->next == first) && (first==second)
	while ( first != second && second->prev != first)
	{
		if ((first->data + second->data)==x)
		{
			found = true;
			cout << "(" << first->data << ", " << second->data << ")" << endl;

			first = first->next;
			second = second->prev;
		}
		else
		{
			if ((first->data + second->data) < x )
			{
				first = first->next;
			}
			else
			{
				second = second->prev;
			}
		}
	}

	if (found==false)
	{
		cout << "No Pair found";
	}
}


void insert(Node ** head_ref , int data)\
{
	Node * temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;

	if (!(*head_ref))
	{
		*head_ref = temp;
	}
	else
	{
		temp->next = *head_ref;
		(*head_ref)->prev = temp;
		*head_ref = temp;
	}

}



void printList(Node * head)
{
	Node * temp = head;

	while (temp!= NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}



int main() {
	Node * head = NULL;
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);


	printList(head);

	int x = 7;

	pairSum(head, x);
	system("pause");
	return 0;
}




