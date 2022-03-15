#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Node 
{
public:
	int data;
	Node * next ;
	
};




bool isCircular (Node * head){

	if (head==NULL)
	{
		return true;
	}
	 // Next of head
	Node * node = head->next;
	// This loop would stop in both cases (1) If
    // Circular (2) Not circular
	while (node != NULL &&  node!= head)
	{
		node=node->next;
	}
	// If loop stopped because of circular condition
	return (node==head);
}


Node * newNode (int data){

	Node * tmp = new Node;
	tmp->data = data;
	tmp->next= NULL;
	return tmp;
}





int main()
{
	Node * head = newNode(1);
	head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    isCircular(head)? cout << "Yes\n" : cout << "No\n" ;
	head->next->next->next->next = head;
	isCircular(head)? cout<<"Yes\n" : cout<<"No\n";

	system("pause");
    return 0;                           
}