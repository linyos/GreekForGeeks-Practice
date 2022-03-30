#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include<unordered_map>
#include <set>
#include <stack>
#include <string>

using namespace std;

class Hash
{
private:
	int bucket; // No. of buckets
	//Pointer to ab array containing bucket.
	list<int> * table;
public:
	// Constructor
	Hash(int V);
	// inserts a key into hash table
	void insertItem(int x);
	// deletes a key from hash table
	void deleteItem(int x);
	// hash function to map values to key
	int hashFunction(int x);

	void displayHash();
};



Hash::Hash(int x)
{
	this->bucket = x;
	table = new list<int>[bucket];
}



void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}


void Hash::deleteItem(int x)
{
	// get the hash index of key
	int index = hashFunction(x);
	// find the key in (index)th list
	list<int> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (*i==x)
		{
			break;
		}
	}
	// if key is found in hash table, remove it
	if (i != table[index].end())
	{
		table[index].erase(i);
	}

}

int Hash::hashFunction(int x)
{
	return (x % bucket);
}


void Hash::displayHash()
{
	for (int i = 0; i < bucket; i++)
	{
		cout << i;
		for (auto x : table[i])
		{
			cout << " --> " << x;
		}
		cout << endl;
	}
}
int main() {
	
	int a[] = { 15, 11, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);

	Hash h(7);
	for (int i = 0; i < n; i++)
		h.insertItem(a[i]);

	// delete 12 from hash table
	h.deleteItem(12);

	// display the Hash table
	h.displayHash();

	system("pause");
	return 0;
}




