#include <iostream>


using namespace std;

class Node
{
public:
	int data;
	Node * next;

};

// The function to insert a node into an empty list.
Node * addToEmpty (Node * last , int data){
	if (last != NULL)
	{
		return last;
	}

	Node * temp = new Node;
	temp->data=data;
	
	last= temp;
	temp->next =last;

	return last;


}



Node * addBegin(Node * last , int data)
{
	if (last== NULL)
	{
		return addToEmpty(last , data);
	}

	Node * temp = new Node();

	temp->data=data;
	temp->next = last->next;
	last->next = temp;
	return last;
}


Node * addEnd(Node * last , int data)
{
	if (last==NULL)
	{
		return addToEmpty(last, data);
	}

	Node * temp = new Node ();
	temp->data =data;

	temp->next= last->next;
	last->next=temp;
	last = temp;
}


Node * addAfter(Node * last , int data , int item)
{
	if (last==NULL)
	{
		return NULL;
	}
	Node *p= last->next;

	// Search the item 
	do
	{
		if (p->data ==item)
		{
			Node * temp = new Node;
			temp->data=data;
			temp->next= p->next;
			p->next= temp;
			if (p==last)
			{
				last= temp;
			}
			return last; 
		}
		p = p->next;
	} while (p != last->next);
	 cout << item << " not present in the list." << endl;
    return last;
}

void traverse(Node  * last)
{
	Node * p ;
	if (last==NULL)
	{
		  cout << "List is empty." << endl;
        return;
	}
	// Pointing to first Node of the list
	p = last->next;
	do
	{
		cout<<p->data<<" ";
		p = p->next;
	} while (p != last->next);
}

int  main() {
	   
	Node *last = NULL;
 
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);
 
    traverse(last);
   
	system("pause");
	return 0;
}

