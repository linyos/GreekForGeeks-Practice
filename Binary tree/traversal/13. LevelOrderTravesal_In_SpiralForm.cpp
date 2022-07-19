#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>

using namespace std;

class Node
{
public:
	int data;
	Node * left, *right;
};

Node * newNode(int data)
{
	Node * temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int height(Node * node)
{
	if (node == NULL)
		return 0;
	else {
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return lheight + 1;
		else
			return rheight + 1;
	}
}



// Recursive
void printGivenLevel(Node * root, int level, int ltr)
{

	cout<<"root:"  << root->data << " ";
	
	if (root == NULL)
		return;
	if (level == 1) {
		cout << root->data << " ";
	}
	else if (level > 1) {
		if (ltr){
			printGivenLevel(root->left, level - 1, ltr);

			printGivenLevel(root->right, level - 1, ltr);
		}
		else {
			//cout << root->data << endl;;
			printGivenLevel(root->right, level - 1, ltr);

			printGivenLevel(root->left, level - 1, ltr);
		}
		
	}


}






// print spiral traversal of a tree.
void printSpiral(Node * root)
{
	int h = height(root);
	int i; 
	bool ltr = false;
	// ltr -> left to right , if this variable is set,
	// then the given level is traversed from left to right 
	for (int i = 1; i <=2; i++)
	{
	
		printGivenLevel(root, i, ltr);
		// Revert ltr to traverse next level in opposite order
		ltr = !ltr;
			
	}
}









// Method 2 : Iteraitve
void printSpiral1(Node * root)
{
	if (root==NULL)
	{
		return;
	}
	stack< Node * > s1;// For levels to be printed from right to left
	stack<Node * > s2;// For levels to be printed from left to right


	// Push First level to first stack 's1'
	s1.push(root);
	// keep printing while any of the stack has some nodes.
	while (!s1.empty() || !s2.empty())
	{
		while (!s1.empty())
		{
			Node  * temp = s1.top();
			s1.pop();
			cout << temp->data << " ";

			if (temp ->right )
			{
				s2.push(temp->right);
			}
			if (temp->left)
			{
				s2.push(temp->left);
			}

		}
		// Print nodes of current level from s2 and push nodes of
	   // next level to s1
		while (!s2.empty())
		{
			Node * temp = s2.top();
			s2.pop();
			cout << temp->data << " ";

			if (temp->left)
			{
				s1.push(temp->left);
			}
			if (temp->right)
			{
				s1.push(temp->right);
			}
		}
	}
}

int main() {


	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	printf("Spiral Order traversal of "
		"binary tree is \n");

	printSpiral1(root);
	system("pause");
	return 0;
}
