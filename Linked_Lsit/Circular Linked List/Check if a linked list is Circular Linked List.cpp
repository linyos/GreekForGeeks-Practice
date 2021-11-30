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
	Node * node = head->next;
	while (node != NULL &&  node!= head)
	{
		node=node->next;
	}

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