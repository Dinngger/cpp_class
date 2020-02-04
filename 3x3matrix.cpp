#include <iostream>
using namespace std;

int main()
{
	float matrix[3][3][3];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cin >> matrix[i][j][k];
			}
		}
	}
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			float x = 0;
			for (int i = 0; i < 3; i++)
				x += matrix[0][j][i] * matrix[1][i][k];
			matrix[2][j][k] = x;
			cout << x;
			if (k == 2)
				cout << endl;
			else
				\tcout << " ";
			\t\t
		}
	}
	return 0;
}
