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
#include <bitset>

using namespace std;


void printArr(vector<vector<int>> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << "(";
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << ")";
	}
}

void permute( vector<vector<int>> &res, vector<int> &nums  , int index   )
{
	if (index >= nums.size())
	{
		res.push_back(nums);
		return;
	}
	for (int i = index; i < nums.size(); i++)
	{
		swap(nums[index], nums[i]);
		permute(res, nums, index + 1);
		swap(nums[index], nums[i]);
	}
	
}

int main()
{

	//string  str= "ABC";

	vector<vector<int>> res; 
	vector<int>  nums = { 1,2,3 };
	int index = 0;

	permute(res , nums , index  );

	printArr(res);
	system("pause");
	return 0;
}
