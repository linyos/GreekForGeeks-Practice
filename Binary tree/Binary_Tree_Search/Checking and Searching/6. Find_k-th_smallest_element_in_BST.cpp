#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
#include <unordered_map>


using namespace std;

class  node
{
public:
	int data;
	node * left, *right;
};




node * newNode(int data) {
	node * Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	
	return Node;
}


node * insert(node * root, int data) {
	if (root ==NULL)
	{
		return (newNode(data));
	}
	else
	{
		if (data <= root->data)
		{
			root->left = insert(root->left, data);
		}
		else
		{
			root->right = insert(root->right, data);
		}
		return root;
	}
}

node * kthSmallest(node * root, int & k) {
	if (root == NULL)
	{
		return NULL;
	}

	node * left = kthSmallest(root->left, k);
	if (left != NULL)
	{
		return left;
	}
	k--;
	if (k==0)
	{
		return root;
	}
	return kthSmallest(root->right, k);
}


void printkthSmallest(node * root, int k) {
	int count = 0;
	node * res = kthSmallest(root, k);
	if (res ==NULL)
	{
		cout << "There are less than k nodes in the BST";
	}
	else
	{
		cout << "K-th Smallest Element is " << res->data;
	}

}


int main()
{
	node * root = NULL;
	int keys[] = { 20 ,8,22,4,12,10,14 };
	for (int x : keys)
	{
		root = insert(root, x);
	}

	int k = 3;
	printkthSmallest(root, k);

	
	system("pause");
	return 0;
}


