#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Node
{
public:
	int data;
	Node * right, *left;
};

Node * newNode( int data)
{
	Node * temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printInorder(Node * node)
{
	if (node==NULL)
	{
		return;
	}
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}




int countNodes(Node * root)
{
	if (root==NULL)
	{
		return 0;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
}


//The function that store inorder traversal of a tree rooted with node.
void storeInorder(Node * node, int inorder[], int * index_ptr)
{
	if (node==NULL)
	{
		return;
	}
	// First store the left subtree.
	
	storeInorder(node->left, inorder, index_ptr);

	//cout << index_ptr << " " << *index_ptr << endl;
	// Copy the root's data
	inorder[*index_ptr] = node->data;
	(*index_ptr)++; // increase index for next entry

	// Finally store the right subtree.
	storeInorder(node->right, inorder, index_ptr);
}

// the function is needed for lib function qsort
int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int *)b);
}

void arrayToBST(int *arr, Node * root, int * index_ptr)
{
	if (root==NULL)
	{
		return;
	}
	//First update the left subtree.
	arrayToBST(arr, root->left, index_ptr);

	//Now update root's data and increment index
	root->data = arr[*index_ptr];
	(*index_ptr)++;

	arrayToBST(arr, root->right, index_ptr);
}




void binaryTreeToBST(Node  * root)
{
	if (root==NULL)
	{
		return;
	}
	// Count the number of nodes in Binary Tree
	int n = countNodes(root);

	// create a temp array [] and store inorder traversal of tree in arr[].
	int *arr = new int[n];
	int i = 0;
	
	
	storeInorder(root, arr, &i);
	

	 //Sort the array using lib function for quick sort
	qsort(arr, n, sizeof(arr[0]), compare);
	
	// Copy array element back to binary tree.
	i = 0;

	arrayToBST(arr, root, &i);
	delete[] arr;


}




int main() {
	Node * root = NULL;
	/* Constructing tree given in the above figure
	   10
	   / \
	   30 15
   /     \
   20     5 */
	root = newNode(10);
	root->left = newNode(30);
	root->right = newNode(15);
	root->left->left = newNode( 20);
	root->right->right = newNode(5);

	// convert Binary Tree to BST
	binaryTreeToBST(root);

	cout << "Following is Inorder Traversal of the converted BST:" << endl;
	printInorder(root);

	system("pause");
	return 0;
}




