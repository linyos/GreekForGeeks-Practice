#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;


class Node
{
public:
	int data;
	Node(int val) {
		data = val;
	}
	Node * ptr;
};


bool isPalin(Node * head)
{
	Node * slow = head;
	stack<int> s;

	// Push all elements of the list to the stack
	while (slow != NULL)
	{
		s.push(slow->data);
		slow = slow->ptr;
	}
	while (head != NULL)
	{
		// Get the top most element;
		int temp = s.top();
		// Pop the element;
		s.pop();
		// Check if data is not same as popped element
		if (head->data !=temp)
		{
			return false;
		}
		head = head->ptr;
	}
	return true;
}



int main() 
{
	Node one = Node(1);
	Node two = Node(2);
	Node three = Node(3);
	Node four = Node(2);
	Node five = Node(1);


	five.ptr = NULL;
	one.ptr = &two;
	two.ptr = &three;
	three.ptr = &four;
	four.ptr = &five;
	Node* temp = &one;


	int result = isPalin(&one);

	if (result == 1)
		cout << "isPalindrome is true\n";
	else
		cout << "isPalindrome is true\n";

	system("pause"); 
	return 0;
}




