#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;



// Method 1 : simple
void printMaxActivities(int s[], int f[], int n)
{
	int i, j;
	cout << "Following activities are selected " << endl;

	i = 0;
	cout << " " << i;
	for ( j	 = 1; j < n; j++)
	{
		if (s[j] >= f[i])
		{
			cout << " " << j;
			i = j;
		}
	}


}




// Method 2: activites sorted

struct Activitiy
{
	int start, finish;
};

bool activityCompare(Activitiy s1, Activitiy s2)
{
	return (s1.finish < s2.finish);
}


void printMaxActivities2(Activitiy arr[], int n)
{
	sort(arr, arr + n, activityCompare);
	cout << "Following activities are selected n";

	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

	for  (int j = 1; j < n ; j++)
	{
		if (arr[j].start >= arr[i].finish)
		{
			cout << "(" << arr[j].start << ", "
				<< arr[j].finish << "), ";
			i = j;
		}
	}
}

int main() 
{

	/*int s[] = { 1, 3, 0, 5, 8, 5 };
	int f[] = { 2, 4, 6, 7, 9, 9 };
	int n = sizeof(s) / sizeof(s[0]);
	printMaxActivities(s, f, n);
*/


	Activitiy arr[] = { {5, 9}, {1, 2}, {3, 4}, {0, 6},
									 {5, 7}, {8, 9} };
	int n = sizeof(arr) / sizeof(arr[0]);
	printMaxActivities2(arr, n);
	
	system("pause"); 
	return 0;
}




