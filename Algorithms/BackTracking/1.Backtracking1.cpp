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
string Ans; // �L�{���O�s���ץ�

bool choosed[100] = { 0 };  // choosed[i]==1��ܽs��i�w�g�X�{�L
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


int main() {

	str = "ABCD";
	backtracking(2);

	system("pause");
	return 0;
}




