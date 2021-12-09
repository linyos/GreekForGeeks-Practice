#include <iostream>
#include <algorithm>


using namespace std ;


#define R 4
#define C 4

//A simple method
//int rowWithMax1s (bool mat[R][C]){
//	int rowIndex =-1;
//	int maxCount =0 ;
//
//	for (int i = 0; i < R; i++)
//	{
//		int count = 0 ;
//		for (int j = 0; j < C; j++)
//		{
//			if (mat[i][j]==1)
//			{
//				count ++ ;
//			}
//		}
//		if (count > maxCount)
//		{
//			maxCount = count;
//			rowIndex = i ;
//		}
//	}
//
//	return rowIndex ;
//
//}


//use Binary Search 
int first (bool arr[] , int low , int high){
	if (high  >= low)
	{
		int mid = low + (high - low )/2;

		if ((mid==0 || arr[mid]-1==0 ) && arr[mid]==1)
		{
			return mid;
		}
		else if (arr[mid]==0)
		{
			return first(arr , (mid+1) , high);
		}
		else
		{
			return first (arr, low ,(mid -1));
		}
	}
	return -1;
}




int rowWithMax1s(bool mat[R][C]){
	  int max_row_index = 0, max = -1;

	  int i  , index ;
	  for (int i = 0; i < R; i++)
	  {
		  index = first(mat[i] , 0 , C-1);
		  if (index != -1 && C -index > max)
		  {
			  max =C-index;
			  max_row_index = i;
		  }
	  }
	   return max_row_index;
}

int main ()
{
	 bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
 
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
	system("pause");
	return 0 ;
}