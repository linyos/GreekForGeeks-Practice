#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <list>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Node
{
public:
	int data;
	Node * left , *right;
};





Node * newNode (int data)
{
	Node * root= new Node;
	root->data=data;
	root->left= root->right = NULL;
	return root;
}

Node  * insert(Node * root , int data)
{
	if (root==NULL) return  newNode(data);

	if (data < root->data)
	{
		root->left = insert(root->left , data);
	}
	else if (data > root->data)
	{
		root->right = insert(root->right , data);
	}
	return root;
}


// Function to find k'th smallest element in BST 
// Here count denote the number of nodes processed so far
int kcount = 0 ;
Node * kthSmallest(Node * root , int & k )
{
	if (root==NULL) return  NULL;
	
	Node * left = kthSmallest(root->left , k);

	if (left != NULL) return left;

	kcount +=1;

	if (kcount==k)
	{
		return root;
	}
	return kthSmallest(root->right , k);
}


// Function to print k'th smallest element in BST
void printkthSmallest(Node * root , int k )
{
	if (root==NULL) return ;
	Node * res = kthSmallest(root , k );
	if (res==NULL)
	{
		cout<< "NO"<<endl;
	}
	else
	{
		cout<<"Element is " << res->data <<endl;
	}
}



int main()
{
	Node * root= NULL;
	int keys[] = { 20 ,8,22,4,12,10,14 };
	for (int x : keys)
	{
		root = insert(root, x);
	}

	int k = 4;
	printkthSmallest(root, k);

	
	system("pause");
	return 0;
}
