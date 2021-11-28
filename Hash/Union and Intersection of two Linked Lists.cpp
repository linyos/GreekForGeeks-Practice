#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <unordered_map>
#include <algorithm>
using	namespace std;



//Method 1 . (linked list)
class Node
{
public:
	int data;
	Node * next;
};
bool isPresent(Node * head, int newdata);
void push(Node ** head_ref, int new_data) {
	Node * new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;

}
Node *  getUnion(Node * head1, Node * head2) {
	Node * result = NULL;
	Node * t1 = head1;
	Node * t2 = head2;

	while (t1 != NULL)
	{
		push(&result, t1->data);
		t1 = t1->next;
	}

	while (t2 != NULL)
	{
		if (!isPresent(result, t2->data))
		{
			push(&result, t2->data);
		}
		t2 = t2->next;
	}
	return result;
}
Node * getIntersectio(Node * head1, Node * head2) {
	Node * result = NULL;
	Node * t1 = head1;
	while (t1 != NULL) {
		if (isPresent(head2, t1->data))
		{
			push(&result, t1->data);
		}
		t1 = t1->next;
	}
	return result;
}
bool isPresent(Node * head, int newdata) {
	Node * node = head;
	while (node != NULL) {
		if (node->data == newdata)
		{
			return 1;
		}
		node = node->next;
	}
	return 0;
}
void printList(Node * node) {
	while (node != NULL) {
		cout << " " << node->data;
		node = node->next;
	}
	cout << endl;
}











//class Node
//{
//public:
//	int data;
//	Node * next;
//};
// Method 3. (Using Hash)
//
//void push(Node ** head_ref, int new_data) {
//	Node * new_node = new Node();
//	new_node->data = new_data;
//	new_node->next = (*head_ref);
//	(*head_ref) = new_node;
//}
//// Utility Function to store the elements of both list.
//void storeEle(Node * head1, Node * head2, unordered_map <int, int> &eleocc) {
//	Node * ptr1 = head1;
//	Node * ptr2 = head2;
//	
//	while (ptr1 != NULL || ptr2 != NULL){
//		if (ptr1 != NULL)
//		{
//			eleocc[ptr1 -> data]++;
//			ptr1 = ptr1->next;
//		}
//		if (ptr2 != NULL)
//		{
//			eleocc[ptr2->data]++;
//			ptr2 = ptr2->next;
//		}
//	}
//}
//Node * getIntersection(unordered_map <int, int> eleocc) {
//	Node * result = NULL;
//	// Push a node with an element having occurrence of 2 as that means the current
//	// element is present in both the list.
//	for (auto  i = eleocc.begin() ; i != eleocc.end(); i++)
//	{
//		if (i->second ==2)
//		{
//			push(&result, i->first);
//		}
//	}
//	return result;
//}
//// Function to get the union two linled list head1 and head2
//Node * getUnion(unordered_map <int, int> eleocc) {
//	Node * result = NULL;
//
//	for (auto it= eleocc.begin() ; it != eleocc.end() ; it++)
//	{
//		push(&result, it->first);
//	}
//	return result;
//}
//void printList(Node * node) {
//	while (node != NULL)
//	{
//		cout << node->data << " ";
//		node = node->next;
//	}
//	cout << endl;
//}
//void printUnionIntersection(Node * head1, Node * head2) {
//	unordered_map <int, int> eleocc;
//	storeEle(head1, head2, eleocc);
//
//	Node * intersection_list = getIntersection(eleocc);
//	Node * union_list = getUnion(eleocc);
//
//	printf("\nIntersection list is \n");
//	printList(intersection_list);
//
//	printf("\nUnion list is \n");
//	printList(union_list);
//}






int main()
{
	// Method 1 
	Node * head1 = NULL;
	Node * head2 = NULL;
	Node * intersection = NULL;
	Node * unin = NULL;

	/*create a linked lits 10->15->5->20 */
	push(&head1, 20);
	push(&head1, 4);
	push(&head1, 15);
	push(&head1, 10);

	/*create a linked lits 8->4->2->10 */
	push(&head2, 10);
	push(&head2, 2);
	push(&head2, 4);
	push(&head2, 8);


	unin = getUnion(head1, head2);
	intersection = getIntersection(head1, head2);
	cout << "\n First list is " << endl;
	printList(head1);
	cout << "\n Second list is " << endl;
	printList(head2);


	cout << "\n Intersection list is " << endl;
	printList(intersection);

	cout << "\n Union list is " << endl;
	printList(unin);






	// Method 3
	//Node * head1 = NULL;
	//Node * head2 = NULL;
	//push(&head1, 1);
	//push(&head1, 2);
	//push(&head1, 3);
	//push(&head1, 4);
	//push(&head1, 5);
	//push(&head2, 1);
	//push(&head2, 3);
	//push(&head2, 5);
	//push(&head2, 6);
	//printf("First list is \n");
	//printList(head1);
	//printf("\nSecond list is \n");
	//printList(head2);
	//printUnionIntersection(head1, head2);

	system("pause");
	return 0;

}


