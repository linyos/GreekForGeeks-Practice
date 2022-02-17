#include <iostream>

using namespace std;


class Node
{
public:
	int data;
	Node * next ;
	
};

Node push (Node ** head_ref , int data){
	Node * node = new Node();
	node->data= data;
	node->next = (*head_ref);
	(*head_ref) = node;
}





// Method 1 
int count(Node * head , int x)
{
	Node * current = head;
	int count = 0 ;
	while (current != NULL)
	{
		if (current->data == x)
		{
			count++;
		}
		current= current->next;
	}
	return count;
}


// Method Recursion
int frequency = 0;
int countRecur (Node * head , int x)
{
	if (head==NULL)
	{
		return frequency;
	}
	if (head->data==x)
	{
		frequency++;
	}
	return count(head->next , x);
}


int main(){
	    /* Start with the empty list */
    Node* head = NULL;
 
    /* Use push() to construct below list
    1->2->1->3->1 */
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
 
    /* Check the count function */
    cout << "count of 1 is " << count(head, 1);


	system("pause");
	return 0 ;
}