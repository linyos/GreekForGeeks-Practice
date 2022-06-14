#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <ctime>
#include <time.h>


using namespace std;


class Node 
{
public:
	int data;
	Node * next;
};



void push (Node ** head_ref , int data)
{
	Node * temp  = new Node;
	temp ->data=data;
	temp->next = *head_ref;
	*head_ref = temp;
}



void printList(Node * head)
{
	while (head != NULL)
	{
		cout << head ->data <<" ";
		head = head->next;
	}
	cout<<endl;
}





Node * reverse(Node * head , int k )
{
	if (!head) 
		return NULL;
	

	Node * current = head;
	Node * next =NULL;
	Node * prev = NULL;

	int count = 0 ;

	while (current != NULL &&  count< k )
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current= next;
		count ++;
	}

	if (next != NULL)
	{
		head->next = reverse(next , k );
	}
	return prev ;
}


/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
// Method 2 : Iterative 
Node * reverse2(Node * head , int k)
{
	if (!head || k==1)
		return head;	

	 // creating dummy node
	Node * dummy = new Node;
	dummy->data = -1;
	dummy->next = head;

	// Initialize three pointer
	Node * prev = dummy;
	Node * curr = dummy;
	Node * next = dummy;


	int count = 0 ;
	while (curr!= NULL)
	{
		curr= curr->next;
		count ++;
	}

	while (next != NULL)
	{
		curr = prev ->next;
		next = curr->next;
		
		// toLoop will set to count - 1
		// in case of remaining element
		int toLoop = count > k ? k : count-1;

		for (int i = 0; i < toLoop; i++)
		{
			// 4 step as discussed above
			curr->next = next->next;
			next->next = prev->next;
			prev->next= next;
			next = curr->next;
		}

		// Setting prev to curr
		prev = curr;

		count -=k;

	}
		// dummy -> next will be our new head for output linked
	// list
	return dummy->next;

}

int main()
{  
	Node* head = NULL;

	/* Created Linked list
	is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << "Given linked list \n";
	printList(head);
	head = reverse(head, 3);



	cout << "\nReversed Linked list \n";
	printList(head);

	system("pause");
	return 0;
}