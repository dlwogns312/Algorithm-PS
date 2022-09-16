#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int arr[1001][1001] = { 0, };
int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ret = 0;
int visited[1001][1001] = { 0, };
int island_name[100000] = { 0, };
int island_num = 2;
int num;

void bfs(int i, int j)
{
	memset(visited, 0, sizeof(visited));
	visited[i][j] = 1;

	queue<pair<int, int>>q;
	num = 1;
	q.push({ i,j });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		arr[x][y] = island_num;

		for (int t = 0; t < 4; t++)
		{
			int nx = x + dx[t];
			int ny = y + dy[t];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny])
			{
				visited[nx][ny] = 1;
				q.push({ nx,ny });
				num++;
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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j]==1)
			{
				bfs(i, j);
				island_name[island_num++] = num;
			}
		}
	}
	island_name[0] = 0;

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!arr[i][j])
			{
				int num = 0;


				ret = max(ret, num + 1);
			}
		}
	}*/

	cout << ret;

}