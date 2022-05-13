#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Node
{
public:
	int data;
	Node * right, *left;
};


Node * newnode(int data)
{
	Node * node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}



void inorder(Node * root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}


Node * insert(Node * node, int data)
{
	if (node == NULL)
	{
		return newnode(data);
	}

	if (data < node->data)
	{
		node->left = insert(node->left, data);
	}
	else
	{
		node->right = insert(node->right, data);
	}
	return node;
}

// Return the node with minimum key value found in that tree.
Node * minValueNode(Node * node)
{
	Node * current = node;
	while (current && current->left != NULL)
	{
		current = current->left;
	}
	return  current;
}



Node * deleteNode(Node * root, int key)
{
	if (root == NULL)
	{
		return root;
	}

	// If  the key to be  deleted is smaller than root's key,
	// then it lies in left subtree.
	if (key < root->data)
	{
		root->left = deleteNode(root->left, key);
	}
	// If the key to be deleted is greater than root's key
	// then it lies in right subtree.
	else if (key > root->data)
	{
		root->right = deleteNode(root->right, key);
	}
	// If key is same as root's key , then this is the node to be deleted
	else
	{
		// node has no child
		if (root->left== NULL && root->right ==NULL)
		{
			return NULL;
		}
		// node with only one child or no child
		else if (root->left ==NULL)
		{
			Node * temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right== NULL)
		{
			Node * temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor
		// Smallest in the right subtree.
		Node *temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);

	}
	return root;
}


int main() {
	Node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);
	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	 cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	cout << "\nInorder traversal of the modified tree \n";
	inorder(root);


	cout << "\nDelete 30\n";
	root = deleteNode(root, 30);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 50\n";
	root = deleteNode(root, 50);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);


	system("pause");
	return 0;
}




