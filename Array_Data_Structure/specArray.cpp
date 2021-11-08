#include<iostream>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include<vector>
#include <math.h>
#include <algorithm>

using namespace std;

#define SIZE 5 


int main(){

	//int arr[] = {1, 2, 8, 10, 10, 12, 19};
 //   int n = sizeof(arr)/sizeof(arr[0]);
 //   int x = 3;
 //   int index = ceilSearch(arr, 0, n-1, x);
 //   if(index == -1)
 //       cout << "Ceiling of " << x << " doesn't exist in array ";
 //   else
 //       cout << "ceiling of " << x << " is " << arr[index];
    
	//蛇行:
	//int x , y ;
	//int array [SIZE][SIZE] = {0};
	//for (int i = 0; i < SIZE * SIZE ; i++)
	//{
	//	x = i /SIZE;	
	//	y = x%2== 0 ? i % SIZE : SIZE-1 - i%SIZE;
	//	array[x][y] = i+1; 
	//}

	//for (int i = 0; i < SIZE; i++)
	//{
	//	for (int j = 0; j < SIZE; j++)
	//	{
	//		cout<<array[i][j] <<" ";
	//	}
	//	cout<<endl;
	//}

	/* Output:
	1 2 3 4 5
	10 9 8 7 6
	11 12 13 14 15
	20 19 18 17 16
	21 22 23 24 25
	*/


	// 螺旋
	//走法偏移量: 右->下->左->上
	int dir_x [4]= {0 ,1,0,-1};
	int dir_y[4] = {1, 0, -1, 0};



	int index=0 ,x=0 ,y=-1 , temp_x , temp_y;

	int array [SIZE][SIZE] = {0};

	for (int i = 0; i < SIZE * SIZE; i++)
	{
		// 試走
		temp_x = x + dir_x[index];
		temp_y = y + dir_y[index];

		   if (temp_x < 0 || temp_x > SIZE-1 || temp_y< 0 || temp_y>SIZE-1|| array [temp_x][temp_y] != 0 )
		   {
			   index = (index+1) %4;
		   }
		   //cout<<index  <<endl;
		    // 下一個座標
		   x=x + dir_x[index]; 
		   y=y + dir_y[index];
			cout<<x <<" " <<y <<endl;
		   array[x][y] = i+1;
	}



	 for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }



	system("pause");
	return 0 ;
}
