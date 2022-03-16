#include <iostream>


using namespace std;

class Node
{
public:
	int data;
	Node * left , * right;
};


Node * newNode (int data)
{
	Node * node = new Node;
	node->data=data;
	node->left=node->right = NULL;
	return node;
}

Node* insert(Node * node , int data)
{
	if (node==NULL)
	{
		return newNode(data);
	}
	if (data< node->data)
	{
		node->left = insert(node->left ,data);
	}
	else if (data > node->data)
	{
		node->right= insert(node->right , data);
	}
	return node;

}



bool iterativeSearch(Node * root , int key)
{
	while (root != NULL)
	{
		if (key> root->data)
		{
			root = root->right;
		}
		else if (key < root->data)
		{
			root= root->left;
		}
		else
		{
			 return true; 
		}
	}
	 return false;
}

int  main() {

	 Node* root = NULL;
    root = insert(root, 20);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    if (iterativeSearch(root, 15))
        cout << "Yes";
    else
        cout << "No";
	system("pause");
	return 0;
}

