#include <iostream>
#include <queue>
using namespace std;


class Node
{
public:
	int data;
	Node * next;
};


void push (Node ** head_ref , int data)
{
	Node * node = new Node;
	node->data =data;
	node->next= *head_ref;
	*head_ref= node;
}


void printList (Node * node)
{
	while (node != NULL)
	{
		cout<< node->data <<" ";
		node= node->next;
	}
	cout<<endl;
}

// Function to skip M nodes and then
// delete N nodes of the linked list.
void skipMdeleteN(Node * head  , int M , int N)
{
	Node * current = head ,* t;
	int count;

	while (current)
	{  
		// Skip M nodes
		for (count = 1 ; count < M && current!= NULL ; count++)
		{
			cout<< current->data <<" " ;
			current =current->next;
		}

		cout<<endl;
		 // If we reached end of list, then return
		if (current == NULL)
			return ;
		

		// Start from next node and delete N Node
		 t = current->next;
		 for (count = 1 ; count<= N && t != NULL ; count++)
		 {
			 Node  * temp = t ;
			 t =t->next;
			 free(temp);
		 }
		  // Link the previous list with remaining nodes
		 current->next = t;
		 // Set current pointer for next iteration
		 current= t ;
	}

}

int  main() {

	 /* Create following linked list
    1->2->3->4->5->6->7->8->9->10 */

	Node* head = NULL;
    int M=2, N=3;
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout << "M = " << M<< " N = " << N << "\nGiven Linked list is :\n";
    printList(head);
 
    skipMdeleteN(head, M, N);
 
    cout<<"\nLinked list after deletion is :\n";
    printList(head);
	system("pause");
	return 0;
}






