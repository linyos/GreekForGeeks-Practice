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

using namespace std;





bool checkPair (int arr[] , int n  ,int x)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] + arr[j] == x)
			{
				cout << "Pair with a given sum "<< x << " is (" <<arr[i] << ", " <<arr[j] <<")" <<endl;
 				return 1;
			}
		}
	}
	return 0;
}




bool hasArrayTowCandidate (int arr[] , int n , int x )
{
	
	sort(arr , arr+ n );

	int l = 0 , r = n-1;
	while (l < r)
	{
		if (arr[l] + arr[r] == x)
		{
			cout << x <<endl;
			cout<<"( "<< arr[l] <<" , " << arr[r] <<" )"<<endl;
			return 1;
		}
		else if (arr[l] + arr[r] < x)
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	return 0 ; 

}




void printPair (int arr[] , int n , int x )
{
	unordered_set<int> s;
	for (int i = 0; i < n; i++)
	{
		int temp = x - arr[i];
		if (s.find(temp) != s.end())
		{
			cout <<"Pair with given sum " << x << " is ( " << arr[i] <<"," << temp <<")" <<endl;
		}
		 s.insert(arr[i]);
	}
}



//void printPairRem (int arr[] , int n , int x)
//{
//	int i;
//	// x= 16
//	int rem[16];
//
//	for (int i = 0; i < x; i++)
//	{
//		rem[i]= 0;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] < x )
//		{
//			rem[arr[i] % x]++;
//		}
//	}
//
//	// Traversing the remainder list from start to middle to find pairs
//
//	for (int i = 1; i <x/2 ; i++)
//	{
//		if (rem[i] > 0 && rem[x-i] > 0 )
//		{
//			cout<<"Yes\n";
//			break;
//		}
//	}
//
//
//}
//



pair <int , int > fundSum (int *arr , int &n , int & target)
{
	int i , findElement;
	unordered_map<int, int> mp;
	pair<int, int> result;
	for (int i = 0; i < n; i++)
	{
		findElement = target - arr[i];
		if (mp[findElement])
		{
			result.first = i-1;
			result.second = mp[findElement]-1;
			break;
		}
		else
		{
			mp.insert({arr[i],i});
		}
	}
	return result;
}





int main()
{
	int arr[] = {0, -1, 2, -3, 1};
	int x = -2;
	int n  = sizeof(arr) / sizeof(arr[0]);

	// Method 1 
	//if (checkPair(arr , n , x))
	//{
	//	 cout << "Valid pair exists" << endl;
	//}
	//else
	//{
	//		cout << "No valid pair exists for " << x << endl;
	//}

	// Method 2 
	//if (hasArrayTowCandidate(arr  , n ,x ))
	//{
	//	cout << "Array has two elements  with given sum";
	//}
 //   else{
 //       cout << "Array doesn't have two elements with given sum";
	//}

	// hash 
	//  printPair(arr, n,x);

	 int arr1[]={1,5,4,3,7,9,2};
    int n1=sizeof(arr)/sizeof(arr[0]);
    int search=7;


   /* pair<int,int>ans= fundSum (arr1,n1,search);

    cout<<min(ans.first,ans.second)<<" "<<max(ans.first,ans.second);
*/

	system("pause");
	return 0;
}