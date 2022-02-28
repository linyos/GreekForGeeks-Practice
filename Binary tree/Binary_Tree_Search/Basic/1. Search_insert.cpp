#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;

class BST
{
private:
	int data;
	BST * left;
	BST * right;
public:
	// Default constructor.
	BST();
	// Parameterized constructor.
	BST(int);
	//Insert function
	BST * Insert(BST *, int);
	//Inorder traversal
	void Inorder(BST *);
	BST * search(BST *, int);

};


// Default Constructor definition
BST::BST() :data(0)  , left(NULL) , right(NULL)  {}



BST::BST(int value)
{
	data = value;
	left = right = NULL;
}

BST * BST::search(BST * root, int key)
{
	if (root ==NULL || root->data == key)
	{
		return root;
	}

	if (root->data  < key)
	{
		return search(root->right, key);
	}
	return search(root->left, key);
}



BST * BST::Insert(BST * root, int value)
{
	if (!root)
	{
		return new BST(value);
	}
	if (value > root->data)
	{
		root->right = Insert(root->right, value);
	}
	else
	{
		root->left = Insert(root->left, value);
	}
	return root;
}



void BST::Inorder(BST * root)
{
	if (!root)
	{
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}


int main() {
	BST  b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);



	cout << b.search(root ,60) << endl;
		 
	system("pause");
	return 0;
}




