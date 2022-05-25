#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>

using namespace std;


class Node
{
public:
	int data;
	Node * next;
};



void push (Node ** head_ref , int data)
{
	Node * temp = new Node;
	temp->data=data;
	temp->next= *head_ref;
	*head_ref = temp;
}



bool areIdentical(Node * a , Node * b)
{
	while (a != NULL && b != NULL)
	{
		if (a->data != b->data)
		{
			return false;
		}
		a= a->next;
		b=b->next;
	}
	return (a==NULL && a==NULL);
}

void printList(Node * head)
{
	while (head != NULL)
	{
		cout<< head->data << " ";
		head = head->next;
	}
	cout<<endl;
}


int main()
{  
	 Node *a = NULL;
     Node *b = NULL;

	  push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    push(&b, 1);
    push(&b, 2);
    push(&b, 3);
 
    if(areIdentical(a, b))
        cout << "Identical";
    else
        cout << "Not identical";
 
	system("pause");
	return 0;
}