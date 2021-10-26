#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;

class node
{
public:
	int data;
	node * left;
	node * right;
	node() : data(0), left(0), right(0) {};
	node(int value) : data(value), left(0), right(0) {};
	void printInorder(node * root);
	node * constructTreeUtil(int pre[], int * preIndex, int low, int high, int size);
	node * constructTree(int pre[], int size);
};

node * node::constructTreeUtil(int pre[], int * preIndex, int low, int high, int size){
	
	
	if (* preIndex >= size || low > high){
		return NULL;	
	}

	node * root =new node(pre[*preIndex]);
	*preIndex = *preIndex + 1;


	if (low==high){
		return root;
	}

	int i;
	for ( i = low; i <= high; ++i)
	{
		if (pre[i] > root->data)
		{
			break;
		}
	}

	root->left = constructTreeUtil(pre, preIndex, *preIndex, i - 1, size);

	root->right = constructTreeUtil(pre, preIndex, i, high, size);


	return root;

}


// The main function to construct BST
node * node::constructTree(int pre[], int size) {
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, 0, size - 1, size);
}

// A utility function to print inorder travesal of a binary tree
void node::printInorder(node * root) {
	if (root==NULL){
		return;
	}
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
	
}







int main() {
	int pre[] = { 10 ,5,1,7,40,50 };
	int size = sizeof(pre) / sizeof(pre[0]);
	node b;
	node * root =b.constructTree(pre, size);
	b.printInorder(root);

	system("pause");
	return 0;
}