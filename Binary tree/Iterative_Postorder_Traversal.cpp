#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <time.h>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/// Using Two Stack


class node
{
public:
	int data;
	node * left, * right ;
	node * next;



	node():left(0),right(0),next(0),data(0){};
	node(int d):left(0) ,right(0),next(0),data(d){};
};

void postOrderIterative(node* root){
	if (root==NULL){
		return ;
	}
	// Create two stack
	stack<node *> s1 ,s2;
	// push root to first stack
	s1.push(root);
	node * Node ;


	// Run while first stack is not empty
	while (!s1.empty()){
		// Pop an item form s1 and push it to s2
		Node = s1.top();
		s1.pop();
		s2.push(Node);

		// push left and right children of removed item to s1
		if (Node->left){
			s1.push(Node->left);
		}
		if (Node->right){
			s1.push(Node->right);
		}
	}

	//Print all elements of scoend stack
	while (!s2.empty()){
		Node = s2.top();
		s2.pop();
		 cout << Node->data << " ";
	}
}

int main(){

	node * root = new node(1);
	root->left = new node(2);
	root->right= new node(3);
	root->left->left = new node(4);
	root ->left->right = new node(5);
	root->right->left= new node(6);
	root->right->right= new node(7);
	postOrderIterative(root);
	system("pause");
	return 0 ;
	
}