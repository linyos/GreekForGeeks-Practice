#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class  Node
{
public:
	int data;
	Node *next;
};
void push(Node ** head_ref, int data) {

	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void InsertAfter(Node * prev, int data) {
	if (prev == NULL)
	{
		cout << "List is empty. \n";
		return;
	}

	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = prev->next;

	// Make next of new node as next of prev node
	new_node->next = prev->next;
	// Move the next node of prev node 
	// as new node
	prev->next = new_node;



}

void printList(Node * head) {
	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	if (head == NULL)
	{
		cout << "NULL";
	}
}

void Push_back(Node ** head, int data) {
	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;

	// If the Linked List is empty.
	// the new node as head.
	if (*head == NULL)
	{

		*head = new_node;
		return;
	}

	Node *last = *head;
	// Travers all the node when the last node
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}

void append(Node * *head, int data) {
	Node * new_node = new Node();
	Node * last = *head;
	new_node->data = data;
	new_node->next = NULL;

	if (*head==NULL){  //list is empty
		*head = new_node;
		return;
	}

	while (last->next !=NULL){
		last = last->next;
	}

	last->next = new_node;

	return;


}


vodi deleteNode(Node ** head_ref, int x) {
	Node *temp = *head_ref;
	Node *prev = NULL;
	// Delete First Node
	if (temp != NULL && temp->data==x){
		*head_ref = temp->next;
		delete temp;
		return;
	}
	else{
		while (temp !=NULL && temp->data !=x){
			prev = temp;
			temp = temp->next;
		}

		if (temp==NULL){
			return;
		}

		prev->next = temp->next;
		delete temp;
	}

}

//Method 1 : Iterative
bool Search1(Node * head, int key) {
	Node * current = head;
	while (current!=NULL){
		if (current->data ==key){
			return true;
		}
		current = current->next;
	}

	return false;
}

//Method 2 :Recursive
bool Search2(Node * head, int key) {
	if (head==NULL){ //Node is empty
		return false;
	}
	if (head->data==key){
		return true;
	}

	return Search2(head->next, key);

}

//Method 1 : Iterativ
int GetNth1(Node * head, int index) {
	Node * current = head;
	int count = 0;
	while (current!=NULL){
		if (count==index){
			return (current->data);
		}
		count++;
		current = current->next;
	}
	return -1;  // Found not
}


//Method 2 :Recursive
int GetNth2(Node *head, int index) {
	if (head ==NULL){
		return -1;
	}
	if (index==0){
		return head->data;
	}
	return GetNth2(head->next, index - 1);
}



int main() {

	Node * head = NULL;
	push(&head, 1);
	InsertAfter(head, 2);


	Push_back(&head, 3);


	printList(head);

	system("pause");
	return 0;
}
