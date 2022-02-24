#include <iostream>
#include<queue>

using namespace std;

// Introduction
class Node
{
public:
	int data;
	Node* left;
   Node* right;
	
};


Node * newNode(int data)
{
	Node * temp = new Node;
	temp->data =data;
	temp->left = temp->right = NULL;
	return temp;
}


bool isMirror(struct Node* root1, struct Node* root2)
{
	if (root1 ==NULL && root2 ==NULL)
	{
		return true;
	}


	if (root1 && root2 && root1->data == root2->data)
	{
		return isMirror(root1->left , root2->left) && isMirror(root1->right , root2->right);
	}

	return false;
}


bool isSymmetric(Node * root)
{
	return isMirror(root, root);
}

int main() {
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
 
    if(isSymmetric(root))
      cout<<"Symmetric";
    else
      cout<<"Not symmetric";


	system("pause");
	return 0;
}







