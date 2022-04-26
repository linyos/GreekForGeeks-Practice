#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

class Node
{
public:
	int data;
	Node * next; 
};


void removeDuplicates(Node* head)
{
	Node * current = head;

	Node * next_next;
	if (current==NULL)
	{
		return;
	}


	while (current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
		}
		else
		{
			current = current->next;
		}
	}

}



void push(Node ** head_ref, int data)
{
	Node * temp = new Node;
	temp->data = data;

	temp->next = *head_ref;
	*head_ref = temp;
}



void printList(Node * head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}




// Recursive Approach
void removeDuplicates1(Node* head)
{
	Node * to_free; 
	if (head== NULL)
	{
		return;
	}
	if (head->next != NULL)
	{
		if ( head->data == head->next->data )
		{
			to_free = head->next;
			head->next = head->next->next;
			free(to_free);
			removeDuplicates1(head);
		}
		else
		{
			removeDuplicates1(head->next);
		}

	}
}

// Using map
void removeDuplicates2(Node* head)
{
	unordered_map< int, bool > track;
	Node * temp = head;

	while (temp)
	{
		if (track.find(temp->data)==track.end())
		{
			cout << temp->data << " ";
		}
		track[track->data] = true;
		temp = temp->next;
	}


}


int main() 
{
	Node* head = NULL;

	/* Let us create a sorted linked list to test the functions
	Created linked list will be 11->11->11->13->13->20 */
	push(&head, 20);
	push(&head, 13);
	push(&head, 13);
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);

	cout << "Linked list before duplicate removal ";
	printList(head);

	/* Remove duplicates from linked list */
	removeDuplicates(head);

	cout << "\nLinked list after duplicate removal ";
	printList(head);
	system("pause");
	return 0;
}




