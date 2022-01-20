#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include<queue>
#include <set> 
#include <iomanip>

using namespace std;

class Node
{
public:
	int data;
	Node * next , * prev ;
};


void pairSum (Node * head, int x ){

	// Set two pointer, First to the beginning of DLL
	// end second to the end of DLL.
	Node * first = head;
	Node * second = head;
	while (second->next != NULL)
	{
		second = second->next;
	}

	bool found = false;


	// The loop terminate when two pointer cross each other  (second->next == first), 
	// or they become same (first == second)
	while (first != second && second->next !=first)
	{
		if ((first->data + second->data)==x)
		{
			found =true;
			cout<<"("<< first->data <<", " <<second->data <<")" <<endl;

			first= first->next;
			second = second->prev;
		}
		else
		{
			if ((first ->data + second ->data) < x)
			{
				first = first->next;
			}
			else
			{
				second = second->prev;
			}
		}
	}
	if (found==false)
	{
		cout<<"No Pair found." <<endl;
	}

}




void insert (Node ** head, int data){

	Node * temp = new Node();
	temp ->data = data;
	temp ->next = temp ->prev = NULL;

	if (!(*head))
	{
		(*head) = temp ;
	}
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}

}

int main (){

	 Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;
 
    pairSum(head, x);
	system("pause");
	return 0 ;
}