#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include<queue>
#include <set> 
#include <iomanip>
using namespace std;

class Node
{
public:
	int key;
	Node * left , * right;
};


Node * newNode(int key){
	Node * temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}


int findLargestSubtreeSumUtil(Node * root , int & ans){

	if (root ==NULL)
	{
		return 0 ;
	}

	int currSum = root->key + findLargestSubtreeSumUtil(root->left , ans ) + findLargestSubtreeSumUtil(root->right , ans);
	cout<<"CurSum: " << currSum <<endl;

	ans = max(ans , currSum);
	return  currSum;
}


// To find largest subtree sum
int findLargestSubtreeSum (Node * root){
	if (root==NULL)
	{
		return 0 ;
	}

	int ans = INT_MIN;

	findLargestSubtreeSumUtil(root , ans);
	return ans;
}


int main (){

			/*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
	    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
	 cout << findLargestSubtreeSum(root);
	system("pause");
	return 0 ;
}