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

void NthPostordernode(Node * root, int n)
{
	static int flag = 0;
	if (root == NULL)
	{
		return;
	}
	if (flag <=n)
	{
		NthPostordernode(root->left, n);
		NthPostordernode(root->right, n);
		flag++;
		if (flag==n)
		{
			cout << root->data;
		}
	}


}




int main() {
	Node* root = newNode(25);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(18);
	root->left->right = newNode(22);
	root->right->left = newNode(24);
	root->right->right = newNode(32);

	int N = 6;

	// prints n-th node found
	NthPostordernode(root, N);

	system("pause");
	return 0;
}




