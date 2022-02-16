#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};


class NodeOperation
{
public:
	void pushNode(Node ** head_ref, int data) 
	{
		Node * newnode = new Node();
		newnode->data = data;
		newnode->next = *head_ref;
		*head_ref = newnode;
	}

	void printNode(Node *head)
	{
		while (head != NULL)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}

	void printMiddle(Node * head)
	{
		Node * slow_ptr = head;
		Node * fast_ptr = head;
		if (head !=NULL)
		{
			while (fast_ptr !=NULL && fast_ptr->next !=NULL)
			{
				fast_ptr = fast_ptr->next->next;
				slow_ptr = slow_ptr->next;
			}
			cout << "The middle element is [" << slow_ptr->data <<"]" << endl;
		}
	}

};



int main() {
	Node * head = NULL;
	NodeOperation * temp = new NodeOperation();
	for (int i = 7; i > 0  ; i--)
	{
		temp->pushNode(&head, i);
		temp->printNode(head);
		temp->printMiddle(head);
	}

	system("pause");
	return 0;
}