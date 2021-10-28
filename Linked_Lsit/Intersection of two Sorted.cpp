#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;


class Node
{
public:
	int data;
	Node * next;

	void push (Node ** head_ref , int new_data);
	Node * sortedIntersect(Node * a , Node * b);

};


Node * Node::sortedIntersect(Node * a , Node * b){
	Node dummy;
	Node * tail = & dummy;
	dummy.next = NULL;

	while (a != NULL && b !=NULL){
		if (a ->data == b->data){
			push((&tail->next) , a->data);
			tail = tail->next;
			a=a->next;
			b=b->next;
		}
		else if (a->data < b->data)
		{
			a=a->next;
		}
		else
		{
			b = b->next;
		}
	}
	return dummy.next;

}

void Node::push(Node ** head_ref , int new_data){

	Node * new_node = new Node ;

	new_node->data = new_data;
	new_node->next= (*head_ref);

	(*head_ref)= new_node;
}

void printList (Node * node ){
	while (node!= NULL){
		cout<< node->data <<" ";
		node = node->next;
	}
}
int main(){

	Node c;
	Node * a = NULL;
	Node * b = NULL;
	Node * intersect = NULL;

	c.push(&a, 6);
    c.push(&a, 5);
    c.push(&a, 4);
    c.push(&a, 3);
    c.push(&a, 2);
    c.push(&a, 1);
	cout<<"Linked list a :";
	printList(a);


	c.push(&b, 8);
   c. push(&b, 6);
    c.push(&b, 4);
    c.push(&b, 2);
	cout<<"\nLinked list b :";
	printList(b);
	 intersect = c.sortedIntersect(a, b);
	 cout<<"\nLinked list containing common items of a & b \n";
    printList(intersect);

	system("pause");
	return 0;
}