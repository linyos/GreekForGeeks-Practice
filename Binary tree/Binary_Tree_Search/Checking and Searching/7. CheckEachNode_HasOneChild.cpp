#include <iostream>
#include <queue>
using namespace std;


// Method 2
bool hasOnlyOneChild(int pre[] , int size)
{
	int nextDiff , lastDiff;

	for (int i = 0; i < size-1; i++)
	{
		

		nextDiff = pre[i] - pre[i+1];
		
		lastDiff = pre[i]-pre[size-1];


		cout<<  "nextDiff:  " <<nextDiff  <<"lastDiff:  " <<lastDiff  <<endl;
		if (nextDiff * lastDiff < 0)
		{
			return false;
		}
	}
	 return true;
}


// Method 3  
int hasOnlyOneChild2(int pre[] , int size)

{  // Initialize min and max using last two elements
	int min , max;
	if (pre[size-1] > pre[size-2])
	{
		max= pre[size-1];
		min = pre[size-2];
	}
	else
	{
		max = pre[size-2];
		min = pre[size-1];
	}
	//Every element must be either smaller than min or greater than max
	for (int i = size-3; i >=0 ; i--)
	{
		if (pre[i] < min)
		{
			min =pre[i];
		}
		else if (pre[i]>max)
		{
			max= pre[i];
		}
		else
		{
			return false;
		}
	}
	return true;

}

int main() {
	int pre[] = {8, 3, 5, 7, 6};
    int size = sizeof(pre)/sizeof(pre[0]);
    if (hasOnlyOneChild2(pre, size) == true )
        cout<<"Yes";
    else
        cout<<"No";
	system("pause");
	return 0;
}







