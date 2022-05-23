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

using namespace std;

class Node
{
public:
	int data;
	Node * next;
	Node * prev;
};


void swap (int *a , int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}



// a utility function to find last node of linked list
Node * lastNode(Node* root)
{
	while (root != NULL && root->next !=NULL)
	{
		root= root->next;
	}
	return root;
}



Node * partition(Node *l , Node * h)
{
	// set pivot as h element
	int x = h->data;
	// similar to i = l-1 for array implemenetation
	Node *i = l->prev;

	 // Similar to "for (int j = l; j <= h- 1; j++)"
	for (Node * j = l  ; j != h ; j = j->next)
	{
		if (j->data <= x)
		{

			// Similar to i++ for array
			 i =(i==NULL) ? l : i->next;

			 swap(&(i->data) , &(j->data));
		}
	}
	// Similar to i++
	i = (i==NULL) ? l : i->next;
	swap(&(i->data) , &(h->data));
	return  i ;
}






// A recursive implementation of quickSort for linked list
void _quickSort(Node *l , Node * h)
{
	if (h != NULL && l != h && l != h->next)
	{
		Node *p = partition(l , h);
		_quickSort(l , p->prev);
		_quickSort(p->next , h);
	}
}


void QuickSort(Node * head)
{
	Node * h = lastNode(head);
	_quickSort(head , h);
}




void push(Node ** head_ref , int data)
{
	Node * temp = new Node;
	temp->data=data;
	temp->prev= NULL;

	temp->next = (*head_ref);
	if ((*head_ref)!= NULL )
	{
		(*head_ref)->prev = temp;
	}

	*head_ref= temp;
}


// utility function to print contents of arr
void printList (Node * head)
{
	while (head != NULL)
	{
		cout << head->data<<" ";
		head= head->next;
	}
	cout<<endl;
}



int main()
{  
	Node * a  = NULL;
	push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    QuickSort(a);
 
    cout << "Linked List after sorting \n";
    printList(a);

	system("pause");
	return 0;
}