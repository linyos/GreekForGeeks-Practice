#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


const int Size = 26;

class TrieNode
{
public:
	bool isEndOfWord;
	TrieNode * child[Size];
};

// Returns new trie node (initialized to NULLs)
TrieNode * getNode(void)
{
	TrieNode * pNode = new TrieNode();
	pNode->isEndOfWord = false;
	
	for (int i = 0; i <Size; i++)
	{
		pNode->child[i] = NULL;
	}
	return pNode;
}



void insert(TrieNode * root, string key)
{
	TrieNode * pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->child[index])
		{
			pCrawl->child[index] = getNode();
		}
		pCrawl = pCrawl->child[index];
	}
	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}




bool search(TrieNode * root, string key)
{
	TrieNode * pCrawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->child[index])
		{
			return false;
		}
		pCrawl = pCrawl->child[index];
	}
	return pCrawl->isEndOfWord;
}

int main() {
	string keys[] = { "the", "a", "there",
				   "answer", "any", "by",
					"bye", "their" };
	int n = sizeof(keys) / sizeof(keys[0]);

	TrieNode * root = getNode();

	for (int i = 0; i < n; i++)
	{
		insert(root, keys[i]);
	}

	search(root, "the") ? cout << "Yes\n" :
		cout << "No\n";
	search(root, "these") ? cout << "Yes\n" :
		cout << "No\n";
	search(root, "their") ? cout << "Yes\n" :
		cout << "No\n";
	search(root, "thaw") ? cout << "Yes\n" :
		cout << "No\n";
	


	system("pause");
	return 0;
}




