#include <iostream>
#include <queue>

using namespace std;


class node
{
public:
	int data;
	node * left ;
	node * right;
};


class ListNode 
{
public:
	int data;
	ListNode * next;
};



void push (ListNode ** head_ref , int data){
	ListNode * root = new ListNode;
	root->data = data;

	root->next = (*head_ref);

	(*head_ref) = root;

}



node * newNode (int data){
	node * temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right= NULL;
	return temp;
}



void convertList2Binary(ListNode * head , node * &root){
	queue<node *> q;

	if (head==NULL)
	{
		root=NULL;
		return ;
	}

	root = newNode(head->data);
	q.push(root);

	head=head->next;
	while (head)
	{
		node * parent = q.front();
		q.pop();

		node * leftChild = NULL  , * rightChild =NULL;
		leftChild = newNode(head->data);
		q.push(leftChild);
		head= head->next;
		if (head)
		{
			rightChild= newNode(head->data);
			q.push(rightChild);
			head= head->next;
		}
		parent->left= leftChild;
		parent->right= rightChild;
	}
}



void inorderTraversal(node * root ){
	if (root)
	{
		inorderTraversal(root->left);
		cout<<root->data <<" " ;
		inorderTraversal(root->right);
	}
}


int main(){
	ListNode * head= NULL;
	  push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */



	node * root = new node();
	convertList2Binary(head , root);


	cout<< "Inorder Traversal of the constructed Binary Tree is: \n";
	inorderTraversal(root);


	system("pause");
	return 0;
}