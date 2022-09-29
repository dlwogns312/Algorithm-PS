#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> parent[122][122];
int arr[122][122];
int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
int dy[8] = { 1,0,-1,0,-1,1,-1,1 };
int visited[122][122];

int N,ret;

pair<int,int>  find(pair<int,int> k)
{
	if (parent[k.first][k.second] == k)
		return k;
	else
		return parent[k.first][k.second] = find(parent[k.first][k.second]);
}

void Union(pair<int, int>a, pair<int, int> b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;

	if (a < b)
		parent[b.first][b.second] = a;
	else
		parent[a.first][a.second] = b;
}

inline bool move(int i, int j)
{
	return i > 0 && i <= N&& j > 0 && j <= N;
}

void init(int _N) {
	N = _N;
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			parent[i][j] = {i,j};
}

int bfs(int i, int j,pair<int,int>now)
{
	int set = 0;
	queue<pair<int, int>>q;
	int flag = 0;
	q.push({ i,j });
	set++;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (arr[nx][ny])
			{
				if (now != find({ nx,ny }))
				{
					return 0;
				}
				continue;
			}
			if (!move(nx, ny))
			{
				return 0;
			}

			if (visited[nx][ny])
				continue;
			set++;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}

	return set;
}

int cell(int row, int col) {
	ret = 0;
	arr[row][col] = 1;
	int check = 0;

	for (int i = 0; i < 8; i++)
	{
		int nx = row + dx[i], ny = col + dy[i];
		if (move(nx, ny)&&arr[nx][ny])
		{
			check++;
			Union({ row,col }, { nx,ny });
		}
	}
	
	if (check >= 2)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = row + dx[i], ny = col + dy[i];
			if (move(nx, ny) && !arr[nx][ny])
			{
				memset(visited, 0, sizeof(visited));
				visited[nx][ny] = 1;
				ret=max(ret,bfs(nx, ny,find({row,col})));
			}
		}
	}
	return ret;
}