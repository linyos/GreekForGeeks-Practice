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


void printPostorder(Node* root) {

	if (root == NULL)
	{
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);

	cout << root->data << " ";
}



void printInorder(Node * root) {
	if (root == NULL)
	{
		return;
	}
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

void printPreorder(Node * root) {
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}




void Recursive_Inorder(Node * root) {

	stack <Node *> s;
	Node * curr = root;

	while (curr != NULL || s.empty() == false)
	{
		while (curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout << curr->data << " ";
		curr = curr->right;
	}

}

int main()
{
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);





	cout << "\n Inorder traversal without recursive \n";
	Recursive_Inorder(root);
	system("pause");
	return 0;

}