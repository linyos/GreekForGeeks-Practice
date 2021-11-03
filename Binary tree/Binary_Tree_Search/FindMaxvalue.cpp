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
	Node* left;
	Node * right;
	
	Node() : data(0), left(0), right(0) {};
	Node(int value) : data(value), left(0), right(0) {};

	Node* insert(Node * node, int data);
	int minValue(Node * node);
};




Node * Node::insert(Node * node, int data) {
	if (node==NULL)
	{
		//node = new node();
		return new Node(data);
	}
	else
	{
		if (data <= node->data)
		{
			node->left = insert(node->left, data);
		}
		else
		{
			node->right = insert(node->right, data);
		}
		return node;
	}
	return node;
}


int Node::minValue(Node * node) {

	Node * current = node;
	while (current->left !=NULL){
		current = current->left;
	}
	return current->data;

}



int main (){
	Node b, *root = NULL;
	root = b.insert(root, 4);
	b.insert(root, 2);
	b.insert(root, 1);
	b.insert(root, 3);
	b.insert(root, 6);
	b.insert(root, 5);
	cout << "\n Minimum value in BST is " << b.minValue(root);
	system("pause");
	return 0;
}