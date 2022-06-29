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



long swapCount(string s)
{
	vector<int> pos;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]=='[')
		{
			pos.push_back(i);
		}
	}
	
	int count = 0; // To count number of encountered '['
	int p = 0;  // to track position of next '[' in pos
	long sum = 0; // To store result

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]=='[')
		{
			++count;
			++p;
		}
		else if (s[i]==']')
		{
			--count;
		}

		if (count < 0 )
		{
			sum += pos[p] - i;
			swap(s[i], s[pos[p]]);
			++p;
			count = 1;
		}
	}
	return sum;
}




// Method 2 

long swapCount2(string s)
{
	
	int countLeft = 0, countRight = 0;

	int swap = 0, imbalance = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]=='[')
		{
			countLeft++;
			if (imbalance > 0 )
			{
				// swap count is last swap count + total number imbalance brackets
				swap += imbalance;
				
				imbalance--;
			}
		}
		
		else if (s[i] == ']')
		{
			// Increment count of Right bracket
			countRight++;

			cout << "countLeft: " << countLeft << " countRight " <<  countRight << endl;
			imbalance = (countRight - countLeft);
		}


		cout << imbalance << endl;
		


	}

	return swap;
}


int main()
{


	string s = "[]][][";
	cout << swapCount2(s) << "\n";

	
	system("pause");
	return 0;
}
