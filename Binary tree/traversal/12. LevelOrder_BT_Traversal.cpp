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

using namespace std;

class Node
{
public:
	int data;
	Node * left,  * right;
};


Node * newNode(int data)
{
	Node * temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
// Computer the height of a tree
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
/* Print nodes at a current level */
void printCurrentLevel(Node * root , int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
}

// Print level order traversal a tree
void printLevelOrder(Node * root)
{
	int h = height(root);
	int i; 
	for ( i = 1; i <=h; i++)
	{
		printCurrentLevel(root, i);
	}
}




// use queue
void  printLevelOrder2(Node* root)
{
	if (root == NULL)
		return;

	queue<Node *> q;
	q.push(root);

	while (!q.empty())
	{
		Node * node = q.front();
		cout << node->data << " ";
		q.pop();

		if (node->left != NULL)
			q.push(node->left);
		
		if (node->right != NULL)
			q.push(node->right);
	}
}


int main() 
{
	
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	cout << endl;
	printLevelOrder2(root);
	system("pause"); 
	return 0;
}




