#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


class Node
{
public:
	int data;
	Node * left, *right;
};



Node * newNode(int data)
{
	Node * temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL; 
	return temp;
}


int heightAndSize(Node * node, int &size)
{
	if (node==NULL) return 0;

	int l = heightAndSize(node->left, size);
	int r = heightAndSize(node->right, size);
	size++;
	return (l > r) ? l + 1 : r + 1;
}

float density(Node * root)
{
	if (root == NULL) return 0;
	
	int size = 0;

	int _height = heightAndSize(root, size);
	return (float)size / _height;
}





int main() {
	
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);

	printf("Density  of given binary tree is %f", density(root));

	system("pause");
	return 0;
}




