#include <iostream>
#include<queue>

using namespace std;

// Introduction
class Node
{
public:
	int data;
	Node * right;
	Node * left;
};

Node * newNode (int data)
{
	Node * node = new Node();
	node->data = data;
	node->left = node->right=NULL;
	return node;
}


bool TreeContinuous(Node * ptr)
{
	if (ptr==NULL)
	{
		return true;
	}

	if (ptr->left == NULL &&ptr->right==NULL)
	{
		return true;
	}
	//IF left subtree is empty. then only check right
	if (ptr->left==NULL)
	{
		return (abs(ptr->data - ptr->right->data)==1 && TreeContinuous(ptr->right));
	}
	if (ptr->right==NULL)
	{
		return (abs(ptr->data - ptr->left->data)==1 && TreeContinuous(ptr->left));
	}
	return (abs(ptr->data - ptr->left->data)==1 &&
		   abs(ptr->data - ptr->right->data)==1 &&
		   TreeContinuous(ptr->left) &&TreeContinuous(ptr->right));
}




int main() {

	 Node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(4);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(5);
    
	TreeContinuous(root) ? cout<<"Yes" : cout<<"No";
	system("pause");
	return 0;
}




