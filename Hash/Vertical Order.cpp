#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using	namespace std;

class Node
{
public:
	int data;
	Node * left, *right;
};


Node * newNode(int key) {
	Node * node = new Node;
	node->data = key;
	node->left = node->right = NULL;
	return node;
}



// &m => get address and change value
void getVerticalOrder(Node  * root, int hd, map <int, vector <int >> &m) {
	if (root == NULL) {
		return;
	}

	//cout << "HD " << hd << endl;
	// Store current node in map 'm'
	m[hd].push_back(root->data);

	// Store nodes in left subtree
	getVerticalOrder(root->left, hd - 1, m);

	// Store node in right subtree 
	getVerticalOrder(root->right, hd + 1, m);
}


void printVerticalCalOrder(Node * root) {
	map <int, vector<int> >  m;
	int hd = 0;

	getVerticalOrder(root, hd, m);

	map <int, vector<int> > ::iterator it;

	for (it = m.begin(); it != m.end(); it++)
	{
		//cout << it->first << endl; // -2 -1 0 1 2  (HD)
		for (int i = 0; i < it->second.size(); ++i)
		{
			cout << it->second[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	cout << "Vertical order traversal is n" << endl;
	printVerticalCalOrder(root);

	system("pause");
	return 0;
}