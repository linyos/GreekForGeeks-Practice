#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;


class BST
{
public:
	int data;
	BST * left, *right;
	BST() :data(0), left(0), right(0) {};
	BST(int value) : data(value), left(0), right(0) {};
	BST * insert(BST * root, int value);
	void inorder(BST *);
};

BST * BST::insert(BST * root, int value) {
	if (!root) {
		// Insert the first node, if root is NULL.
		return new BST(value);
	}
	if (value > root->data)
	{

		root->right = insert(root->right, value);
	}
	else
	{
		root->left = insert(root->left, value);
	}


	return root;

}


void BST::inorder(BST * root) {
	if (!root) {
		return;
	}
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);

}

int main() {
	BST b, *root = NULL;
	root = b.insert(root, 50);
	b.insert(root, 30);
	b.insert(root, 20);
	b.insert(root, 40);
	b.insert(root, 70);
	b.insert(root, 60);
	b.insert(root, 80);

	b.inorder(root);


	system("pause");
	return 0;
}