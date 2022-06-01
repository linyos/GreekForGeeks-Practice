#include <iostream>

using namespace std;



class Node
{
public:
	int data;
	Node * next;
};



void push(Node ** head_ref, int data)
{
	Node * temp = new Node;
	temp->data = data;
	temp->next = *head_ref;
	*head_ref = temp;
}


void printList(Node *  node) {
	Node * current = node;
	while (current != NULL)
	{
		cout << current->data << "  ";
		current = current->next;
	}
	cout << endl;
}


//Method  ( Using length of linked list)

void printNthFromLast(Node * head, int n)
{
	int len = 0, i;
	Node * temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < n) return;

	temp = head;

	for (i = 1; i < len - n + 1; i++)
	{
		temp = temp->next;
	}
	return;
}






//Method 2 : (Using two pointer)
class node
{
public:
	int data;
	node * next;
	node (int value)
	{
		data=value;
		next = NULL;
	}
};


class Llist
{
public:
	node * head;
	Llist(){head =NULL;}


	void insertAtBegin(int value)
	{
		node * newNode = new node(value);
		newNode->next = head;
		head= newNode;
	}

	void nthFromEnd(int n )
	{
		node * main_ptr = head ;
		node * ref_ptr = head;

		if (head == NULL)
		{
			cout<<"List is empty" <<endl;
			return ;
		}
		for (int i = 1; i < n; i++)
		{
			ref_ptr = ref_ptr->next;
			if (ref_ptr==NULL)
			{
				cout<< n  << " is greater than no. of nodes in the list"
                     << endl;
				return ;
			}
		}


		while (ref_ptr != NULL && ref_ptr->next != NULL)
		{
			ref_ptr = ref_ptr->next ;
			main_ptr = main_ptr->next;
		}
		  cout << "Node no. " << n
             << " from end is: " << main_ptr->data << endl;

	}




	void displaylist ()
	{
		node * temp = head;
		while (temp != NULL)
		{
			cout<< temp->data <<"->";
			temp = temp->next;
		}
		cout<<endl;

	}

};






int main(){

	Node * head = NULL;
	for (int i = 60; i >= 10; i -= 10)
	{
		push(&head, i);
	}

	printList(head);
	int n = 2;
	printNthFromLast(head, n);




	system("pause");
	return 0 ;
}