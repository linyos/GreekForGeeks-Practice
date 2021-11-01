#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>
using namespace std;





struct ele{
	int count , index ,val ;
};

bool mycomp(ele a  , ele b){
	return (a.val < b.val);
}

bool mycomp2(ele  a , ele b){
	if (a.count != b.count){
		return (a.count < b.count);
	}
	else
	{
		return a.index > b.index;
	}
}

void sortByFrequency(int arr[] , int n){
	ele element[10];

	for (int i = 0; i < n; i++){
		 element[i].index = i;
		 element[i].count=0;
		 element[i].val = arr[i];
	}

	stable_sort(element , element+n , mycomp);

	element[0].count = 1;




}


int main (){


	system("pause");
	return 0;
}