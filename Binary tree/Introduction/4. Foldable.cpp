#include <iostream>
#include <fstream>
#include <string>

using namespace std;



class Node 
{
public:
	int data;
	Node * left;
	Node * right;
};

// Method1
//void mirror (Node * node);
//bool isStructSame(Node* a, Node* b);
//
//
//bool isFoldable(Node * root){
//	bool res ;
//	if (root ==NULL)
//	{
//		return true;
//	}
//
//	mirror(root ->left);
//
//	res = isStructSame(root->left , root->right);
//	 mirror(root->left);
// 
//	 return res;
//
//}
//bool isStructSame(Node *a , Node *b){
//	if (a==NULL && b==NULL)
//	{
//		return true;
//	}
//	if (a!= NULL && b !=NULL && isStructSame(a->left, b->left) && isStructSame(a->right , b->right))
//	{
//		return true;
//	}
//	return false;
//}
//
//
//void mirror (Node * node){
//	if (node==NULL)
//	{
//		return ;
//	}
//	else
//	{
//		Node * tmp ;
//		// do the subtree
//		mirror(node->left);
//		mirror(node->right);
//
//		// swap the pointer in this node
//		tmp = node->left;
//		node->left = node->right;
//		node->right = tmp;
//
//	}
//}
//Node * newNode(int data){
//	Node * node = new Node();
//	node->data= data;
//	node->left=NULL;
//	node->right=NULL;
//
//	return node;
//}


// Method2 
bool IsFoldableUtil(Node * n1 , Node *n2);

bool IsFoldable(Node * root){
	if (root==NULL)
	{
		return true;
	}
	return IsFoldableUtil(root->left , root->right);
}

bool IsFoldableUtil(Node * n1 , Node *n2){
	if (n1==NULL && n2==NULL)
	{
		return true;
	}
	if (n1==NULL || n2==NULL)
	{
		return false;
	}

	return IsFoldableUtil(n1->left , n2->right) && IsFoldableUtil(n1->right , n2->left);

}


Node * newNode(int data){
	Node * node = new Node();
	node->data= data;
	node->left=NULL;
	node->right=NULL;

	return node;
}



int main(){
	
	
	Node * root= newNode(1);
	root->left = newNode(2);
	root->right=newNode(3);
	 root->right->left = newNode(4);
    root->left->right = newNode(5);
 if (IsFoldable(root) == 1) {
        cout << "tree is foldable";
    }
    else {
        cout << "\ntree is not foldable";
    }





	 
	system("pause");
	return 0;
}