#include <iostream>

using namespace std;


class Node
{
public:
	int data;
	Node * next ;
	
};

void push (Node ** head_ref , int data){
	Node * node = new Node();
	node->data= data;
	node->next = (*head_ref);
	(*head_ref) = node;
}


int detectLoop(Node * node)
{
	Node * slow_p =node;	
	Node * fast_p = node;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p= slow_p->next;
		fast_p= fast_p->next->next;
			if (slow_p == fast_p)
			{
				return 1;
			}
	}
	return 0 ;

}





int main(){
 Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 

	system("pause");
	return 0 ;
}