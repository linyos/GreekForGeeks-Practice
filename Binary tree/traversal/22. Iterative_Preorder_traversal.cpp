#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


class Node
{
public:
	int data;
	Node * left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};


void preorderIterative(Node * root)
{
	if (root==NULL)
	{
		return;
	}
	stack<Node *> st; 
	Node * curr = root;

	while (!st.empty() || curr!= NULL)
	{
		while (curr != NULL)
		{
			cout << curr->data << " ";
			if (curr->right)
			{
				st.push(curr->right);
			}
			curr = curr->left;
		}

		if (st.empty() == false)
		{
			curr = st.top();
			st.pop();
		}

	}

	
}





int main() {
	
	Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->left->left = new Node(70);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->left->left->right = new Node(80);

	preorderIterative(root);


	system("pause");
	return 0;
}




