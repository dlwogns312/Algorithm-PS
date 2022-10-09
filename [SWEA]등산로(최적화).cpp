#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <cstring>

using namespace std;

int ret;
int mount[9][9];
int n, k;
vector<pair<int, int>> high;
int max_high;
int visited[9][9];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


inline bool move(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j < n;
}

void dfs(int i, int j,int cnt,int used)
{
	if (cnt > ret)
		ret = cnt;

	for (int x = 0; x < 4; x++)
	{
		int nx = i + dx[x], ny = j + dy[x];

		if (move(nx, ny) && !visited[nx][ny]&&mount[nx][ny])
		{
			if (mount[i][j] > mount[nx][ny])
			{
				visited[nx][ny] = 1;
				dfs(nx, ny, cnt + 1, used);
				visited[nx][ny] = 0;
			}
			else if (!used && mount[i][j] > mount[nx][ny] - k)
			{
				int tmp = mount[nx][ny];
				mount[nx][ny] = mount[i][j] - 1;
				visited[nx][ny] = 1;
				dfs(nx, ny, cnt + 1, 1);
				mount[nx][ny] = tmp;
				visited[nx][ny] = 0;
			}
		}

	}
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		//Initialize
		ret = 0;
		max_high = 0;
		high.clear();
		cin >> n >> k;
		memset(visited, 0, sizeof(visited));

		//input
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				cin >> mount[x][y];
			
				if (mount[x][y] == max_high)
				{
					high.push_back({ x,y });
				}
				else if (mount[x][y] > max_high)
				{
					high.clear();
					max_high = mount[x][y];
					high.push_back({ x,y });
				}
			}
		}

		for (int x = 0; x < high.size(); x++)
		{
			visited[high[x].first][high[x].second] = 1;
			dfs(high[x].first, high[x].second, 1, 0);
			visited[high[x].first][high[x].second] = 0;
		}

		cout << "#" << i << " " << ret << "\n";
	}
}