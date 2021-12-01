#include<iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;



class Node
{
public:
	int data;
	Node * next ;
};


Node * addToEmpty (Node * head , int data){
	if (head!=NULL)
	{
		return head;
	}
	Node * temp = new Node;
	temp->data = data;
	head= temp ;
	head->next = head ;
	return head;
}


Node * addBegin (Node * head , int data){
	if (head==NULL)
	{
		return addToEmpty(head , data);
	}

	Node * temp = new Node;

	temp->data = data;
	temp->next = head->next;
	head->next = temp;
	return head;

}

void traverse (Node * head){
	Node * p;
	if (head==NULL)
	{
		cout<<"List is empty." <<endl;
		return ;
	}
	p = head;
	
	do
	{
		cout<<p->data <<" ";
		p = p->next;
	} while (p != head);
}

Node * exchangeNodes (Node * head){
	// If list is of length 2 
	if (head->next->next == head)
	{
		head= head->next;
		return head;
	}
	Node * p = head;
	while (p ->next->next != head)
	{
		p = p->next;
	}


	p->next->next = head->next;
	// (5) 6->1->2->3->*4->5	
	//6->1->2->3->*4->5

	head->next = p->next;
	//'6->5
	p->next = head;
	//4*->6
	head= head->next;
	return head;
}




 




int main()
{
	int i ;
	Node * head = NULL;	
	head= addToEmpty(head , 6);
	for (int i = 5; i >0 ; i--)
	{
		head = addBegin(head , i);
	}
	cout<<"List Before: ";
	traverse(head);
	cout<<endl;

	cout << "List After: ";
    head = exchangeNodes(head);
    traverse(head);
	system("pause");
    return 0;                           
}