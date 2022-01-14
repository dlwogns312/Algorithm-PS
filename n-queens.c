#include <stdio.h>
#include <stdlib.h>

int col[4];

int promising(int i)
{
	int k = 1;
	int flag = 1;
	while (k < i && flag)
	{
		if (col[i] == col[k] || abs(col[i] - col[k]) == (i - k))
			flag = 0;
		k += 1;
	}
	return flag;

}

void n_queens(int i)
{
	int n = sizeof(col) / sizeof(int);
	if (promising(i))
	{
		if (i == n)
		{
			for (int x = 1; x < n + 1; x++)
				printf("%d ", col[x]);
			printf("\n");
		}
		else
			for (int j = 1; j < n + 1; j++)
			{
				col[i + 1] = j;
				n_queens(i + 1);
			}
	}
}
int main()
{
	n_queens(0);

}