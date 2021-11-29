#include<iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>


using namespace std;

class node
{
public:
	int data;
	node * left , * right;

};


node * newnode (int data){

	node * tmp = new node;
	tmp ->data = data;
	tmp ->left = tmp->right=NULL;
	return tmp; 
}


void printLeaves (node * root){
	if (root == NULL)
	{
		return ;
	}

	printLeaves (root->left);

	if (!(root->left) && !(root->right))
	{
		cout<< root->data<<" ";
	}
	printLeaves(root->right);
}




void printBoundaryLeft(node * root){
	if (root==NULL)
	{
		return;
	}

	if (root->left)
	{
		cout<<root->data<<" "; 
		printBoundaryLeft(root->left);
	}
	else if (root->right)
	{
		cout<<root->data<<" ";
		printBoundaryLeft(root->right);
	}
}

void printBoundaryRight (node * root){
	if (root==NULL)
	{
		return ;
	}

	if (root->right)
	{
		printBoundaryRight(root->right);
		cout<<root->data<<" ";
		
	}
	else if (root->left)
	{
		printBoundaryRight(root->right);
		cout<<root->data<< " ";
		
	}
}



void printBoundary (node * root){
	if (root ==NULL)
	{
		return ;
	}

	cout<<root->data <<" ";

	printBoundaryLeft(root->left);
	printLeaves(root->left);
	printLeaves(root->right);
	
	printBoundaryRight(root->right);
}





int main()
{
	node * root= newnode(20);
	root->left = newnode(8);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    root->right = newnode(22);
    root->right->right = newnode(25);


	
	printBoundary(root);

	system("pause");
    return 0;                           
}