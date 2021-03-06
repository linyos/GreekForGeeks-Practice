#include <iostream>
#include<queue>
#include<algorithm>
#include <map>
#include<list>
#include <vector>
#include<unordered_map>
#include <set>

using namespace std;


void findCommon(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
	int i = 0, j = 0, k = 0;
	while (i < n1 && j <n2  && k <n3)
	{
		if (arr1[i]==arr2[j] && arr2[j]==arr3[k])
		{
			cout << arr1[i] << " ";
			i++;
			j++;
			k++;
		}
		else if (arr1[i] < arr2[j])
		{
			i++;
		}
		else if (arr2[j] < arr3[k])
		{
			j++;
		}
		else
		{
			k++;
		}
	}

}



void findCommon1(int ar1[], int ar2[], int ar3[], int n1, int n2 , int n3)
{
	int i = 0, j = 0, k = 0;

	int prev1, prev2, prev3;
	prev1 = prev2 = prev3 = INT_MIN;

	while (i < n1 && j < n2 && k < n3)
	{
		// 判斷是否與上一個值一樣
		while (ar1[i]==prev1 && i< n1)
			i++;
		while (ar2[j] == prev2 && j < n2)
			j++;
		while (ar3[k] == prev3 && k < n3)
			k++;


		if (ar1[i]==ar2[j] && ar2[j]==ar3[k])
		{
			cout << ar1[i] << " ";
			prev1 = ar1[i];
			prev2 = ar2[j];
			prev3 = ar3[k];
			i++;
			j++;
			k++;
		}
		else if (ar1[i] <ar2[j])
		{
			prev1 = ar1[i];
			i++;
		}
		else if (ar2[j] < ar3[k]) {
			prev2 = ar2[j];
			j++;
		}
		else {
			prev3 = ar3[k];
			k++;
		}
	}

}


void findCommonSet (int a[] ,int b[] ,int c[] , int n1 , int n2 ,int n3)
{
	// three sets to maintain frequency of elements
	unordered_set <int> uset1 , uset2 , uset3;
	for (int i = 0; i < n1; i++)
	{
		uset1.insert(a[i]);
	}
	for (int i = 0; i < n2; i++)
	{
		uset2.insert(b[i]);
	}

	// Checking if element of 3rd array are present in first 2 set
	
	for (int i = 0; i < n3; i++)
	{
		if (uset1.find(c[i]) != uset1.end() && uset2.find(c[i]) != uset2.end())
		{
			if (uset3.find(c[i])==uset3.end())
			{
				cout << c[i] <<" ";
			}
			uset3.insert(c[i]);
		}
	}
}





bool binary_search(int arr[] , int n , int element)
{
	int l = 0  , r = n-1;
	while (l < r)
	{
		int mid = l + (r-l)/2;
		if (arr[mid]==element)
		{
			return true;
		}
		else if (arr[mid] > element)
		{
			r = mid-1;
		}
		else
		{
			l = mid+1;
		}
	}
	return false;
}



void findCommonBS(int a[], int b[], int c[], int n1, int n2,int n3)
{
	for (int j = 0; j < n1; j++)
	{
		if (j != 0 && a[j] == a[j-1])
		{
			continue;
		}

		if (binary_search(b ,n2 ,a[j]) && binary_search(c , n3 , a[j]) )
		{
			cout<<a[j] <<" " ;
		}
	}
}

int main() {

	int ar1[] = { 1, 5, 10, 20, 40, 80 };
	int ar2[] = { 6, 7, 20, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	cout << "Common Elements are ";
	findCommon(ar1, ar2, ar3, n1, n2, n3);

	system("pause");
	return 0;
}




