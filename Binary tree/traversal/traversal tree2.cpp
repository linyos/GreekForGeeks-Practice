#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
using	namespace std;
class Node
{
public:
	int data;
	Node * left, *right;
	Node(int data) : data(data), right(NULL), left(NULL) {};
};



// Traverse the binary tree without recursion and without stack
void MorrisTraversal(Node * root) {
	Node * current, *pre;
	if (root == NULL) {
		return;
	}
	current = root;
	while (current != NULL)
	{
		if (current->left == NULL)
		{
			//cout << current->data << " ";
			current = current->right;
		}
		else
		{

			// Find the inorder predecessor of current
			pre = current->left;
			cout << pre->data << " ";
			while (pre->right != NULL && pre->right != current)
			{
				pre = pre->right;
			}

			if (pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				//cout << current->data << " ";
				current = current->right;
			}
			cout << pre->data << " ";

		}
	}



}


int main()
{
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);


	MorrisTraversal(root);
	system("pause");
	return 0;

}