#include <iostream>

using namespace std;
#define MAX 10 

static int St_Size = 0;

struct stack{
	int item[MAX];
	int top;
};

typedef struct stack st;

void createEmptyStack(st * s) {
	s->top = -1;
}

int isFull(st * s) {
	if (s->top==MAX-1){
		return 1;
	}
	else
	{
		return 0;
	}
}


int isEmpty(st * s) {
	if (s->top==NULL){
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(st * s, int NewItem) {
	if (isFull(s)){
		cout << "Stcak FULL" << endl;
	}
	else{
		s->top++;
		s->item[s->top] = NewItem;
	}
	St_Size++;

}

void pop(st*s) {
	if (isEmpty(s)){
		cout << "Stack Empty" << endl;
	}
	else{
		cout << "Item Popped = " << s->item[s->top];
		s->top--;
	}
	St_Size--;
	cout << endl;

}


void printStack(st * s) {
	cout << "Stack: ";
	for (int i = 0; i < St_Size; i++){
		cout << s->item[i] << " ";
	}
	cout << endl;
}

int main() {
	int ch;
	st * s = new st();
	createEmptyStack(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);

	printStack(s);

	pop(s);
	printStack(s);



	system("pause");
	return 0;
}