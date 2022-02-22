#include <iostream>
#include<unordered_map>
#include <unordered_set>
using namespace std;

// Introduction
class Node
{
public:
	int data;
	Node * next;
};


Node * newNode(int data)
{
	Node  * temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}



int countNodes(Node * n)
{
	int res = 1;
	Node * temp = n;
	while (temp->next != n)
	{	
		res++;
		temp = temp->next;
	}
	return res;
}

int countNodesinLoop(Node * list)
{
	Node * slow_p = list;
	Node * fast_p = list;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		
		fast_p = fast_p->next->next;
		if (slow_p==fast_p)
		{
			return countNodes(slow_p);
		}
	}
	return 0;


}



int main() {
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next;

	cout << countNodesinLoop(head) << endl;

	system("pause");
	return 0;
}




