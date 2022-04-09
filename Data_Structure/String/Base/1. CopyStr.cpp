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



// Iterative : 
void myCopy(char s1[], char s2[])
{
	int i = 0;
	for ( i = 0; s1[i] != '\0' ; i++)
	{
		s2[i] = s1[i];
	}
	s2[i] = '\0';
}



void myCopy1(char s1[], char s2[], const  int & i)
{
	s2[i] = s1[i];
	if (s1[i]=='\0')
	{
		return;
	}
	myCopy1(s1, s2, i+1);
}
int main() {

	char s1[100] = "GEEKSFORGEEKS";
	char s2[100] = "";
	cout << "Befor: " << s2 << endl;
	//myCopy(s1, s2);
	const int index = 0;
	myCopy1(s1, s2 , index);
	cout << "Copy: " << s2 << endl;




	system("pause");
	return 0;
}




