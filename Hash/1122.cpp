#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

class Hash
{
	int Bucket;
	list<int> * table;
public:
	Hash(int V);

	void insertItem(int x);
	void deleteItem(int key);
	int hashFunction(int  x) {	
		return (x % Bucket);
	}
	void displayHash();
};


Hash::Hash(int b) {
	this->Bucket = b;
	table = new list <int>[Bucket];
}
void Hash::insertItem(int key) {
	int index = hashFunction(key);
	table[index].push_back(key);
}



void Hash::deleteItem(int key) {
	int index = hashFunction(key);
	list <int> ::iterator iter;
	for ( iter= table[index].begin() ; iter!= table[index].end(); iter++){
		if (*iter == key)
		{
			break;
		}
	}
	cout <<"iter: "<< *iter << endl;
	cout << index << endl;
	if (iter != table[index].end())
	{
		table[index].erase(iter);
	}
}

void Hash::displayHash() {
	for (int i = 0; i < Bucket; i++)
	{
		cout << i;
		for (auto x : table[i])
		{
			cout << " --> " << x;
		}
		cout << endl;
	}
}


int main()
{
	int a[] = { 15, 11, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);

	Hash h(7);

	for (int i = 0; i < n; i++)
	{
		h.insertItem(a[i]);
	}

	h.deleteItem(12);
	
	//h.displayHash();

	system("pause");
	return 0;
}