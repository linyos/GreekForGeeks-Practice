#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;


class Node
{
public:
	int data;
	Node * left;
	Node * right;
};


Node * newnode(int data)
{
	Node * node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}


bool hasPathSum(Node * node , int  &sum)
{
	if (node == NULL)
	{
		return (sum == 0);
	}
	else
	{
		bool ans = 0;
		cout << "Sum : " <<    sum << endl;
		int subSum = sum  - node->data;

		if (subSum == 0 && node->left == NULL && node->right == NULL)
		{
			return 1;
		}
		if (node->left)
		{
			ans = ans || hasPathSum(node->left, subSum);
		}
		if (node->right)
		{
			ans = ans || hasPathSum(node->right, subSum);
		}
	}
	
}

int main() 
{
	int sum = 21;


	Node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	root->left->right = newnode(5);
	root->right->left = newnode(2);

	if (hasPathSum(root, sum))
		cout << "There is a root-to-leaf path with sum " << sum;
	else
		cout << "There is no root-to-leaf path with sum " << sum;

	system("pause"); 
	return 0;
}


