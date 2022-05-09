#include <iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;







void displayMatrix(unsigned int const *p, unsigned int r, unsigned int c)
{
	unsigned int row, col;
	cout << endl;
	for ( row = 0 ; row  < r; row++)
	{
		for (col  = 0;  col< c; col++)
		{
			cout << *(p + row * c + col) << " ";
		}
		cout << endl;
	}
	cout << endl;
}




void rotate(unsigned int *pS, unsigned int *pD, 
	unsigned int r, unsigned int c)
{
	unsigned int row, col;

	for ( row = 0; row < r; row++)
	{
		for ( col = 0; col < c; col++)
		{
			cout << col << " " << col * r + (r - row - 1) << endl;
			*(pD + col * r+ (r-row-1)) = *(pS + row * c + col);
		}
	}

}

int main() 
{


	unsigned int image[][4] = { {1, 2, 3, 4},
							{5, 6, 7, 8},
							{9, 10, 11, 12} };

	unsigned int * pSource;
	unsigned int *pDestination;
	unsigned int m, n;

	m = 3, n = 4, pSource = (unsigned int *)image;
	pDestination = (unsigned int *)malloc(sizeof(int) * m *n);

	displayMatrix(pSource, m, n);
	rotate(pSource, pDestination, m, n);

	displayMatrix(pDestination, n, m);
	free(pDestination);
	system("pause");
	return 0;
}


