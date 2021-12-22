#include <iostream>
#include <string>
#include<algorithm>



using namespace std ;


#define MAX 26


void alternateSort(string &s){
	int n = s.length();


	int lCount[MAX] ={0} , uCount[MAX] ={0};

	for (int i = 0; i < n; i++){
		if (isupper (s[i]))
		{
			uCount[s[i]- 'A']++;
		}
		else
		{
			lCount[s[i]-'a']++;
		}
	}


	int i = 0 , j =0 , k =0 ;
	while (k < n)
	{
		while (i < MAX && uCount[i]==0)
		{
			i++;
			if (i<MAX)
			{
				s[k++] ='A'+i;
				uCount[i]--;
			}
		}
		while (j <MAX && lCount[j]==0)
		{
			j++;
			if (j<MAX)
			{
				s[k++]='a'+j;
				lCount[j]--;
			}
		}
	}
	
}





int main(){

	

	   string str = "bAwutndekWEdkd";
    alternateSort(str);
    cout << str << "\n";
	system("pause");
	return 0;
}