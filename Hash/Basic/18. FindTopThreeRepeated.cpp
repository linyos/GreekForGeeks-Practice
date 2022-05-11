#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>


using namespace std;


void top3Repeated(int arr[], int n)
{
	if (n< 3)
	{
		  cout << "Invalid Input";
        return;
	}

	unordered_map < int , int >fre ;
	/*
		unordered_map  : first : 计 , second : 瞷计
	*/


	for (int i = 0; i < n; i++)
	{
		fre[arr[i]] ++ ;
	}

	/*
		Pair <int, int > : first :Ω计 , second  : 计
	*/
	
	pair<int , int > x ,y, z;

	 x.first = y.first = z.first = INT_MIN;


	 for (auto curr: fre)
	 {
		 if (curr.second > x.first)
		 {
			 z = y;
			 y =x;

			 x.first= curr.second;
			 x.second =curr.first;
		 }
		 else if (curr.second >y.first)
		 {
			 z = y ;
			 y.first= curr.second;
			 y.second = curr.first;
		 }
		 else if (curr.second > z.first)
		 {
			 z.first =curr.second;
			 z.second = curr.first;
		 }
	 }


	 cout<< "Three largest elements are " << x.second << " " << y.second << " " << z.second ; 

}

int main ()
{	
	  int arr[] = { 3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
   top3Repeated(arr, n);
	 
	 system("pause");
	return 0 ;
}
