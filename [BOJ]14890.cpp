#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 101

int  n, l;
int arr[MAXN][MAXN];

int check_row[MAXN][MAXN] = { 0, };
int check_col[MAXN][MAXN] = { 0, };

int ret=0;

inline bool move(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j < n;
}

int row_check(int i, int j)
{
	int tmp = arr[i][j];
	for (int k = 0; k < l; k++)
	{
		if (!move(i+k,j)||check_row[i + k][j] || tmp != arr[i + k][j])
			return 0;
	}

	for (int k = 0; k < l; k++)
	{
		check_row[i + k][j] = 1;
	}
	return 1;
}

int move_row(int x)
{
	int tmp;
	for (int i = 0; i < n-1; i++)
	{
		tmp = arr[i+1][x] - arr[i][x];
		if (abs(tmp) > 1)
			return 0;
		if (tmp == 1)
		{
			if (!row_check(i + 1 - l, x))
				return 0;
		}
		else if (tmp == -1)
		{
			if (!row_check(i + 1, x))
				return 0;
			i += (l-1);
		}
	}

	return 1;
}

int col_check(int i, int j)
{
	int tmp = arr[i][j];
	for (int k = 0; k < l; k++)
	{
		if (!move(i, j+k)|| check_col[i][j+k] || tmp != arr[i][j+k])
			return 0;
	}

	for (int k = 0; k < l; k++)
	{
		check_col[i][j+k] = 1;
	}
	return 1;
}
int move_col(int y)
{
	int tmp;
	for (int i = 0; i < n-1; i++)
	{
		tmp = arr[y][i+1] - arr[y][i];
		if (abs(tmp) > 1)
			return 0;
		if (tmp == 1)
		{
			if (!col_check(y,i + 1 - l))
				return 0;
		}
		else if (tmp == -1)
		{
			if (!col_check(y,i + 1))
				return 0;
			i += (l - 1);
		}
	}

	return 1;
}

int main()
{
	cin >> n >> l;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
	{
		ret += move_row(i);
		ret += move_col(i);
	}

	cout << ret;

}