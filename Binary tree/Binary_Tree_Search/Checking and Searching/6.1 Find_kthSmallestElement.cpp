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
	Node * left , *right;
	int lCount;
};



Node * newNode (int data)
{
	Node *newnode = new Node;
	newnode->data=data;
	newnode->left = newnode->right = NULL;
	newnode->lCount = 0 ;
	return newnode;
}


Node * insert(Node * root , int x )
{
	if (root== NULL) return newNode(x); 

	if (x< root->data)
	{
		root->left = insert(root->left , x);
		root->lCount++;
	}
	else if (x > root->data)
	{
		root->right = insert(root->right , x);
	}
	return root;
}

Node * kthSmallest(Node * root , int k)
{
	if (root == NULL) return NULL ;

	int count = root->lCount +1 ;
	if (count == k ) return root;

	if (count > k )
	{
		return kthSmallest(root->left , k);
	}
	cout<< k <<" " << k-count << endl;
	return kthSmallest(root->right , k-count);
 }













/*
           20
         /   \
        8     22
       / \   
      4   12   
         / \
        10  14


*/





int main()
{ 
	Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
    for (int x : keys)
        root = insert(root, x);
    int k = 4;
    Node* res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->data;

	system("pause");
	return 0;
}