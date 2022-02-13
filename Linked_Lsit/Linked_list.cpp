#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
using namespace std;
void Swap(int & a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

class LinkedList;
class Node {

private :
	int data;
	Node  *next;


public:
	Node() : data(0), next(0) {};
	Node(int x) : data(x), next(NULL) {};
	

	friend class LinkedList;
};




class LinkedList
{
private:
	Node * head;
public:
	LinkedList() : head(0) {};
	void reverse();
	void print();
	void push(int data);
	void push_back(int data);
	void insertAfter(int data, int key);
	void removeDuplicate();
	void removeDuplicate1();
	void PairWiseSwap();
	void moveToFront();
	void segregateEvenOdd();
};

void LinkedList::print() {
	Node * current = head;
	while (current != 0){
		cout << current->data << "->";
		current = current->next;
	}
	if (current == 0){
		cout << "NULL";
	}
}

void LinkedList::push(int x) {
	Node * new_node = new Node(x);
	new_node->next = head;
	head = new_node;

}

void LinkedList::push_back(int data) {
	Node * newNode = new Node(data);
	if (head==NULL){
		head = newNode;
		cout << "List is empty. \n";
		return;
	}
	Node * current = head;
	while (current->next != NULL)	{
		current = current->next;
	}
	current->next = newNode;
}

void LinkedList::insertAfter(int data, int key) {
	Node * newNode = new Node(data);
	if (head==NULL){
		head = newNode;
		cout << "List is empty. \n";
		return;
	}
	Node * current = head;
	while (current!= NULL){
		if (current->data == key){
			current->next = newNode;
		}
		current = current->next;
	}
}



void LinkedList::removeDuplicate() {
	// Pointer to traverse the linked list
	Node * current = head;
	// Pointer to  store the next pointer of a node to be deleted
	Node * next_next;
	// If the list is empty
	if (current ==NULL){
		return;
	}
	// Traverse the list till last node
	while (current->next != NULL){
		// compare current  node with next node
		if (current->data == current->next->data){
			// the sequence of steps is important
			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
		}
		else{
			current = current->next;
		}
	}
}

void LinkedList::removeDuplicate1() {
	Node * ptr1, * ptr2, * dup;
	ptr1 = head;
	while (ptr1!= NULL && ptr1->next !=NULL){
		ptr2 = ptr1;
		while (ptr2->next !=NULL){

			if (ptr1->data == ptr2->next->data){
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else{
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

void LinkedList::PairWiseSwap() {
	Node * tmp = head;
	while (tmp!=NULL && tmp->next !=NULL){
		Swap(tmp->data, tmp->next->data);
		tmp = tmp->next->next;
	}
}

void LinkedList::moveToFront() {
	// If linked list is empty, or it contains only one node,
	// then nothing needs to be done.
	if (head==NULL || head->next==NULL){
		return;
	}
	// Initialize second last and last pointers 
	Node * seclast = NULL;
	Node * last = head;
	while (last->next != NULL){
		seclast = last;
		last = last->next;
	}
	// Set the next of second last as NULL
	seclast->next = NULL;
	// Set next of last as head node
	last->next = head;
	// Change the head pointer to point to last node now.
	head = last;
}

void LinkedList::reverse() {
	Node * current = head;
	Node * prev = NULL;
	Node * next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void LinkedList::segregateEvenOdd() {
	Node * end = head;
	Node * prev = NULL;
	Node * curr = head;
	while (end->next != NULL) {
		end = end->next;
	}
	Node *new_end = end;
	while (curr->data % 2 != 0 && curr != end) {
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}
}

int main() {

	LinkedList node1;
	node1.push(5);
	node1.push(4);
	node1.push(3);
	node1.push(2);
	node1.push(1);
	node1.push_back(6);
	node1.insertAfter(7, 6);
	node1.insertAfter(8, 7);
//	cout << "Linked list before moving last to front.\n";
	node1.print();
	
	//node1.moveToFront();
	//cout << "\nLinked list after moving last to front.\n";
	//node1.print();


	//node1.removeDuplicate();
	//cout << "\nLinked list after duplicate removal.\n";
	//node1.print();
	//node1.removeDuplicate1();
	//cout << "\n Linked list after removing duplicates.\n";
	//node1.print();






	system("pause");
	return 0;
}