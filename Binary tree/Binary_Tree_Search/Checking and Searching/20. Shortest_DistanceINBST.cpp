#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
using namespace std;


class Node
{
public:
	int data;
	Node * left;
	Node * right;
};



Node * newNode(int data)
{
	Node * temp = new Node;
	temp->data = data;
	temp->left = temp ->right = NULL;
	return temp;
}

Node * insert (Node * root , int data)
{
	if (!root)
	{
		root = newNode(data);
	}
	else if (root->data > data)
	{
		root->left = insert(root->left , data);
	}
	else if (root->data < data)
	{
		root->right = insert(root->right , data);
	}
	return root;

}

// The function returns distance of x from root, 
// This function assumes that x exists in BST and BST is not NULL.
int distanceFromRoot (Node * root , int x )
{
	if (root->data ==x){
		return 0;
	}
	else if (root->data > x){
		return   1+ distanceFromRoot(root->left ,x);
	}
	return 1+ distanceFromRoot(root->right ,x);
}


// Return minimum distance between a and b.
// This function assumes that a and b exist in BST.
int distanceBetween2(Node * root , int a , int b)
{

	if (!root) return 0;

	// Both keys lie in left
	if (root->data > a && root->data > b)
	{
		return distanceBetween2(root->left , a, b);
	}

	//Both keys lie in right
	if (root->data <a && root->data< b)
	{
		return distanceBetween2(root->right , a ,b);
	}
	// Lie in opposite directions 
	// Root is LCA of two nodes
	if (root->data >=a && root->data <=b)
	{
		return distanceFromRoot(root ,a) + distanceFromRoot(root,b);
	}
}



int findDistWrapper (Node * root , int a , int b)
{
	if (a > b)
	{
		swap(a, b);
	}
	return distanceBetween2(root, a, b);
}





int  main() {

	/*
			 20 
			/   \
		  10     30
 		 /  \    / \
		5    15 25  35
	
	
	*/



	Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);

	int a = 5 , b =35;
	cout<< findDistWrapper(root , a ,b);

	system("pause");
	return 0;
}



