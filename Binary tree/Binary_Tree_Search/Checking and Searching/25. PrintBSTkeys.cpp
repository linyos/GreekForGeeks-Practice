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


void print(node * root, int k1, int k2)
{
	if (root==NULL)
	{
		return;
	}
	// 
	if (k1 < root->data)
	{
		print(root->left, k1, k2);
	}
	// 
	if (k1 <=root->data && k2>= root->data)
	{
		cout << root->data << " ";
	}
	print(root->right, k1, k2);
}



node *newNode(int data)
{
	node * current = new node();
	current->data = data;
	current->left = current->right = NULL;
	return current;
}
int main() {
	node * root = new node;
	int k1 = 10, k2 = 25;
	root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	print(root, k1, k2);
	system("pause");
	return 0;
}




