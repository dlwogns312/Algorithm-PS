#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
int n, m;
int dx_even[6] = { 0,-1,0,1,1,-1};
int dy_even[6] = { 1,0,-1,0,-1,-1 };
int dx_odd[6] = { 0,-1,0,1,1,-1 };
int dy_odd[6] = { 1,0,-1,0,1,1 };

int visited[15][15] = { 0, };
int save[15][15]={ 0, };
int arr[15][15];
int ret = 0;

int check_up_x[3]={}

void dfs(int i, int j,int level,int cost)
{
	if (level == 4)
	{
		ret = max(ret, cost);
		return;
	}

	if (level == 1)
	{
		
	}
	if (j % 2 == 0)
	{
		for (int x = 0; x < 6; x++)
		{
			int nx = i + dx_even[x];
			int ny = j + dy_even[x];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
			{
				visited[nx][ny] = 1;
				dfs(nx, ny, level + 1, cost + arr[nx][ny]);
				visited[nx][ny] = 0;
			}
		}
	}
	else
	{
		for (int x = 0; x < 6; x++)
		{
			int nx = i + dx_odd[x];
			int ny = j + dy_odd[x];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
			{
				visited[nx][ny] = 1;
				dfs(nx, ny, level + 1, cost + arr[nx][ny]);
				visited[nx][ny] = 0;
			}
		}
	}
}


int main()
{
	//버퍼 분리
	ios_base::sync_with_stdio(false);

	//stream 분리 flush의 빈도 줄임
	cin.tie(); cout.tie();

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 1;
			dfs(i, j,1,arr[i][j]);
			visited[i][j] = 0;
			
		}
	
	

	cout << ret;
}
