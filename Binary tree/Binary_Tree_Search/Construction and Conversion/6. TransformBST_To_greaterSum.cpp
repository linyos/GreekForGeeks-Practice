#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
	int data;
	Node * left, *right;
};



Node * newNode(int item)
{
	Node * node = new Node;
	node->data = item;
	node->left = node->right = NULL;
	return node;
}



void transformTreeUtil(Node *root, int *sum)
{
	if (root == NULL) return;
	// Recur for right subtree
	transformTreeUtil(root->right, sum);
	// Update sum
	*sum = *sum + root->data;
	// Store old sum in current node
	root->data = *sum - root->data;
	// Recur for left subtree
	transformTreeUtil(root->left, sum);

}


void transformTree(Node *root)
{
	int sum = 0;
	transformTreeUtil(root, &sum);
}


void printInorder(Node * root)
{
	if (root == NULL) return;
	
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}



int main() 
{
	Node *root = newNode(11);
	root->left = newNode(2);
	root->right = newNode(29);
	root->left->left = newNode(1);
	root->left->right = newNode(7);
	root->right->left = newNode(15);
	root->right->right = newNode(40);
	root->right->right->left = newNode(35);

	cout << "Inorder Traversal of given tree\n";
	printInorder(root);
	transformTree(root);

	cout << "\n\nInorder Traversal of transformed tree\n";
	printInorder(root);

	system("pause");
	return 0;
}




