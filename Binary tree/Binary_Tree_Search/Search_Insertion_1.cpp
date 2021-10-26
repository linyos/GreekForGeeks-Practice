#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;


class BST
{
public:
	int data;
	BST * left, *right;
	BST() :data(0), left(0), right(0) {};
	BST(int value) : data(value), left(0), right(0) {};
	BST * insert(BST * root, int value);
	void inorder(BST *);
	BST * search (BST *root , int key );
	BST * minValueNode (BST * root);
	BST * deleteNode (BST * root , int key);
};


BST * BST::minValueNode (BST * root){
	BST * current = root ;
	while (current && current->left !=NULL ){
		current = current->left;
	}
	return current;
}

BST * BST::deleteNode(BST * root , int key ){
	if (root ==NULL){
		return root;
	}

	if (key < root->data){
		root->left = deleteNode(root->left , key);
	}
	else if (key > root->data){
		root->right = deleteNode(root->right, key);
	}
	else{
		if (root->left==NULL && root->right==NULL){
			return NULL;
		}
		else if (root->left==NULL)
		{
			BST * tmp = root->right;
			delete tmp;
			//free(tmp);
			return tmp;
		}
		else if (root->right==NULL)
		{
			BST * tmp = root->left;
			delete tmp;
			//free(tmp);
			return tmp;
		}


		BST * tmp = minValueNode(root->right);
		root->data= tmp->data;
		root->right = deleteNode(root->right , tmp->data);	
	}
	return root;
}


BST * BST::insert(BST * root, int value) {
	if (!root) {
		// Insert the first node, if root is NULL.
		return new BST(value);
	}
	if (value > root->data){

		root->right = insert(root->right, value);
	}
	else{
		root->left = insert(root->left, value);
	}


	return root;

}


BST * BST::search (BST * root , int key){
	if (root == NULL || root->data == key){
		return root ;
	}
	if (root->data  < key){
		return search (root->right , key);
	}
	return search(root->left , key);
}

void BST::inorder(BST * root) {
	if (!root) {
		return;
	}
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);

}

int main() {
	BST b, *root = NULL;

	root = b.insert(root, 50);
	b.insert(root, 30);
	b.insert(root, 20);
	b.insert(root, 40);
	b.insert(root, 70);
	b.insert(root, 60);
	b.insert(root, 80);


	cout << "Inorder traversal of the given tree \n";
	b.inorder(root);

	  cout << "\nDelete 20\n";
	  root = b.deleteNode(root , 20);
	   cout << "Inorder traversal of the modified tree \n";
   b.inorder(root);


	system("pause");
	return 0;
}