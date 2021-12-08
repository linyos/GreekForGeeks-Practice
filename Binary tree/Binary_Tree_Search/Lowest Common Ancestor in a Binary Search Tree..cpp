#include <iostream>


using namespace std;



class Node
{
public:
	int data;
	Node * left , *right;
};

Node * newNode(int data){
	Node * temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Node * lca (Node * root , int n1 , int n2){
	while (root != NULL)
	{
		if (root->data > n1 && root->data > n2)
		{
			root = root->left;
		}
		else if (root ->data < n1 && root->data < n2)
		{
			root = root->right;
		}
		else{
			break;
		}
	}
	return root ;
}


int main(){
	 Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
	int n1 = 10, n2 = 14;

	Node *t = lca(root , n1 ,n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl;

	n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;


	system("pause");
	return 0;
}