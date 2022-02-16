#include <iostream>

using namespace std;


class Node
{
public:
	int data;
	Node * next;
};


void push (Node ** head_ref , int data){
	Node * node = new Node();
	node->data =data;
	node->next= *head_ref;
	(*head_ref) = node;
}



void printList (Node *  node){
	Node * current = node;
	while (current != NULL)
	{
		cout<<current->data<<" -> ";
		current= current->next;
	}
	cout<<endl;
}



bool Search (Node * head , int x ){

	Node * current = head;
	while (current != NULL)
	{
		if (current ->data == x )
		{
			return true;
		}
		current=current->next;
	}
	return false;



}



int main(){


	Node * head = NULL;
	
	push(&head , 1);
	push(&head , 2);
	push(&head , 3);
	push(&head , 4);
	push(&head , 5);

	cout<<"Initial Linked List: \n";
	printList(head);


	 cout<<"Search Linked List:  ";
	 Search(head ,3)? cout <<"Yes \n" : cout<<"No\n"; 
	 
	system("pause");
	return 0 ;
}