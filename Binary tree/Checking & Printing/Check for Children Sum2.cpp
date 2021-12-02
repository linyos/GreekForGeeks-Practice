#include <iostream>
#include <string >
#include <queue>
#include <algorithm>


using namespace std;



class Node
{
public:
	int data;
	Node * left , * right;
};

Node * newNode (int data){
	Node * node = new Node;
	node->data = data;
	node->left = node->right =NULL;
	return node;
}


int sum (Node * root){
	if (root==NULL)
	{
		return 0 ;
	}
	return sum(root->left) + root->data  + sum(root->right);
}


int isSumTree (Node * node){
	int ls , rs ;
	if (node ==NULL || node->left==NULL && node->right==NULL)
	{
		return 1 ;
	}

	ls= sum(node->left);
	rs= sum(node->right);

	if ((node->data == ls+rs) && isSumTree(node->left) && isSumTree(node->right))
	{
		return 1;
	}
	return 0 ;
}




int main(){
	Node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3); 
    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
 
    getchar();


	system("pause");
	return 0 ;
}