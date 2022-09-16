#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

//if column number is odd
int dx_odd[6] = { 0,-1,0,1,1,1 };
int dy_odd[6] = { -1,0,1,0,-1,1};
//if column number is even
int dx_even[6] = { 0,-1,0,1 ,-1,-1};
int dy_even[6] = { -1,0,1,0 ,-1,1};

//예외 케이스1
int cx_even[3] = {-1,-1,1};
int cy_even[3] = {-1,1,0};

int cx_odd[3] = {1,1,-1};
int cy_odd[3] = {-1,1,0};

//예외 케이스2
int bx_even[3] = {0,0,-1};
int by_even[3] = {-1,1,0};

int bx_odd[3] = {0,0,1};
int by_odd[3] = {-1,1,0};

int n, m;
int arr[20][20];

bool visited[20][20] = { 0, };
int ret = 0;

inline bool move(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j < m;
}

void dfs(int i, int j, int level, int cost)
{
	if (level == 4)
	{
		ret = max(ret, cost);
		return;
	}

	if (j % 2 == 0)
	{
		for (int k = 0; k < 6; k++)
		{
			int nx = i + dx_even[k], ny = j + dy_even[k];
			if (move(nx, ny) && !visited[nx][ny])
			{
				visited[nx][ny] = 1;
				dfs( nx,ny,level + 1,cost + arr[nx][ny] );
				visited[nx][ny] = 0;
			}
		}
	}
	else
	{
		for (int k = 0; k < 6; k++)
		{
			int nx = i + dx_odd[k], ny = j + dy_odd[k];
			if (move(nx, ny) && !visited[nx][ny])
			{
				visited[nx][ny] = 1;
				dfs(nx,ny,level + 1,cost + arr[nx][ny]);
				visited[nx][ny] = 0;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	//1. dfs로 연결된 최댓값 구하기
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 1;
			dfs(i, j,1,arr[i][j]);
			visited[i][j] = 0;

			int tmp1, tmp2;
			tmp1 = tmp2 = arr[i][j];
			//예외처리
			if (j % 2 == 0)
			{
				for (int k = 0; k < 3; k++)
				{
					int nx = i + bx_even[k], ny = j + by_even[k];
					int nnx = i + cx_even[k], nny = j + cy_even[k];

					if (move(nx, ny))
						tmp1 += arr[nx][ny];
					if (move(nnx, nny))
						tmp2 += arr[nnx][nny];
				}
			}
			else
			{
				for (int k = 0; k < 3; k++)
				{
					int nx = i + bx_odd[k], ny = j + by_odd[k];
					int nnx = i + cx_odd[k], nny = j + cy_odd[k];

					if (move(nx, ny))
						tmp1 += arr[nx][ny];
					if (move(nnx, nny))
						tmp2 += arr[nnx][nny];
				}
			}
			ret = max(ret, max(tmp1, tmp2));
		}

	cout << ret;
}
