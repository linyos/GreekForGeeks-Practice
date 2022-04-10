#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

class Trie
{
public:
	// index is set when node is a leaf
	int index; 
	Trie * child[MAX_CHAR];

	Trie()
	{
		for (int i = 0; i < MAX_CHAR; i++)
		{
			child[i] = NULL;
		}
		index = -1;
	}
};



void insert(Trie * root, string str, int index)
{
	Trie * node = root;
	for (int i = 0; i < str.size(); i++)
	{
		// Taking ascii value to find index of child node.
		char ind = str[i] - 'a';
		// making new path if not already
		if (!node->child[ind])
		{
			node->child[ind] = new Trie();
		}
		// go to next node
		node = node->child[ind];
		cout << node->child[ind] << endl;
	}
	// Mark leaf (end of word) and store
	// index of word in arr[]

	
	node->index = index;
}





bool preorder(Trie * node, string str[])
{
	if (node==NULL)
	{
		return false;
	}

	for (int i = 0; i < MAX_CHAR; i++)
	{
		if (node->child[i] != NULL)
		{
			if (node->child[i]->index != -1)
			{
				cout    << str[node->child[i]->index] << " " ;
			}
			preorder(node->child[i], str);
		}
	}
}



void printSorted(string arr[], int n)
{
	Trie * root = new Trie();

	for (int i = 0; i < n; i++)
	{
		insert(root, arr[i], i);
	}
	preorder(root, arr);
}
int main() {
	
	string arr[] = { "abc", "xy", "bcd" };
	int n = sizeof(arr) / sizeof(arr[0]);
	printSorted(arr, n);
	


	//string str = "abc";
	//for (int i = 0; i < str.length(); i++)
	//{
	//	char c = str[i];
	//	cout << (int)c << " ";
	//}
	system("pause");
	return 0;
}




