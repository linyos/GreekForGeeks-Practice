#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <unordered_map>

using namespace std;


class Node
{
public:
	int data;
	Node * next;
};



void  push(Node ** head_ref, int data)
{
	Node * temp = new Node; 
	temp->data = data;
	temp->next = *head_ref;
	*head_ref = temp;
}

void printList(Node * head)
{
	Node * current = head;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void reverseList(Node ** head)
{
	Node * current = *head;
	Node * prev = NULL;
	Node * next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}
	*head= prev;
}



int main() 
{
	Node * node = NULL;

	push(&node, 5);
	push(&node, 4);
	push(&node, 3);
	push(&node, 2);
	push(&node, 1);
	printList(node);



	reverseList(&node);
	printList(node);
	system("pause");
	return 0;
}


