#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	int data;
	Node * next;
};


void push (Node ** head_ref , int data)
{
	Node * node = new Node; 
	node->data = data;
	node->next = *head_ref;
	*head_ref= node;
}




bool isSumSorted(Node * headA , Node * headB , Node * headC , int key)
{
	Node * a = headA;

	while (a != NULL)
	{
		Node * b = headB;
		Node * c = headC;
		while (b != NULL && c!= NULL)
		{
			int sum = a->data + b->data + c->data;
			if (sum == key)
			{
				cout<<"Triplet Found: " << a->data <<" " << b->data <<" " << c->data ;
				return true;
			}
			else if (sum < key)
			{
				b = b->next;
			}
			else
			{
				c = c->next;
			}
		}

		a = a->next;
	}


	cout<<"No such triplet";
	return false;
}


int main() {
    Node* headA = NULL;
    Node* headB = NULL;
    Node* headC = NULL;
	   /*create a linked list 'a' 10->15->5->20 */
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);
 
    /*create a sorted linked list 'b' 2->4->9->10 */
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);
 
    /*create another sorted
    linked list 'c' 8->4->2->1 */
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);

	int givenNumber = 25;
 
    isSumSorted (headA, headB, headC, givenNumber);
	system("pause");
	return 0;
}






