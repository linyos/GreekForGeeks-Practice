#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

class Node
{
public:
	int data;
	Node * next, *prev;
};


void printList(Node * head)
{
	Node * temp = head;
	cout << "Forward Traversal using next pointer\n";

	while (head)
	{
		cout << head->data << " ";
		temp = head;
		head = head->next;
	}


	cout << "\nBackward Traversal using prev pointer\n";
	while (temp )
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}



void insert(Node ** head, int data)
{

	Node * temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;

	if (!(*head))
	{
		(*head) = temp;
	}
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}


Node * merge(Node * first, Node * second)
{
	if (!first) return second;
	if (!second) return first;

	// Pick the smaller value
	if (first->data < second->data)
	{
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}

}

Node * split(Node * head)
{
	Node * fast = head;
	Node * slow = head;

	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node * temp = slow->next;
	slow->next = NULL;
	return temp;

}

void p(Node * head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



Node * mergeSort(Node * head)
{
	if (! head || ! head->next) return head;

	Node * second = split(head);


	cout << "=====second list==== " << endl;

	p(second);

	cout << "========== " << endl;

	head = mergeSort(head);
	second = mergeSort(second);

	return merge(head, second);

}






int main() 
{

	Node * head = NULL;
	insert(&head, 5);
	insert(&head, 20);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 30);
	insert(&head, 10);
	head = mergeSort(head);
	cout << "Linked List after sorting\n";
	//printList(head);
	
	system("pause"); 
	return 0;
}


