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
	Node * next;

};



Node * addToEmpty(Node * last , int data ){

	if (last !=NULL)
	{
		return last;
	}
	Node * temp = new Node;
	temp->data = data;
	last = temp ;

	temp->next = last;
	return last;
}


Node * addBegin (Node * last, int data){
	if (last ==NULL)
	{
		return addToEmpty(last , data);
	}

	Node *  temp = new Node;
	temp->data = data;
	temp->next = last->next;
	last->next = temp;
	return last;
}



Node * addAfter(Node * last , int data , int item ){
	if (true)
	{

	}



}

int main()
{

	system("pause");
    return 0;                           
}