#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


// Method 1 : simple linear 
//bool areDisjoint(int set1 []  , int set2[] , int m , int n ){
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (set1[i]==set2[j])
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}

// Method 2 : (Use Sorting and Merging)
//bool areDisjoint(int set1[] , int set2[] , int m , int n ){
//
//	sort(set1 , set1+m);
//	sort(set2, set2+n);
//
//	int i = 0 , j =0 ;
//	while (i < m  && j < n ){
//		if (set1[i] < set2[j])
//		{
//			i++;
//		}
//		else if( set2[j] < set1[i])
//		{
//			j++;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	return true;
//}




// Method Hash (Use Hashing)
bool areDisjoint(int set1[] , int set2[] , int  n1, int n2 ){
	set<int > myset; 

	for (int i = 0; i < n1; i++)
	{
		myset.insert(set1[i]);
	}

	for (int i = 0; i < n2; i++)
	{
		if (myset.find(set2[i]) != myset.end())
		{
			return false;
		}
	}
	return true;
}

int main(){
	int set1[] = {12,34,11,9,3};
	int set2[] = {7,2,1,5};
	int m = sizeof(set1)/sizeof(set1[0]);
	int n = sizeof(set2)/sizeof(set2[0]);
	areDisjoint(set1 , set2 , m , n ) ? cout<< "Yes" : cout<< "No";

	system("pause");
	return 0;
}