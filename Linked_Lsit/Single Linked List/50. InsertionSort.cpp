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
#include <ctime>

using namespace std;


class Node
{
public:
	int data;
	Node * next;
};


void push (Node ** head_Ref , int data)
{
	Node * temp =new Node;
	temp->data=data;
	temp ->next = *head_Ref;
	*head_Ref= temp;
}

void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data <<  " ";
		head = head ->next;
	}
	cout <<endl;

}


 void sortedInsert(Node ** sortNode , Node* head)
 {
	 if ((*sortNode)==NULL || (*sortNode)->data >= head ->data)
	 {
		 head->next = (*sortNode);
		(*sortNode) = head;
	 }
	 else
	 {
		  Node* current = *sortNode;
		  while (current->next != NULL&& current->next->data < head->data) {
                current = current->next;
            }
            head->next = current->next;
            current->next = head;

		// error verion
		 //while ((*sortNode)->next != NULL && (*sortNode)->next->data <head->data)
		 //{
			// (*sortNode) = (*sortNode) ->next;
		 //}
		 //head->next = (*sortNode)->next;
		 //(*sortNode)->next = head;
	 }
 }

Node *  insertionSort (Node * headref )
{
	Node * current = headref;
	Node * sortnode = NULL;
	while (current != NULL)
	{
		Node * next = current->next;
		sortedInsert(&sortnode,current);
		current= next;
	}

	return sortnode;

}



int main()
{  

	Node * a = NULL;
   push (&a , 5);
   push (&a , 20);
   push (&a , 4);
   push (&a , 3);
   push (&a , 30);

   printList(a);

   Node * b = insertionSort(a);
   
	printList(b);
	system("pause");
	return 0;
}