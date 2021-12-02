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
	Node * node = new Node ;
	node->data =data;
	node->left= node->right =NULL;
	return node;
}

int isSumProperty (Node * node){
	int sum =0;
	// If node is NULL or it's a leaf node then return true.
	if (node==NULL || node->left==NULL && node->right==NULL)
	{
		return 1;
	}
	else
	{
		if (node->left != NULL)
		{
			sum += node->left ->data;
		}
		if (node->right != NULL)
		{
			sum += node->right->data;
		}
		return ((node->data==sum) && isSumProperty(node->left) && isSumProperty(node->right) );
	}
}




int main(){
	Node * root = newNode(10);
	root->left = newNode(8);
	root->right=newNode(2);
	 root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(2);
	 if(isSumProperty(root))
        cout << "The given tree satisfies "
            << "the children sum property ";
    else
        cout << "The given tree does not satisfy "
            << "the children sum property ";
 
    getchar();



	system("pause");
	return 0 ;
}