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
	int key;
	Node * left, *right;

	Node() : key(0), left(0), right(0) {};
	Node(int data) : key(data), left(0), right(0) {};
};

Node * newNode(int item) {
	Node * temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void preorder(Node * root) {
	if (root != NULL)
	{
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}


vector <Node * > gerTrees(int arr[], int start, int end) {
	vector<Node *> trees;
	if (start > end)
	{
		trees.push_back(NULL);
		return trees;
	}
	for (int i = start; i <= end; i++)
	{

		vector<Node *> ltrees = gerTrees(arr, start, i - 1);
		vector<Node *> rtrees = gerTrees(arr, i + 1, end);
		for (int j = 0; j < ltrees.size(); j++)
		{
			for (int k = 0; k < rtrees.size(); k++)
			{
				Node * node = newNode(arr[i]);
				node->left = ltrees[j];
				node->right = rtrees[k];
				trees.push_back(node);
			}
		}
	}
	return trees;
}



int main()
{
	int in[] = { 4, 5, 7 };
	int n = sizeof(in) / sizeof(in[0]);

	vector<Node *> trees = gerTrees(in, 0, n - 1);

	cout << "Preorder traversals of different "
		<< "possible Binary Trees are \n";
	for (int i = 0; i < trees.size(); i++)
	{
		preorder(trees[i]);
		printf("\n");

	}

	system("pause");
	return 0;

}