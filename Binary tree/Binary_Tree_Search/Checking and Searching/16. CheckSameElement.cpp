#include <iostream>
#include<unordered_set>

using namespace std;


class Node
{
public:
	int data;
	Node * left , *right;
};

Node * newNode(int data)
{
	Node * node = new Node;
	node->data =data;
	node->left= node->right =NULL;
	return node;
}

void insertToHash(Node * root , unordered_set<int> &s)
{
	if (!root)  return ;
	
	insertToHash(root->left , s);
	s.insert(root->data);
	insertToHash(root->right , s);
}

bool checkBSTs(Node* root1, Node* root2)
{
	if (!root1 && !root2)
	{
		return true;
	}
	if ((root1 &&!root2) || (!root1 && root2) )
	{
		return false;
	}
	unordered_set<int> s1 ,s2;
	insertToHash(root1 ,s1);
	insertToHash(root2,s2);
	return (s1==s2);
}





int  main() {
	  Node* root1 = newNode(15);
    root1->left = newNode(10);
    root1->right = newNode(20);
    root1->left->left = newNode(5);
    root1->left->right = newNode(12);
    root1->right->right = newNode(25);
     
    // Second BST
    Node* root2 = newNode(15);
    root2->left = newNode(12);
    root2->right = newNode(20);
    root2->left->left = newNode(5);
    root2->left->left->right = newNode(10);
    root2->right->right = newNode(25);
     
    // check if two BSTs have same set of elements
    if (checkBSTs(root1, root2))
        cout << "YES";
    else
        cout << "NO";



	system("pause");
	return 0;
}



