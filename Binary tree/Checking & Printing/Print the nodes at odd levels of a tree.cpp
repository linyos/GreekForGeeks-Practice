#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include<queue>
using namespace std;

class Node
{
public:
	int data;
	Node * left , *right;
};

Node * newNode (int key){
	Node * temp = new Node();
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp ;
}


//Method 1 (Recursive)
//void printOddNodes (Node * root , bool isOdd =true){
//	if (root ==NULL)
//	{
//		return ;
//	}
//	if (isOdd)
//	{
//		cout<< root->data <<" ";
//	}
//
//	printOddNodes(root->left , !isOdd);
//	printOddNodes(root->right , ! isOdd);
//}


//Method 2 (Iterative)
void printOddNodes(Node *root){
	if (root==NULL)
	{
		return ;
	}
	queue < Node * > q;
	q.push (root );
	bool isOdd = true;

	while (1)
	{
		int nodeCount = q.size();
		if (nodeCount == 0 )
		{
			break;
		}
		while (nodeCount > 0)
		{
			Node * node = q.front();
			if (isOdd)
			{
				cout<< node->data <<" ";
			}
			q.pop();
			if (node->left != NULL)
			{
				q.push(node->left );
			}
			if (node->right !=NULL)
			{
				q.push(node->right);
			}
			nodeCount--;
		}
		isOdd = !isOdd;
	}

}






int main(){


	 Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printOddNodes(root);
 

	system("pause");
	return 0 ;
}