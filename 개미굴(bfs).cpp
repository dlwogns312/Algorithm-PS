#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

int visited[1001][1001] = { 0, };

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int n, m;
int arr[1001][1001];

//save the island size and number
int island_num = 1;
int island_name[100001] = { 0, };

int ret = 0;

inline int move(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j < m;
}

void grouping()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!arr[i][j]||visited[i][j])
				continue;

			queue<pair<int, int>> q;
			q.push({ i,j });
			int num=1;
			visited[i][j] = island_num;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k], ny = y + dy[k];
					if (move(nx, ny) && arr[nx][ny] && !visited[nx][ny])
					{
						visited[nx][ny] = island_num;
						num++;
						q.push({ nx,ny });
					}
				}
			}

			island_name[island_num++] = num;
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	//mark island name by bfs
	grouping();

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
				continue;

			set<int> s;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if (move(nx, ny) && arr[nx][ny])
					s.insert(visited[nx][ny]);
			}
			if (s.empty())
				continue;
			int tmp = 0;

			for (auto it : s)
			{
				int plus = it;
				tmp += island_name[plus];
			}

			ret = max(ret, tmp+1);
		}


	cout << ret;
}
