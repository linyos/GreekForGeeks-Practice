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

using namespace std;


class Node
{
public:
	int data;
	Node * next;
};


void push (Node ** head_ref , int data)
{
	Node * temp = new Node;
	temp ->data =data;
	temp ->next= *head_ref;
	*head_ref = temp ;
}

void printList(Node * head)
{
	while (head != NULL)
	{
		cout << head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}


Node * getTail (Node * head)
{
	Node * current = head;


	// µ¥©ó (current->next != NULL)
	while (current!= NULL && current->next != NULL)
	{
		current = current->next;
	}

	
	return current;
}




// Partitions the list taking the last element as the pivot
Node * partition(Node * head , Node * end ,
				 Node ** newHead , Node ** newEnd)

{
	Node * pivot = end;
	
	Node *cur = head , *tail = pivot ;

	Node * prev = NULL; 

	while (cur != pivot)
	{
		// If cur node is smaller than pivot 

		cout << "pivot " << pivot->data<<endl; 
		cout << "tail" << tail->data<<endl; 

		if (cur->data < pivot->data)
		{
			// First node that has a value less than the pivot - become the new head
			if ((*newHead)==NULL)
				(*newHead) = cur;
			
			prev = cur;
			cur = cur->next; 
		}
		// If cur node is greater than pivot
		else
		{
			// Move cur node to next to tail ,
			// and change tail
			if (prev)
				prev->next = cur->next;
			
			Node * temp = cur->next;
			cur->next = NULL;
			tail->next =cur;
			tail = cur;
			cur = temp ;
		}
	}


	if ((*newHead) == NULL)
		(*newHead) = pivot;

	(*newEnd) = tail;
	return pivot;
}




// the sorting happens exclusive of the end node
Node * quickSortRecur (Node * head , Node  * end)
{
	if (!head || head==end)
	{
		return head;
	}

	Node * newHead = NULL , *newEnd = NULL;
	// Partition the list, newHead and newEnd will be
    // updated by the partition function
	Node * pivot = partition(head , end , &newHead , & newEnd);

	// If pivot is the smallest element - no need to recur
    // for the left part.
	if (newHead != pivot)
	{	

		Node * temp = newHead;
		while (temp->next!= pivot)
		{
			temp = temp->next;
		}
		temp ->next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead , temp);
		// Change next of last node of the left half to pivot
		temp = getTail(newHead);
		temp->next = pivot;
	}

	pivot->next = quickSortRecur(pivot->next , newEnd);

	return newHead;
}


// The main function for quick sort
void quickSort (Node ** headRef)
{
	(*headRef) = quickSortRecur(*headRef , getTail(*headRef));
	return ;
}


int main()
{  
	 Node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

	cout << "Linked List before sorting \n";
    printList(a);
 
    quickSort(&a);
 
    cout << "Linked List after sorting \n";
    printList(a);


	system("pause");
	return 0;
}