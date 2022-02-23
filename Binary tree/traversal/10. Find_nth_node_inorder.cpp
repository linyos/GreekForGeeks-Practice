#include <iostream>
#include<queue>

using namespace std;

// Introduction
class Node
{
public:
	int data;
	Node * left;
	Node * right;
};

Node * newNode(int data)
{
	Node * node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void NthInorder(Node * node, int n) {
	static int count = 0;
	if (node == NULL)
	{
		return;
	}
	if (count <= n )
	{
		// First recur on left child
		NthInorder(node->left, n);
		count++;
		// When count = n then print element
		if (count==n)
		{
			cout << node->data << " ";
		}
		// now recur on right child.
		NthInorder(node->right, n);
	}
}




int main() {
	Node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);

	int n = 4;

	NthInorder(root, n);


	system("pause");
	return 0;
}




