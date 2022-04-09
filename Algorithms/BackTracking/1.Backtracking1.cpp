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

string str;
string Ans; // 過程中保存答案用

bool choosed[100] = { 0 };  // choosed[i]==1表示編號i已經出現過
void backtracking(const int &N)
{
	if (Ans.size()==N)
	{
		cout << Ans << endl;
		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		
		if (choosed[i] ==0 )
		{

			cout << ":: " << i<<" "<< str[i];
			Ans.push_back(str[i]);
			choosed[i] = 1;

			backtracking(N);
			
			Ans.pop_back();
			choosed[i] = 0;
		}
	}

}



/ Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string a, int l, int r)
{
	if (l == r)
	{
		cout << "Ans: " << a << endl;
	}
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{
			// swapping 
			swap(a[l], a[i]);
			// Recursion called
			permute(a, l + 1, r);
			//backtrack
			swap(a[l], a[i]);
		}
	}
}

int main() {

	str = "ABCD";
	backtracking(2);



	string str1 = "ABC";
	int n = str1.size();
	permute(str1, 0, n - 1);



	system("pause");
	return 0;
}




