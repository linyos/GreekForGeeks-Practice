#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>

using namespace std;




unsigned long int catalan(unsigned int n)
{
	if (n < 1 )
	{
		return 1;
	}
	unsigned long int res = 0 ;
	for (int i = 0; i < n; i++)
	{
		res += catalan(i) * catalan(n- i -1);
	}
	return res;
}



unsigned long int catalanDp (unsigned int n )
{
	unsigned long int catalan[11];

	catalan[0] = catalan[1] =1;

	for (int i = 2; i <= n; i++)
	{
		catalan[i] = 0 ;
		for (int j = 0; j < i; j++)
		{
			catalan[i] += catalan[j] * catalan[i-j-1];
		}
	}

	return catalan[n];
}

int main()
{
	cout << "\nRecursive:\n";
	 for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";


	 cout << "\nDP:\n";
	  for (int i = 0; i < 10; i++)
        cout <<  catalanDp(i) << " ";


	system("pause");
	return 0;
}