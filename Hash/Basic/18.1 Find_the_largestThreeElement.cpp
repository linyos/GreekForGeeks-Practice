#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>


using namespace std;




void print3largest(int arr[], int n)
{
	int first , second , third;

	if (n <3 )
	{
		cout << " Invalid Input ";
        return;
	}
	third = first = second = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (arr[i]> first)
		{
			third = second;
			second = first;
			first  = arr[i];
		}
		else if (arr[i] > second)
		{
			third =second;
			second =arr[i];
		}
		else if (arr[i]>third)
		{
			third=arr[i];
		}

	}

	 cout << "Three largest elements are "
        << first << " " << second << " "
        << third << endl;
}

int main ()
{	
	  int arr[] = { 12, 13, 1, 10, 34, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    print3largest(arr, n);
	 
	 system("pause");
	return 0 ;
}
