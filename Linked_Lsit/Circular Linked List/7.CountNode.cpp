#include <iostream>


using namespace std;

class Node
{
public:
	int data;
	Node * next ;

};

Node * push (Node * last , int data)
{
	if (last==NULL)
	{
	 Node * temp = new Node();
	 temp->data=data;
	 last= temp;
	 temp->next= last;
	 return last;
	}
	Node * node = new Node;
	node->data =data;
	node->next= last->next;
	last->next = node;
	return last;
}



int countNodes(Node * head)
{
	Node * temp = head;
	int result = 0;
	if (head != NULL)
	{
		do
		{
			temp =temp->next;
			result ++;
		} while (temp != head);
	}
	return result;
}



int  main() {
	   Node* head = NULL;
    head = push(head, 12);
    head = push(head, 56);
    head = push(head, 2);
    head = push(head, 11);
    cout << countNodes(head);

   
	system("pause");
	return 0;
}

