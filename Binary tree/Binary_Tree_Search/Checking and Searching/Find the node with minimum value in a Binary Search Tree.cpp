#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
#include <unordered_map>


using namespace std;

class  node
{
public:
	int data;
	node * left, *right;
};

node * newNode(int data) {

	node * Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

node * insert(node * node, int data) {
	if (node==NULL)
	{
		return (newNode(data));
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
}


int minValue(node * root) {
	node * current = root;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current->data;
}


int main()
{
	node * root = NULL;
	root = insert(root, 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 5);

	cout << "\n Minimum value in BST is " << minValue(root);
	system("pause");
	return 0;
	
}


