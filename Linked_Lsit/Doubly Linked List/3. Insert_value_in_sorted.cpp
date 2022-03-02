#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include<queue>
#include <set> 
#include <iomanip>
#include <unordered_set>
using namespace std;


class Node
{
public:
	int data;
	Node * prev , * next;
};


Node * getNode (int data){
	Node * newNode = new Node();
	newNode->data = data ;
	newNode->next = newNode->prev = NULL;
	return newNode;
}


void sortedInsert(Node ** head_ref , Node * newNode ){
	Node * current ;
	if (*head_ref ==NULL)
	{
		*head_ref =newNode;
	}
	// if the node is to be inserted at the beginning of the doubly linked list 
	else if ((*head_ref)->data  >= newNode->data)
	{
		newNode->next = *head_ref;
		newNode->next->prev = newNode;
		*head_ref = newNode;
	}
	else
	{
		current = *head_ref;
		while (current->next != NULL && current->next->data < newNode->data)
		{
			current= current->next;
		}
		newNode->next = current->next;

		//If the new node is not inserted at the end of the list
		if (current->next != NULL)
		{
			newNode->next ->prev= newNode;
		}

		current->next = newNode;
		current->prev= current;
	}
}
	

void printList(Node * head){
	while (head != NULL)
	{
		cout<<head->data <<" ";
		head= head->next;
	}
	cout<<endl;
	
}


int main (){
	Node * head =NULL;
	Node * new_node = getNode(8);



	sortedInsert(&head, new_node);
    new_node = getNode(5);
    sortedInsert(&head, new_node);
    new_node = getNode(3);
    sortedInsert(&head, new_node);
    new_node = getNode(10);
    sortedInsert(&head, new_node);
    new_node = getNode(12);
    sortedInsert(&head, new_node);
    new_node = getNode(9);
    sortedInsert(&head, new_node);
	
	cout << "Created Doubly Linked Listn" <<endl;
    printList(head);


	system("pause");
	return 0 ;
}