#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

bool visited[1001][1001];
pair<int,int> parent[1001][1001];

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int n, m;
int arr[1001][1001];
int ret = 0;

inline bool move(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j < m;
}

pair<int,int> find(pair<int, int>x)
{
	if (parent[x.first][x.second].first < 0)
		return x;
	return parent[x.first][x.second] = find(parent[x.first][x.second]);
}

void Union(pair<int, int>x, pair<int, int> y)
{
	x = find(x); y = find(y);
	if (x == y)
		return;
	int cnt_x = -parent[x.first][x.second].first;
	int cnt_y = -parent[y.first][y.second].first;

	if (cnt_x > cnt_y)
	{
		parent[y.first][y.second] = x;
		parent[x.first][x.second].first += -cnt_y;
	}
	else
	{
		parent[y.first][y.second].first += -cnt_x;
		parent[x.first][x.second] = y;
	}
}
void grouping()
{
	memset(parent, -1, sizeof(parent));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > 0)
			{
				for (int k = 0; k < 2; k++)
				{
					int nx = i + dx[k],ny=j+dy[k];
					if (move(nx, ny) && arr[nx][ny])
						Union({ i,j }, { nx, ny });
				}
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

	grouping();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
				continue;

			set<pair<int, int>>s;
			for (int x = 0; x < 4; x++)
			{
				int nx = i + dx[x], ny = j + dy[x];
				if (move(nx, ny) && arr[nx][ny])
					s.insert(find({ nx, ny }));
			}

			if (s.empty())
				continue;

			int tmp = 0;
			for (auto it : s)
			{
				pair<int, int> plus = it;
				tmp += (-parent[plus.first][plus.second].first);
			}
			ret = max(ret, tmp+1);
		}
	}
	cout << ret;
}
