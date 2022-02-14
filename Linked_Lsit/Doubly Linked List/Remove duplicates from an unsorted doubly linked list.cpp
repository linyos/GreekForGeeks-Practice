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
	Node * next;
	Node * prev;

};


void deleteNode (Node ** head_ref , Node * del){
	if (*head_ref ==NULL || del ==NULL)
	{
		return;
	}

	// If node to be deleted is head node
	if (*head_ref==del)
	{
		*head_ref = del->next; 
	}
	// Change next only if node to be deleted is NOT the last
	if (del->next  != NULL)
	{
		del->next->prev = del->prev;
	}
	//Change pre noly if node to be deleted is NOT the first node
	if (del->prev != NULL)
	{
		del->prev->next = del->next;
	}

	free(del);

}

void removeDuplicates (Node ** head_ref){


	// If DLL is empty or if it contains only a single node
	if ((*head_ref) ==NULL || (*head_ref)->next ==NULL)
	{
		return;
	}

	Node * ptr1 , *ptr2;

	//pick elements one by one
	for (ptr1 = *head_ref ; ptr1 != NULL  ; ptr1= ptr1->next )
	{
		ptr2 = ptr1->next;
		//Compare the picked element with the rest of the elements
		while (ptr2 != NULL)
		{
			// If duplicate, Then delete it
			if (ptr1->data == ptr2->data)
			{
				// Store pointer to  the node next to 'ptr2'
				Node * next = ptr2->next;
				// delete node pointer to ny 'ptr2'
				deleteNode(head_ref , ptr2);

				// update 'ptr2'
				ptr2= next;
			}
			else
			{
				ptr2 = ptr2->next;
			}
		}
	}


}




void push (Node ** head_ref , int data){
	Node * newNode = new Node();
	newNode->data = data;
	newNode->prev= NULL;
	newNode->next = (*head_ref);

	if ((*head_ref) != NULL)
	{
		(*head_ref)->prev = newNode;
	}
	(*head_ref)= newNode;
}

void printList(Node * head){

	while (head!= NULL)
	{
		cout<<head->data <<" ";
		head= head->next;
	}
	cout<<endl;
}



int main (){
	Node * head = NULL;
	 // Create the doubly linked list:
    // 8<->4<->4<->6<->4<->8<->4<->10<->12<->12
    push(&head, 12);
    push(&head, 12);
    push(&head, 10);
    push(&head, 4);
    push(&head, 8);
    push(&head, 4);
    push(&head, 6);
    push(&head, 4);
    push(&head, 4);
    push(&head, 8);
 
    cout << "Original Doubly linked list:n";
    printList(head);
 
    /* remove duplicate nodes */
    removeDuplicates(&head);
 
    cout << "\nDoubly linked list after "
            "removing duplicates:n";
    printList(head);

	system("pause");
	return 0 ;
}