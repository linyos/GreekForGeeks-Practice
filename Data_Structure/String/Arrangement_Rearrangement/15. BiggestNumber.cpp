#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>

using namespace std;

int myCompare(string x, string y)
{
	string XY = x.append(y);
	
	string YX = x.append(x);

	// Now see which of the tow formed number is greater
	return XY.compare(YX) > 0 ? 1 : 0;
}






void printLargest(vector<string> arr)
{
	sort(arr.begin(), arr.end(), myCompare);
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}
	cout << endl;
}
int main() {
	

	vector<string> arr;

	// output should be 6054854654
	arr.push_back("54");
	arr.push_back("546");
	arr.push_back("548");
	arr.push_back("60");
	printLargest(arr);


	system("pause");
	return 0;
}




