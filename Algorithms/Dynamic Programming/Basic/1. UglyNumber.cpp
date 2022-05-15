#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>

using namespace std;

//Method 1 (Simple)  
int maxDivide(int a, int b)
{
	while (a % b ==0)
	{
		a = a / b;
	}
	return a; 
}
int isUgly(int no)
{
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);

	return (no == 1) ? 1 : 0;
}
int getNthUglyNo(int n)
{
	int i = 1; 
	int count = 1;
	while (n > count)
	{
		i++;
		if (isUgly(i))
		{
			count++;
		}
	}
	return  i;
}

unsigned getNthUglyNo1(unsigned n)
{
	unsigned ugly[150];
	unsigned i2 = 0, i3 = 0, i5 = 0;
	unsigned next_multiple_of_2 = 2;
	unsigned next_multiple_of_3 = 3;
	unsigned next_multiple_of_5 = 5;
	unsigned next_ugly_no = 1;

	ugly[0] = 1;
	for (int i = 1; i < n; i++)
	{
		next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
		ugly[i] = next_ugly_no;
		
		if (next_ugly_no==next_multiple_of_2)
		{
			i2 = i2 + 1;
			next_multiple_of_2 = ugly[i2] * 2;
		}
		if (next_ugly_no == next_multiple_of_3)
		{
			i3 = i3 + 1;
			next_multiple_of_3 = ugly[i3] * 3;
		}
		if (next_ugly_no == next_multiple_of_5)
		{
			i5 = i5 + 1;
			next_multiple_of_5 = ugly[i5] * 5;
		}
	}
	return next_ugly_no;
}




int main() 
{


	//unsigned no = getNthUglyNo(150);
	//cout << "150th ugly no. is " << no << endl;




	unsigned num = getNthUglyNo1(10);

	
	cout << "150th ugly no. is " << num << endl;
	system("pause");
	return 0;
}


