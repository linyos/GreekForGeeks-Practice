#include <iostream>

using namespace std;


class Node
{
public:
	int data;
	Node * left ;
	Node * right;
};


Node * newNode(int data){
	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right=NULL;
	return node;
}



void preOrder (Node * node){
	if (node==NULL)
	{
		return;
	}
	cout<<node->data <<" ";
	preOrder(node->left);
	preOrder(node->right);
}


Node * sortedArrayToBST (int arr[] , int start , int end){
	if (start > end)
	{
		return NULL;
	}
	int mid = start + (end- start)/2; 
	Node * root = newNode(arr[mid]);
	root ->left = sortedArrayToBST(arr , start , mid-1);

	root->right = sortedArrayToBST(arr , mid+1 , end);

	return root;
}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
	Node * root = sortedArrayToBST(arr , 0 , n-1);
	 cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
	system("pause");
	return 0;
}