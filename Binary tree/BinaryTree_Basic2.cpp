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




Node * newNode (int key){
	
	Node * temp = new Node;
	temp->data = key;
	temp->left=temp->right = NULL;
	return temp;
}

void inorder(Node * temp){
	if (temp ==NULL)
	{
		return ;
	}
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}

void deleteDeepest(Node * root , Node * d_node){
	queue<Node *> q ;
	q.push (root);
	Node * temp;
	while (!q.empty()){
		temp = q.front();
		q.pop();

		if (temp ==d_node){
			temp = NULL;
			delete(d_node);
			return;
		}
		if (temp->right){
			if (temp->right==d_node)
			{
				temp->right =NULL;
				delete(d_node);
				return;
			}
			else
			{
				q.push(temp->right);
			}
		}
		if (temp->left)
		{
			if (temp->left == d_node)
			{
				temp->left=NULL;
				delete(d_node);
				return ;
			}
			else
			{
				q.push(temp->left);
			}
		}
	}

}



Node * deletion(Node * root , int key){
	if (root==NULL)
	{
		return NULL;
	}
	if (root->left==NULL && root->right ==NULL)
	{
		if (root->data ==key)
		{
			return NULL;
		}
		else
		{
			return root;
		}
	}

	queue<Node *> q ;
	q.push(root);

	Node * temp ;
	Node * key_node = NULL;

	while (!q.empty())
	{
		
		temp = q.front();
		q.pop();
		if (temp->data==key)
		{
			key_node = temp;
		}
		if (temp->left)
		{
			q.push(temp->left);
		}
		if (temp->right)
		{
			q.push(temp->right);
		}
	}

	if (key_node != NULL)
	{
		int x = temp->data;
		deleteDeepest(root , temp);
		key_node->data = x;
	}
	return root; 
}





int main(){
	Node * root = newNode(10);
	root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
 
    cout << "Inorder traversal before deletion : ";
    inorder(root);
	int key = 11;
    root = deletion(root, key);
 
    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

	system("pause");
	return 0 ;
}