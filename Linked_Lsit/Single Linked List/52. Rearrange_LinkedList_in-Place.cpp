#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};


void push(Node ** head_ref, int data)
{
	Node * node = new Node;
	node->data = data;
	node->next = *head_ref;
	*head_ref = node;
}

void printNode(Node * head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}


void reverseList(Node ** head)
{
	Node * prev = NULL, *next = NULL;
	Node * curr = *head;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}



void rearrange(Node ** head)
{

	// 1. Find the middle point using tortoise and hare method
	Node * slow = *head;
	Node * fast = slow->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	// 2. Split the linked list in two halves
	// head1 , head of first half  1 -> 2 -> 3
	// head2 , head of second half 4 -> 5
	Node * head1 = *head;
	Node * head2 = slow->next;
	slow->next = NULL;

	// 3. Reverse the second half, 4->3
	reverseList(&head2);

	// 4. Merge alternate nodes;
	push(head, 0);

	// Assign dummy node
	// curr is the pointer to this dummy node, which will be used to
	// from the new list.
	Node * curr = *head;
	while (head1 || head2)
	{
		// First add the element from list
		if (head1)
		{
			curr->next = head1;
			curr = curr->next;
			head1 = head1->next;
		}
		// Add the element from the second list
		if (head2)
		{
			curr->next = head2;
			curr = curr->next;
			head2 = head2->next;
		}

	}

	*head = (*head)->next;
}

int main()
{
	Node * head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printNode(head);
	rearrange(&head);
	printNode(head);





	system("pause");
	return 0;
}
