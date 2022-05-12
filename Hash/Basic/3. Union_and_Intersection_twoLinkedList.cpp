#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>

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
	temp->next=*head_ref;
	*head_ref=temp;

}

void printList (Node * head)
{
	Node * temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}



Node * getUnion(unordered_map<int , int> eleOcc)
{
	Node * result = NULL;

	for (auto it = eleOcc.begin() ; it != eleOcc.end() ; it++)
	{
		push(&result, it->first);
	}

	return result;
}





void storeEle (Node * head1 , Node * head2 , unordered_map<int , int> &eleOcc)
{
	Node * ptr1 = head1;
	Node * ptr2 = head2;
	 // Traverse both lists
	while (ptr1 != NULL || ptr2 != NULL)
	{
		 // store element in the map
		if (ptr1 != NULL)
		{
			eleOcc[ptr1->data]++;
			ptr1 = ptr1->next;
		}
		// store element in the map
		if (ptr2 != NULL)
		{
			eleOcc[ptr2->data]++;
			ptr2= ptr2->next;
		}
	}
}



Node* getIntersection(unordered_map<int, int> eleOcc)
{
	Node * result = NULL;

	for (auto it = eleOcc.begin() ; it!= eleOcc.end() ; it++)
	{
		if (it->second == 2)
		{
			push(&result , it->first);
		}
	}
	return result;
}





void printUnionIntersection (Node * head1 , Node *head2)
{
	unordered_map<int , int > eleOcc;
	storeEle(head1 , head2 , eleOcc);


	Node * intersection_list = getIntersection(eleOcc);

	Node * union_list  = getUnion(eleOcc);
	printf("\nIntersection list is \n");
    printList(intersection_list);
  
    printf("\nUnion list is \n");
    printList(union_list);




}

int main ()
{ 
	Node * head1 = NULL;
	Node * head2 = NULL;

	 push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);
  
	  push(&head2, 1);
    push(&head2, 3);
    push(&head2, 5);
    push(&head2, 6);



	printf("First list is \n");
    printList(head1);
  
    printf("\nSecond list is \n");
    printList(head2);
  
    printUnionIntersection(head1, head2);
	
	
	system("pause");
	return 0 ;
}
