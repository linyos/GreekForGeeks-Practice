#include <iostream>

using namespace std;


struct Node
{
	int data;
	Node * next;
	Node (int x ){
		data= x;
		next=NULL;
	}
};

Node * push (Node * last , int data){

	if (last==NULL)
	{
		// Struct 結構配給一個記憶體空間
		Node * temp = (Node *) malloc(sizeof(Node));

		temp->data = data;
		last = temp ;
		temp->next = last;
		return last ;
	}
	// Creating a node dynamically 
	Node * temp = (Node *) malloc(sizeof(Node ));
	temp->data =data;
	temp ->next = last->next;
	last->next = temp;
	return last;
}


int countNodes (Node * head){
	Node * temp = head;
	int result = 0 ;
	if (head != NULL)
	{
		do
		{
			temp= temp->next;
			result ++;
		} while (temp != head);
	}
	return result;
}


int main(){

	Node* head = NULL;
    head = push(head, 12);
    head = push(head, 56);
    head = push(head, 2);
    head = push(head, 11);
    cout << countNodes(head);


	system("pause");
	return 0;
}