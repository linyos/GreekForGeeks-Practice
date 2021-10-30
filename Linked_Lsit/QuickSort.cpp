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

Node * quickSortRecur(Node * head, Node * end) {
	if (!head || head==end){
		return head;
	}
	Node * newHead = NULL, *newEnd = NULL;

	Node * pivot = partition(head, end, &newHead, &newEnd);


	if (newHead !=pivot){
		
		Node * tmp = newHead;
		//cout << pivot ->data << " ";
		while (tmp->next !=pivot)	
			tmp = tmp->next;
		tmp->next = NULL;
		newHead = quickSortRecur(newHead, tmp);
		tmp = getTail(newHead);
		tmp->next = pivot;
	}


	pivot->next = quickSortRecur(pivot->next, newEnd);
	return newHead;
}



void quickSort(Node ** headRef) {
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}

int main() {
	Node * a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	cout << "Linked List before sorting \n";
	printList(a);
	quickSort(&a);

	//cout << "Linked List after sorting \n";
	//printList(a);
	system("pause");
	return 0;
}