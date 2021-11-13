#include<iostream>
#include<algorithm>
#include<string>
#include <math.h>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};

Node * SortedMerge(Node * a, Node * b);
void FrontBackSplit(Node * source, Node ** frontRef, Node ** BackRef);



// Sorted the linked list by changed next pointers
void MergeSort(Node ** headRef) {
	Node * head = *headRef; 
	Node * a;
	Node * b;

	if ((head==NULL) || (head->next==NULL)){
		return;
	}

	FrontBackSplit(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a, b);


}


Node * SortedMerge(Node * a, Node * b) {
	Node * result = NULL;
	if (a==NULL){
		return b;
	}
	else if (b==NULL){
		return a;
	}

	if (a->data <= b->data){
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = SortedMerge(a, b->next);
	}


	return result;

}
void FrontBackSplit(Node * source, Node ** frontRef, Node ** backRef) {

	Node * fast;
	Node * slow;
	slow = source;
	fast = source->next;
	
	// fast is two node
	// slow is one node
	while (fast != NULL){
		fast = fast->next;
		if (fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}

	/*
	'Slow' is before the midpoint in the last
	so split it in two  at the point.
	*/

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;

}



void printList(Node * node) {
	while (node != NULL){
		cout << node->data << " ";
		node = node->next;
	}
}



void push(Node **head_ref, int new_data) {
	Node * new_node = new Node();
	new_node->data = new_data;

	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
int main() {
	
	Node * res = NULL;
	Node * a = NULL;

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