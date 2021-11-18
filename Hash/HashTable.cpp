#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <string>
#include <stack>
#include <list>

using namespace std;


struct Node
{
	int key ;
	string value;
	Node * next;

	  Node():key(0),value(""),next(0){};
    Node(int Key, string Value):key(Key),value(Value),next(0){};
	  Node(Node const &data):key(data.key),value(data.value),next(data.next){};
};


class HashChainNode
{
	private:
		int size ,count;
		Node ** table;
		
		int HashFunction (int key);
		void TableDoubling();
		void TableShrinking();
		void Rehashing(int size_orig);
	public:	
		HashChainNode(){};
		HashChainNode(int m) :size(m) , count(0){
			table= new Node *[size];               // allocate the first demension of table
			for (int i = 0; i < size; i++)        // initialization
			{
				table[i]=0;                     // ensure 
			}
		}

		~HashChainNode();

		void Insert(Node data);
		void Delete(string key);
		string Search(string key);
		void DisplayTable();
};



void HashChainNode::Insert(Node data){
	count++;
	if (count> size){
		TableDoubling();   // if n/m > 1, then double the size of table
	}

	int index = HashFunction(data.key); // get index of slot
	Node * newNode = new Node (data);

	//push front
	if (table[index] == NULL){         
		table[index]=newNode;
	}
	else
	{
		Node * next = table[index]->next;
		table[index]->next=newNode;
		newNode->next=next;
	}



}









void HashChainNode::TableDoubling(){
	int size_orig = size;
	size * 2;
	Rehashing(size_orig);
}

void HashChainNode::TableShrinking(){
	int size_orig = size;
	size /=2 ;
	  Rehashing(size_orig);  
}


void HashChainNode::Rehashing(int size_orig){
	Node ** newtable = new Node *[size];
	for (int i = 0; i < size; i++){
		newtable[i]= 0;
	}




}

HashChainNode::~HashChainNode(){

	for (int i = 0; i < size; i++){
		Node * current = table[i];
		while (current != NULL){
			Node * previous = current;
			current = current->next;
			delete previous;
			previous =0;
		}
	}
	delete [] table;

}


void HashChainNode::DisplayTable(){

	for (int i = 0; i < size; i++){
		cout<<"#slot#" <<i <<" : ";
		Node * current = table[i];
		while (current != NULL){
			cout<<"(" << current->key << "," <<current->value<<")";
			current= current->next;
		}
		cout<<endl;
	}
	cout<<endl;

}

int main(){
	



	system("pause");
	return 0;
}



