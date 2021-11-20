#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using	namespace std;


#define TABLE_SIZE  13 
#define PRIME 7


class DoubleHash
{
	int * hashTable;
	int curr_size;

public:
	bool isFull() {
		return (curr_size == TABLE_SIZE);
	}
	int hash1(int key) {
		return (key  % TABLE_SIZE);
	}
	int hash2(int key) {
		return (PRIME - (key % PRIME));
	}

	DoubleHash() {
		hashTable = new int[TABLE_SIZE];
		curr_size = 0;
		for (int i = 0; i < TABLE_SIZE; i++) {
			hashTable[i] = -1;
		}
	}


	void insertHash(int key) {
		if (isFull()) {
			return;
		}
		int index = hash1(key);

		if (hashTable[index] != -1)
		{
			// get index2 from second hash
			int index2 = hash2(key);
			int i = 1;
			while (1)
			{
				// get newIndex 

				int newIndex = (index + i * index2) % TABLE_SIZE;

				cout << "hashTable[newIndex]" << hashTable[newIndex] << endl;
				// if not collison
				if (hashTable[newIndex] == -1)
				{
					hashTable[newIndex] = key;
					break;
				}
				i++;
			}
		}
		else
		{
			hashTable[index] = key;
		}
		curr_size++;
	}

	void search(int key) {
		int index1 = hash1(key);
		int index2 = hash2(key);
		int i = 0;
		while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key)
		{
			// If collision hashing => i++;
			if (hashTable[(index1 + i * index2) % TABLE_SIZE == -1])
			{
				cout << key << " does not exist " << endl;
				return;
			}
			i++;
		}
		cout << key << " Found " << endl;
	}

	void displayHash() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (hashTable[i] != -1)
			{
				cout << i << "-->" << hashTable[i] << endl;
			}
			else
			{
				cout << i << endl;
			}
		}
	}



};


int main()
{
	int a[] = { 19 ,27,36,10,64 };

	int n = sizeof(a) / sizeof(a[0]);

	DoubleHash h;

	for (int i = 0; i < n; i++) {
		h.insertHash(a[i]);
	}

	h.search(36);
	h.search(100);

	h.displayHash();

	system("pause");
	return 0;
}