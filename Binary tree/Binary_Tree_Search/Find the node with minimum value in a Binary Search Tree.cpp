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



Node * insert(Node * node , int data){
	if (node==NULL)
	{
		return newNode(data);
	}
	else
	{
		if (data <= node->data)
		{
			node->left = insert(node->left , data);
		}
		else
		{
			node->right = insert(node->right , data);
		}
		return node;
	}
	
}



int minValue(Node * node){
	Node * current = node;
	while (current ->left != NULL)
	{
		current = current->left;
	}
	return current->data;
}

int main(){
	Node * root = NULL;
	root= insert(root , 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 5);
 
    cout << "\n Minimum value in BST is " << minValue(root);


	system("pause");
	return 0;
}