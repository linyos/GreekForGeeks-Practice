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
	node * current = new node;
	current->data = data;
	current->left = current->right = NULL;
	return current;
}


node * insert(node * root, int data) {
	if (root == NULL) return newNode( data);

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


void inorder(node * root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}



node * leafDelete(node * root)
{
	if (root==NULL) return  NULL;
	
	if (root->left== NULL && root->right== NULL)
	{
		free(root);
		return NULL;
	}
	root->left = leafDelete(root->left);
	root->right = leafDelete(root->right);
	return root;
}

int main() {
	
	node* root = NULL;
	root = insert(root, 20);
	insert(root, 10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 30);
	insert(root, 25);
	insert(root, 35);
	cout << "Inorder before Deleting the leaf Node." << endl;
	inorder(root);
	cout << endl;
	leafDelete(root);
	cout << "INorder after Deleting the leaf Node." << endl;
	inorder(root);


	system("pause");
	return 0;
}




