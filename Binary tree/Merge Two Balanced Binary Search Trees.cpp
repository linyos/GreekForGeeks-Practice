#include <iostream>
#include <string>

using namespace std;




class node
{
public:
	int data;
	node * left , *right;
};

int *merge(int arr1[], int arr2[], int m, int n);
void storeInorder (node * node , int inorder [] , int *index_ptr);
node * sortedArrayToBST (int arr[] , int start  , int end);



node *newNode (int data){
	node * temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp ;
}

void printInorder (node * node){
	if (node == NULL)
	{
		return; 
	}
	printInorder(node ->left);
	cout<< node ->data << " ";
	printInorder (node->right);
}





// This function merges two balanced Binary search three from a sorted array
node * mergeTrees (node * root1 , node * root2 , int m , int n ){
	//Store inorder traversal of frist tree in an array arr1[]
	int * arr1 = new int [m];
	int i = 0 ;
	storeInorder (root1 , arr1 , &i);

	// Store inorder traversal of second tree in another array arr2[]
	int * arr2 = new int [n];
	int j =0 ;
	storeInorder (root2 , arr2 , &j);

	int * mergedArr = merge(arr1 , arr2 , m , n);

	return sortedArrayToBST(mergedArr , 0 , m+n -1);


}


int * merge(int arr1[] , int arr2[] , int m , int n ){
	// mergedArr[] is going to contain result 
	int *mergedArr = new int [m+n];
	int i = 0 , j =0 , k =0 ;


	// Traversal through both arrays
	while (i < m && j < n )
	{
		if (arr1[i] < arr2[j])
		{
			mergedArr[k] = arr1[i];
			i++;
		}
		else
		{
			mergedArr[k]= arr2[j];
			j++;
		}
		 k++;
	}


	// If there are more elements in first array.
	while (i < m)
	{
		mergedArr[k] =arr1[i];
		i++ ;
		k++ ;
	}

	while (j<n)
	{
		mergedArr[k]= arr2[j];
		j++;
		k++;
	}
	return mergedArr;


}





//The Function that stores inorder traversal of a tree rooted with node
void storeInorder (node * node , int inorder[] , int *index_ptr){
	if (node == NULL)
	{
		return ;
	}

	// First recur on left child
	storeInorder (node->left , inorder , index_ptr);
	inorder[*index_ptr] = node->data;
	(*index_ptr) ++ ;
	storeInorder(node->right , inorder , index_ptr);
}


// The function that constructs Balanced Binary Search Tree from a sorted array
node * sortedArrayToBST(int arr[], int start, int end){

	if (start > end)
	{
		return NULL;
	}
	 // Get the middle elemen and make it root.
	int mid = start +(end- start)/2;
	node * root = newNode(arr[mid]);


	// Recursively construct the left subtree and make it left child of root
	root->left =sortedArrayToBST(arr, start , mid-1);

	root->right = sortedArrayToBST(arr , mid+1 , end);

	return root;
}



int main(){
	 /* Create following tree as first balanced BST
        100
        / \
      50 300
      / \
     20 70
    */
	node *root1 = newNode(100);
	 root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

	 /* Create following tree as second balanced BST
        80
        / \
        40 120
    */
	 node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);
 
    node *mergedTree = mergeTrees(root1, root2, 5, 3);
 
    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);
	system("pause");
	return 0 ;
}