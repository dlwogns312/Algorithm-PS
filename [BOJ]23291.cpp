#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>
using namespace std;

int tower[100][100] = { 0, };
int n, k;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
void setup()
{
	int lx=1, ly=1;
	int  sx=0;
	int min = tower[0][0];
	
	for (int i = 1; i < n; i++)
		if (min >tower[0][i])
			min = tower[0][i];
	for (int i = 0; i < n; i++)
		if (min == tower[0][i])
			tower[0][i]++;
	
	while (ly <= n - sx - lx)
	{
		for (int y = 0; y < ly; y++)
		{
			for (int x = 0; x < lx; x++)
			{
				tower[lx - x][sx+lx+y] = tower[y][x + sx];
				tower[y][x + sx] = 0;
			}
		}
		
		sx += lx;
		if (lx == ly)
			ly++;
		else
			lx++;
	}
}
void divide()
{
	int t_scan[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t_scan[i][j] = tower[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!t_scan[i][j])
				continue;
			for (int x = 0; x < 4; x++)
			{
				int nx = i + dx[x];
				int ny = j + dy[x];

				if (!t_scan[i][j])
					continue;
				int give = t_scan[nx][ny] - t_scan[i][j];
				if (give >= 5)
				{
					give /= 5;
					tower[nx][ny] -= give;
					tower[i][j] += give;
				}
			}
		}
	}

	int arrange = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!tower[j][i])
				continue;
			if (0 == j && arrange == i)
			{
				arrange++;
				continue;
			}
			tower[0][arrange++] = tower[j][i];
			tower[j][i] = 0;
		}
	}
}

void half_setup()
{
	for (int x = 0; x < n / 2; x++)
	{
		tower[1][n - x - 1] = tower[0][x];
		tower[0][x] = 0;
	}

	for (int y = 0; y < 2; y++)
	{
		for (int x = n / 2; x < n * 3 / 4; x++)
		{
			tower[3 - y][n - 1 + n / 2 - x] = tower[y][x];
			tower[y][x] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int count = 0, diff=9999;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> tower[0][i];
	

	while (1)
	{
		setup();
		divide();


		half_setup();
		divide();

		int max = tower[0][0];
		int min = tower[0][n - 1];
		for (int i = 0; i < n; i++)
		{
			if (max < tower[0][i])
				max = tower[0][i];
			if (min > tower[0][i])
				min = tower[0][i];
		}
		diff = max - min;

		count++;

		if (diff <= k)
			break;
	}

	printf("%d\n", count);

}