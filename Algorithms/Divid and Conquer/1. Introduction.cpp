#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;




// Function to find the maximum no. in a given array.
int DAC_Max(int arr[], int index, int l)
{	
	int max; 
	if (index>= l-2)
	{
		if (arr[index] > arr[l-1])
		{
			return arr[index];
		}
		else
		{
			return arr[index + 1];
		}
	}

	max = DAC_Max(arr, index + 1, l);

	if (arr[index] > max)
	{
		return arr[index];
	}
	else
	{
		return max;
	}
}


int  DAC_Min(int arr[], int index, int l)
{
	int min;
	if (index >= l-2)
	{
		if (arr[index]> arr[index-1])
		{
			return arr[index - 1];
		}
		else
		{
			return arr[index];
		}
	}
	min = DAC_Min(arr, index + 1, l);
	if (arr[index]> min)
	{
		return min;
	}
	else
	{
		return arr[index];
	}
	

}
int main() {

	int arr[] = { 120, 34, 54, 32, 58, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int max, min;
	max = DAC_Max(arr, 0, n);
	min = DAC_Min(arr, 0, n);
	cout << "Maximum: " << max << endl;
	cout << "Minimum: " << min << endl;



	system("pause");
	return 0;
}




