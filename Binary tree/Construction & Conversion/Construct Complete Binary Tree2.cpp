#include <iostream>
#include <queue>

using namespace std;




class  Node
{
public:
	int data;
	Node * left , * right;
};



Node * newNode(int data){
	Node * node = new Node();
	node->data = data;
	node->left= node->right = NULL;
	return node ;
}


Node * insertLevelOrder(int arr [] , Node * root , int i , int n ){

 if (i < n)
    {
        Node* temp = newNode(arr[i]);
        root = temp;
 
        // insert left child
        root->left = insertLevelOrder(arr,
                   root->left, 2 * i + 1, n);
 
        // insert right child
        root->right = insertLevelOrder(arr,
                  root->right, 2 * i + 2, n);
    }
    return root;
}


void inorderNode (Node * root){

	if (root != NULL)
	{
		inorderNode(root->left);
		cout<< root->data <<" ";
		inorderNode(root->right);
	}
}

int main(){
	 int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);

 	Node * root =insertLevelOrder(arr, root , 0 , n);

	inorderNode(root);




	system("pause");
	return 0;
}