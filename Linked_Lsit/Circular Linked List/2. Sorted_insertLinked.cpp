#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using	namespace std;

class Node
{
public:
	int data;
	Node * next;
};


void SortedInsert(Node ** head_ref, Node * newNode) {
	Node * current = *head_ref;

	if (current == NULL) {
		newNode->next = newNode;
		*head_ref = newNode;
	}
	else if (current->data >= newNode->data)
	{
		while (current->next != *head_ref)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->next = *head_ref;
		*head_ref = newNode;
	}
	else
	{
		while (current->next != *head_ref && current->next->data < newNode->data)
		{
			current = current->next;
		}

		newNode->next = current->next;
		current->next = newNode;

	}

}


void printList(Node * head) {
	Node * tmp;
	if (head != NULL) {
		tmp = head;
		do
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		} while (tmp != head);
	}

}


int main()
{
	int arr[] = { 12, 56, 2, 11, 1, 90 };
	int list_size, i;

	Node * start = NULL;
	Node * tmp;

	for (int i = 0; i < 6; i++)
	{
		tmp = new Node();
		tmp->data = arr[i];
		SortedInsert(&start, tmp);
	}


	printList(start);
	system("pause");
	return 0;
}