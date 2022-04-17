#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>

using namespace std;


class node
{
public:
	int data;
	node * left, *right;
};


node * newNode(int data)
{
	node *  current = new node();
	current->data = data;
	current->left = current->right = NULL;
	return current; 
}

node * insert(node * root, int data)
{
	if (root == NULL) return newNode(data);
	if (root->data > data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root; 
}

void inorderTraversal(node * root)
{
	if (root)
	{
		inorderTraversal(root->left);
		cout << root->data << " ";
		inorderTraversal(root->right);
	}
}


node * removeOutsideRange(node * root, int min, int max)
{
	if (root == NULL)
	{
		return NULL;
	}
	root->left = removeOutsideRange(root->left, min, max);
	root->right = removeOutsideRange(root->right, min, max);

	if (root->data < min )
	{
		node * rChild = root->right;
		delete root; 
		return rChild;
 	}
	if (root->data > max)
	{
		node * lChild = root->left;
		delete root;
		return lChild;
	}
	return root;
}






int main() {
	
	node * root = NULL;
	root = insert(root, 6);
	root = insert(root, -13);
	root = insert(root, 14);
	root = insert(root, -8);
	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 7);

	cout << "Inorder traversal of the given tree is: ";
	inorderTraversal(root);

	root = removeOutsideRange(root, -10, 13);

	cout << "\nInorder traversal of the modified tree is: ";
	inorderTraversal(root);


	system("pause");
	return 0;
}




