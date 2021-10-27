#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;


class Node
{
public:
	int data;
	Node * right;
	Node * left;
	Node (): data(0) , right(0) , left(0){};
	Node (int value) : data(value) ,right(0) , left(0){};


	int compare (const void * a , const void * b);
	void printInorder(Node * node);
};







int Node::compare(const void * a , const void * b){
	return ( *(int*)a - *(int*)b) ;
}

void Node::printInorder(Node * node){
	if (node==NULL){
		return ;
	}
	printInorder(node ->left);
	cout<< node->data <<" ";
	printInorder(node->right);
}

int main() {


	system("pause");
	return 0;
}