#include <iostream>
#include<queue>

using namespace std;

// Introduction
class Node
{
public:
	int data;
	Node * next;
	
};


class LinkedList
{
public:
	Node * head;
	LinkedList() 
	{
		head=NULL;
	}
	void reverse()
	{
		Node * current = head;
		Node * prev = NULL;
		Node * next = NULL;
		while (current != NULL)
		{
			next= current->next;
			current->next=prev;

			prev=current;
			current=next;
		}
		head = prev;
	}



	void pirntList()
	{
		Node * temp = head;
		while (temp != NULL)
		{
			cout<<temp->data<<" ";
			temp= temp->next;
		}
	}

	void push(int data){
		Node * node = new Node();
		node->data=data;
		node->next=head;
		head= node;

	}
};




int main() {

	 LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
  
    cout << "Given linked list\n";
    ll.pirntList();
    ll.reverse();
  
    cout << "\nReversed Linked list \n";
    ll. pirntList();

	system("pause");
	return 0;
}




