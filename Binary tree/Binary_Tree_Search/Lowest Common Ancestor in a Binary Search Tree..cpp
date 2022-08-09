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


// method2 

Node * findLCA(Node * root, int n1, int n2)
{
	if (root == NULL)
		return NULL;

	if (root->key == n1 || root->key == n2)
		return root;
	// Look for keys in left and right subtrees
	Node * left = findLCA(root->left, n1, n2);
	Node * right = findLCA(root->right, n1, n2);

	// If both of the above calls return NULL,
	// then one key is presnet in once subtree and other is present in other,
	// So this node is the LCA
	if (left && right)
		return root;

	return left != NULL ? left : right;
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