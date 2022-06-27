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

// Print all members of ar[] that have given
void findNumbers(vector<int> &ar, int sum, vector<vector<int>> & res, vector<int> &out, int i)
{
	if (sum ==0 )
	{
		res.push_back(out);
		return;
	}
	while (i < ar.size() && sum-ar[i] >= 0 )
	{
		// every element in the array starting from i which can contribute to the sum 
		out.push_back(ar[i]); 
		// recursive call for next numbers (先把相同數字的情況找完)
		findNumbers(ar, sum - ar[i], res, out, i);
		
		i++;

		// Remove number from list (backtracking)
		out.pop_back();
	}
}



// Returns all combinations
// of ar[] that have given
// sum.

vector<vector<int>>  combinationSum(vector<int>& ar, int sum)
{
	sort(ar.begin(), ar.end());

	// remove duplicate
	ar.erase(unique(ar.begin(), ar.end()), ar.end());

	vector<int> r;
	vector<vector<int>> res;
	
	findNumbers(ar, sum, res, r, 0);

	return res;
}


int main()
{

	vector<int> ar;
	ar.push_back(2);
	ar.push_back(4);
	ar.push_back(6);
	ar.push_back(8);
	int n = ar.size();
	int sum = 8;


	vector<vector<int>> res = combinationSum(ar, sum);

	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) {
			cout << " ( ";
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << ")";
		}
	}

	system("pause");
	return 0;
}
