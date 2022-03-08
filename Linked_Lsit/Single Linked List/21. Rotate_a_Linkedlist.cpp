#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	int data;
	Node * next;
};

// The function rotate a linked list counter-clockwise and update the head,
// The Function assumes that k is smaller than size of linked list, It does't modify the
// list if k is greater than or equal to size.
void rotate (Node ** head_ref , int k)
{
	if (k == 0 ) return ;

	
	Node * current = * head_ref;


	int count= 1;
	while (count < k && current != NULL)
	{
		current = current->next;
		count++;
	}
	 // If current is NULL, k is greater than
    // or equal to count of nodes in linked list.
    // Don't change the list in this case
	if (current == NULL)
	{
		return ;
	}

	
	// Current points to kth node.
	//Store it in a variable.
	
	Node * kthNode = current;
	//Current will point to last node after this loop
	//current will point to node (60) in the above example.
	while (current ->next != NULL)
	{

		current= current->next;
	}
	cout<<"Current " <<current->data<<endl; 
	// Current next  of last node to previous head 
	// Next of 60 is now changed to node 10
	current->next = *head_ref;
	// Change head to (k+1)th node
	// head is now changed to node 50
	*head_ref= kthNode->next;
	//change next of kth node to NULL
	// next to 40 is now NULL.
	kthNode->next = NULL;

}



void push (Node ** head_ref , int data)
{
	Node *  node = new Node;
	node->data =data;
	node->next = * head_ref;
	*head_ref = node;
}


void printList (Node * node)
{
	while (node != NULL)
	{
		cout<<node->data<<" ";
		node= node->next;
	}
	cout<<endl;
}

int main() {

	Node* head = NULL;
 
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    cout << "Given linked list \n";
    printList(head);
    rotate(&head, 4);
 
    cout << "\nRotated Linked list \n";
    printList(head);


	system("pause");
	return 0;
}







