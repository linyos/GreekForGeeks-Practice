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
void insert(Node ** head, int x)
{
	if ((*head) == NULL)
	{
		(*head) = new Node;
		(*head)->data = x;
		(*head)->next = NULL;
		return;
	}
	Node * temp = new Node;
	temp->data = (*head)->data;
	temp->next = (*head)->next;
	(*head)->data = x;
	(*head)->next = temp;
}

void print(Node* head)
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

Node * merge(Node * a, Node * b)
{
	Node * merge = new Node;
	Node * temp = new Node;

	// merge is equal to temp so in the end we have the top node.
	merge = temp;
	while (a!= NULL && b != NULL)
	{
		if (a->data <= b->data)
		{
			temp->next = a;
			a = a->next;
		}
		else {
			temp->next = b;
			b = b->next;
		}
		temp = temp->next;
	}
	while (a != NULL)
	{
		temp->next = a;
		a = a->next;
		temp = temp->next;
	}
	while (b != NULL)
	{
		temp->next = b;
		b = b->next;
		temp = temp->next;
	}
	return merge->next;
}



Node * middle(Node * head)
{
	Node * slow = head;
	Node * fast = head->next->next;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node * sort(Node * head)
{
	if (head->next ==NULL)
	{
		return head;
	}
	Node * mid = new Node;
	Node * head2 = new Node;

	mid = middle(head);
	head2 = mid->next;
	mid->next = NULL;

	Node * finalhead = merge(sort(head), sort(head2));
	return finalhead;
}
int main()
{
	Node * head = NULL;
	int n[] = { 7, 10, 5, 20, 3, 2 };
	for (int i = 0; i < 6; i++)
	{
		insert(&head, n[i]);
	}

	cout << "Sorted Linked List is: \n";
	print(sort(head));
	system("pause");
	return 0;
}
