#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include<cassert>
#include <set>
#include <map>

using namespace std;

class Node
{
public:
	int data;
	Node * left ,*  right;
};

Node * newNode (int data)
{
	Node * temp  = new Node;
	temp->data =data;
	temp->left= temp->right =NULL;

	return temp ;
}




Node * insert (Node * node  ,int key )
{
	if (node==NULL)
	{
		return newNode(key);
	}
	if (key < node->data)
	{
		node->left = insert(node->left , key);
	}
	else
	{
		node->right = insert(node->right , key);
	}
	return node;
}


// This function finds predecessor and successor of key in BST.

void findPreSuc(Node * root , Node *&prev , Node *&suc , int key)
{
	if (root== NULL) return;
	// If key is present at root
	if (root->data == key)
	{
		// the maximum value in left subtree is predecessor
		if (root->left != NULL)
		{
			Node * temp = root->left;
			while (temp->right)
			{
				temp = temp->right;
			}
			prev = temp ;
		}
		// the minimum value in right subtree is successor
		if (root->right != NULL)
		{
			Node * temp = root->right;
			while (temp->left)
			{
				temp = temp->right;
			}
			suc = temp;
		}
		return;
	}
	// If key is smaller than root's key, go th left subtree
	if (root->data > key)
	{
		suc =root;
		findPreSuc(root->left ,prev ,suc , key);
	}
	// IF key is greater than root's key, go the right subtree.
	else
	{
		prev=root;
		findPreSuc(root->right ,prev ,suc , key);
	}
}





int  main() {
	
	int key = 50 ;

	/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

	Node * root= NULL;
	root= insert(root , 50);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
	Node * prev = NULL , *suc = NULL;

	findPreSuc(root ,prev, suc , key);

	 if (prev != NULL)
      cout << "Predecessor is " << prev->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";

	system("pause");
	return 0;
}



