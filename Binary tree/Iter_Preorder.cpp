//#include <iostream>
//#include <vector>
//#include <set>
//#include <algorithm>
//#include <map>
//#include <unordered_set>
//#include <time.h>
//#include <string>
//#include <math.h>
//#include <vector>
//#include <queue>
//#include <stack>
//using namespace std;
//
//class node
//{
//public:
//	int data;
//	node * left, * right ;
//	node * next;
//
//
//
//	node():left(0),right(0),next(0),data(0){};
//	node(int d):left(0) ,right(0),next(0),data(d){};
//};
//
//void iterativePreorder(node* root){
//
//	if (root==NULL){
//		return ;
//	}
//
//	stack<node *> nodeStack;
//	nodeStack.push(root);
//
//	while (nodeStack.empty()==false){
//		node * thenode = nodeStack.top();
//		cout<< thenode->data <<" ";
//		nodeStack.pop();
//
//		if (thenode->right){
//			nodeStack.push(thenode->right);
//		}
//		if (thenode->left){
//			nodeStack.push(thenode->left);
//		}
//	}
//}
//
//int main(){
//
//	node * root = new node(10);
//	root->left = new node(8);
//	root->right= new node(2);
//	root->left->left = new node(3);
//	root ->left->right = new node(5);
//	root->right->left= new node(2);
//	iterativePreorder(root);
//
//
//	system("pause");
//	return 0 ;
//	
//}