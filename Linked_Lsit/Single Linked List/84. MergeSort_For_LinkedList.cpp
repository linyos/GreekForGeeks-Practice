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

Node* SortedMerge(Node* a, Node* b);

void FrontBackSplit(Node * source, Node** frontRef, Node ** backRef);

void MergeSort(Node ** headRef)
{
	Node * head = *headRef;
	Node * a, *b;

	if (head== NULL || head->next == NULL)
	{
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}



Node * SortedMerge(Node *a, Node *b) {
	Node * result = NULL;

	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;

	// Pick either a or b and recur;
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return result;
}

void FrontBackSplit(Node* head, Node** frontRef, Node** backRef)
{
	Node * slow = head, *fast = head->next;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	*frontRef = head;
	*backRef = slow->next;
	slow->next = NULL;

}

void printList(Node * node) {
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}


void push(Node ** head, int data)
{
	Node * node = new Node;
	node->data = data;
	node->next = *head;
	*head = node;
}
int main()
{
	Node * res = NULL;
	Node *a = NULL;

	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	MergeSort(&a);

	cout << "Sorted Linked List is: \n";
	printList(a);
	system("pause");
	return 0;
}
