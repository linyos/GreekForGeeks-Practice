#include <iostream>


using namespace std;

// Introduction
class Node
{
public:
	int data;
	Node * right;
	Node * left;
};


Node * CreateNode(int data) {
	Node * newNode = new Node();
	if (!newNode)
	{
		cout << "Memory error \n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}



Node * InsertNode(Node * root, int data)
{
	if (root ==NULL)
	{
		root = CreateNode(data);
		return root;
	}
	


}



void inorder(Node * root) {
	if (root ==NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);


}


int main() {



	system("pause");
	return 0;
}




