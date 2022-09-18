#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>

#define MAXN 21
#define INF 9999

using namespace std;

int n;

typedef struct
{
	int x, y;
	int level, exp;
}fighter;

typedef struct
{
	int x, y;
	int moved;
}node;

int arr[MAXN][MAXN];
fighter player;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

//check whether there is monster to kill or not
int off = 1;
int ret = 0;

//compare the position of monsters if false -> change
bool comp(const node& a, const node& b)
{
	if (a.moved == b.moved)
	{
		if (a.x == b.x)
			return a.y < b.y;
		else
			return a.x < b.x;
	}
	else
		return a.moved < b.moved;
}

inline bool move(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j < n;
}

int play()
{
	int min_move = INF;
	int visited[MAXN][MAXN] = { 0, };
	
	queue<node> q;
	vector<node> v;

	q.push({ player.x,player.y,0 });
	visited[player.x][player.y] = 1;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (cur.moved > min_move)
			continue;

		if (arr[cur.x][cur.y]&&arr[cur.x][cur.y] < player.level)
		{
			v.push_back({ cur.x,cur.y,cur.moved });
			min_move = cur.moved;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i], ny = cur.y + dy[i];

			if (move(nx, ny) && !visited[nx][ny] && arr[nx][ny] <= player.level)
			{
				visited[nx][ny] = 1;
				q.push({ nx,ny,cur.moved + 1 });
			}
		}
	}

	if (v.empty())
		return 0;

	sort(v.begin(), v.end(), comp);

	player.exp++;
	ret += v[0].moved;
	arr[v[0].x][v[0].y] = 0;
	player.x = v[0].x;
	player.y = v[0].y;
	
	if (player.exp == player.level)
	{
		player.level++;
		player.exp=0;
	}

	return 1;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				arr[i][j] = 0;
				player = { i,j,2,0 };
			}
		}

	//play
	while (off)
	{
		off=play();
	}

	cout << ret;

}