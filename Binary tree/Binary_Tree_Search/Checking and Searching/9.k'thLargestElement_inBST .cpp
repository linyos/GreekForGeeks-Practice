#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int key;
	Node *left , *right;
};


Node * newNode (int data)
{
	Node * temp = new Node();
	temp->key=data;
	temp->left = temp->right = NULL;
	return temp;
}


Node * insert(Node * node , int data)
{
	if (node==NULL )
	{
		return newNode(data);
	}

	if (data < node->key)
	{
		node->left = insert(node->left , data);
	}
	else if (data > node->key)
	{
		node->right = insert(node->right , data);
	}
	return node;
}



void  kthLargestUtil(Node *root, int k, int &c)
{
	if (root==NULL || c> k)
	{
		return ;
	}
	kthLargestUtil(root->right, k ,c);
	c++;
	if (c==k)
	{
		 cout << "K'th largest element is " << root->key << endl;
        return;
	}

	kthLargestUtil(root->left , k ,c);
}
void kthLargest(Node *root , int k)
{
	int c = 0;
 kthLargestUtil(root, k, c);
}

int main() {

	   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
	  Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    int c = 0;
    for (int k=1; k<=7; k++)
        kthLargest(root, k);
 


	system("pause");
	return 0;
}







