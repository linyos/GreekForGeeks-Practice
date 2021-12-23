#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;



class node
{
public:
	int data;	
	node * left , *right;
};



node * newNode (int data){
	node * root = new node();
	root->data =data;
	root->left =NULL;
	root->right=NULL;
	return root;
}


// Computer the height of a tree.
//Height is the number f nodes along the longest path from the root 
// node down to the fathest leaf node.

int height(node * node){

	if (node==NULL)
	{
		return 0;
	}
	return  1+ max(height(node->left) , height(node->right));
}


// get diameter of a binary tree
int diameter (node * tree){
	if (tree==NULL)
	{
		return 0;
	}

	int lheight = height(tree->left);
	int rheight = height(tree->right);

	int ldiameter = diameter(tree->left);
	int rdiameter =diameter(tree->right);

	return max(lheight+rheight +1,max(ldiameter , rdiameter ));

}



int main(){
	
	node * root = newNode(1);
	    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
	/* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */


	 // Function Call
    cout << "Diameter of the given binary tree is " <<
     diameter(root);
	system("pause");
	return 0;
}