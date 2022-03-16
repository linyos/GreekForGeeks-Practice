#include <iostream>


using namespace std;

class Node
{
public:
	int data;
	Node * left , * right;
};


Node * newNode(int data)
{
	Node * temp = new Node;
	temp->data=data;
	temp->left= temp->right=NULL;
	return temp;
}

Node * insert(Node * node , int data)
{
	if (node==NULL) return newNode(data);

	if (data < node->data)
	{
		node->left = insert(node->left , data);
	}
	else if (data> node->data)
	{
		node->right = insert(node->right , data);
	}
	return node;
}


void secondLargestUtil(Node * root, int &c)
{
	if (root==NULL || c >=2)
	{
		return ;
	}
	 secondLargestUtil(root->right , c);
	 c++ ;
	 if (c==2)
	 {
		 cout << "2nd largest element is " << root->data <<endl;
		return ;
	 }
	 secondLargestUtil(root->left , c);
}



void secondLargest(Node * root)
{
	int c = 0;
	secondLargestUtil(root,c);
}

int  main() {
	 Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    secondLargest(root);
   
	system("pause");
	return 0;
}

