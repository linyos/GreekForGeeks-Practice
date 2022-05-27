#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>

using namespace std;




class Node
{
public:
	int data;
	Node * left , * right;
};

Node * newNode(int data)
{
	Node * node = new Node;
	node->data= data;
	node->left = node->right = NULL;
	return node;
}



void inorder(Node * node)
{
	if (node == NULL)
	{
		return ;
	}	
	inorder(node->left);
	cout<< node->data <<" ";
	inorder(node->right);
}


Node * insertNode (Node * root , int data)
{
	if (root==NULL)
	{
		root= newNode(data);
		return root;
	}

	queue <Node *> q;
	q.push(root);

	while (!q.empty())
	{
		Node * temp = q.front();
		q.pop();

		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left = newNode(data);
			return root;
		}

		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right =newNode(data);
			return root;
		}

	}

}




int main()
{  
	Node* root =  newNode(10);
    root->left = newNode(11);
    root->left->left =  newNode(7);
    root->right =  newNode(9);
    root->right->left =  newNode(15);
    root->right->right =  newNode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
 
    int key = 12;
    root = insertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;


	system("pause");
	return 0;
}