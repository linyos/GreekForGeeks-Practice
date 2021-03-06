#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;



void printClosest(int ar1[], int ar2[], int m, int n, int x)
{

	int diff = INT_MAX;

	int res_l,res_r;

	int l = 0 , r = n-1;
	while (l<m && r >= 0 )
	{
		// If this pair is cloesr to x than the previously
		// found closest, then update res_l , res_r and diff
		if (abs(ar1[l] + ar2[r]-x) < diff)
		{
			res_l = l;
			res_r = r;
			diff = abs(ar1[l] + ar2[r] -x);
		}


		if (ar1[l] + ar2[r] > x)
		{
			r--;
		}
		else
		{
			l++;
		}

	}
	  // Print the result
    cout << "The closest pair is [" << ar1[res_l] << ", "
         << ar2[res_r] << "] \n";

}


int main()
{  

	 int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 38;
    printClosest(ar1, ar2, m, n, x);

	system("pause");
	return 0;
}