#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Node
{
public:
	int data;
	Node * next;

};

void push(Node**head_ref, int new_data) {
	Node * new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(Node * node) {
	while (node !=NULL){
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

// Return the last node of the list
Node * getTail(Node * current) {
	while (current != NULL && current->next !=NULL) {
		current = current->next;
	}
	return current;
}

Node * partition(Node * head, Node * end, Node ** newHead, Node ** newEnd) {
	Node * pivot = end;
	Node * prev = NULL, *cur = head, *tail = pivot;

	while (cur != pivot){
		if (cur->data  < pivot->data){
			if ((*newHead)==NULL){
				(*newHead) = cur;
			}
			prev = cur;
			cur = cur->next;
		}
		else			
		{// If cur node is greater than pivot
			// Move cur node to next of tail and change tail
			if (prev)
			{
				prev->next = cur->next;
			}
			Node * tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	if ((*newHead)==NULL){
		(*newHead) = pivot;
	}
	(*newHead) = tail;

	return pivot;
}




int main() {



	system("pause");
	return 0;
}