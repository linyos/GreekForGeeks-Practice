#include <iostream>
#include <vector>
#include <map>
#include<list>
#include<queue>
#include<set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>


using namespace std;



int lcs(char *x , char *y ,int m , int n)
{
	if (m==0 || n ==0 )
	{
		return 0;
	}
	if (x[m-1] == y[n-1])
	{
		return 1+ lcs(x, y,m-1,n-1);
	}
	else
	{
		return max(lcs(x,y,m,n-1) , lcs(x,y,m-1,n));
	}
}

int lcsDp(char * X , char * Y , int m , int n ,vector<vector<int>> &dp )
{
	


	if (m==0 || n==0)
	{
		return 0;
	}

	if (X[m-1] ==Y[n-1])
	{
		return dp[m][n] = 1 + lcsDp(X ,Y ,m-1,n-1, dp);
	}
	if (dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	return dp[m][n] =max(lcsDp(X,Y ,m,n-1 , dp),lcsDp(X,Y,m-1,n,dp));

}





int main()
{{
	char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
      
    int m = strlen(X);
    int n = strlen(Y);

	 cout<<"Length of LCS is "<< lcs( X, Y, m, n )<<endl; ;


	// 二維vector 作為DP的陣列儲存位置          // -1: 初始值
	 vector<vector<int>> dp(m+1 , vector<int>(n+1,-1));


	 

	 cout << "Length of LCS is " << lcsDp(X, Y, m, n, dp)<<endl;


	 //for (int i = 0; i < dp.size(); i++)
	 //{
		// for (int j = 0; j < dp[i].size(); j++)
		// {
		//	 cout<<dp[i][j] <<"  ";
		// }
		// cout<<endl;
	 //}


	system("pause");
	return 0;
}