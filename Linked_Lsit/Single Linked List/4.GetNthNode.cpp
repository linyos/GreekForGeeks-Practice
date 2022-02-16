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





int GetNth (Node * head,  int index){

	Node * current = head;

	int Count = 0 ;
	while (current != NULL)
	{
		if (Count==index)
		{
			return current->data;
		}
		Count++;
		current= current->next;
	}


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






int main(){


 // Start with the
    // empty list
    Node* head = NULL;
 
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
 


	printList(head);
    // Check the count
    // function
    cout << "Element at index 3 is " << GetNth(head, 2);
	system("pause");
	return 0 ;
}