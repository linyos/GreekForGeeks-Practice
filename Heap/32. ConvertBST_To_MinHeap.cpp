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
	Node *left , *right;
};


// allocate a new node with the given data and null 
// left and right pointer
Node * newNode (int data)
{
	Node * temp = new Node;
	temp->data=data;
	temp->left= temp->right = NULL;
	return temp;
}

// inorder Traversal of the tree so as to store the node value in 'arr' in sorted order
void inorderTraversal(Node * root  ,  vector<int> & arr)
{
	if (root==NULL) return ;
	// first recur on left subtree
	inorderTraversal(root->left , arr);
	// copy the data of the node.
	arr.push_back(root->data);
	// recur on right subtree
	inorderTraversal(root->right , arr);
}


// function for the preorder traversal of the tree
void preorderTraversal(Node* root)
{
	if (!root ) return ;

	cout << root->data <<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}




// Function to convert the given BST to min heap
// perform preorder traversal of the tree
void BSTToMinHeap(Node * root , vector<int> arr , int *i )
{
	if (root==NULL) return ;
	 // first copy data at index 'i' of 'arr' to
    // the node
	root->data = arr[++*i];
	 // then recur on left subtree
	BSTToMinHeap(root->left, arr , i);
	  // now recur on right subtree
	BSTToMinHeap(root->right , arr , i );

}



void convertToMinHeapUtil(Node *  root)
{
	vector<int> arr;
	int i = -1;

	inorderTraversal(root , arr);


	// BST to Min heap conversion
	BSTToMinHeap(root , arr , &i);
}



int main()
{ 
	Node * root = newNode(4);
	 root->left =newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
 
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
	 
	

	system("pause");
	return 0;
}