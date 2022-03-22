#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include<unordered_map>
#include <set>
#include <stack>

using namespace std;

class Node
{
public:
	int data;
	Node * left, *right;
};

Node * newNode(int data)
{
	Node * node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return  node;
}




Node * insert(Node  * node, int data)
{
	if (node==NULL)
	{
		return newNode(data);
	}

	if (data < node->data)
	{
		node->left = insert(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = insert(node->right, data);
	}
	return node;
}


int findMaxForN(Node * root, int N)
{
	if (root==NULL) return -1;
	if (root->data == N) return N;

	else if (root->data < N)
	{
		int k = findMaxForN(root->right, N);
		if (k==-1)
		{
			return root->data;
		}
		else
		{
			return k;
		}
	}
	else if (root->data > N)
	{
		return findMaxForN(root->left, N);
	}

}

int main() {
	int N = 4;

	// creating following BST
	/*
				  5
			   /   \
			 2     12
		   /  \    /  \
		  1   3   9   21
					 /   \
					19   25  */
	Node* root = NULL;
	root=insert(root, 25);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 12);
	insert(root, 9);
	insert(root, 21);
	insert(root, 19);
	insert(root, 25);
	
	cout << findMaxForN(root, N) << endl;

	system("pause");
	return 0;
}




