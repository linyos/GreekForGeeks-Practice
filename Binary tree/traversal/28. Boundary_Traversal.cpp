#include <iostream>


using namespace std;

class Node
{
public:
	int data;
	Node * left , * right;
};


Node * newNode(int data)
{
	Node * node = new Node;
	node->data=data;
	node->left = node->right =NULL;
	return node;
}
// Tp print leaf nodes of a binary tree
void printLeaves (Node * root)
{
	if (root == NULL)
	{
		return;
	}
	printLeaves(root->left);

	// Print it if 
	if ((!root->left) && !(root->right))
	{
		cout<<root->data<<" ";
	}
	printLeaves(root->right);
}
//A function to print all left boundary nodes, except a leaf node.
//Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root)
{
	if (root==NULL)
	{
		return;
	}
	if (root->left)
	{
		cout<<root->data<<" ";
		printBoundaryLeft(root->left);
	}
	else if (root->right)
	{
		cout<<root->data<<" ";
		printLeaves(root->right);
	}
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root)
{
	if (root==NULL)
	{
		return;
	}
	if (root->right)
	{
		printBoundaryRight(root->right);
		cout<<root->data<<" ";
	}
	else if (root->left)
	{
		 printBoundaryRight(root->left);
		cout<<root->data<<" " ;
	}

}


// A function to do boundary traversal of a given binary tree
void printBoundary(Node * root)
{
	if (root==NULL)
	{
		return ;
	}
	// 20
 	cout<<root->data<<" ";
	printBoundaryLeft(root->left); // 8
 
	  //// Print all leaf nodes
	// 4 10 14
    printLeaves(root->left); 
	//25 
    printLeaves(root->right);
 
   // // Print the right boundary in bottom-up manner
	//22
    printBoundaryRight(root->right);
}



int  main() {
	Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    printBoundary(root);
 
	system("pause");
	return 0;
}

