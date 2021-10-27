#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;


class Node
{
public:
	int data;
	Node * right;
	Node * left;
	Node() : data(0), right(0), left(0) {};
	Node(int value) : data(value), right(0), left(0) {};



	void printInorder(Node * node);
	void storeInorder(Node * root, int  inorder[], int * index_ptr);
	void arrayToBST(int *arr, Node * root, int * index_ptr);
	void binaryTreeToBST(Node * root);
	int countNodes(Node * root);

};
void Node::storeInorder(Node * root, int inorder[], int * index_ptr) {
	if (root == NULL) {
		return;
	}
	// first store the left subtree.

	storeInorder(root->left, inorder, index_ptr);

	cout << *index_ptr << endl;
	// Copy the root's data
	inorder[*index_ptr] = root->data;
	(*index_ptr)++;

	storeInorder(root->right, inorder, index_ptr);



}

int compare(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}
void Node::arrayToBST(int * arr, Node * root, int * index_ptr) {
	if (root == NULL) {
		return;
	}
	// First update the left subtree
	arrayToBST(arr, root->left, index_ptr);

	// Update root's data and increment index
	root->data = arr[*index_ptr];
	(*index_ptr)++;

	arrayToBST(arr, root->right, index_ptr);



}

void Node::binaryTreeToBST(Node * root) {
	if (root == NULL) {
		return;
	}
	int n = countNodes(root);

	int * arr = new int[n];
	int i = 0;
	storeInorder(root, arr, &i);


	qsort(arr, n, sizeof(arr[0]), compare);

	i = 0;
	arrayToBST(arr, root, &i);

	delete[] arr;

}


// A utility function to print inorder travesal of a binary tree
void Node::printInorder(Node * root) {
	if (root == NULL) {
		return;
	}
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);

}


int Node::countNodes(Node * root) {
	if (root == NULL) {
		return 0;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
}



int main() {
	Node b, *root = NULL;
	root = new Node(10);
	root->left = new Node(30);
	root->right = new Node(15);
	root->left->left = new Node(20);
	root->right->right = new Node(5);

	b.binaryTreeToBST(root);
	//cout << "Following is Inorder Traversal of the converted BST:" << endl;
	//b.printInorder(root);


	system("pause");
	return 0;
}