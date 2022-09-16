#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef struct
{
	int x, y;
	int level, exp;
	int time;
}node;
int n, m;

int arr[21][21];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
node gamer;
int ret = 1;

void bfs()
{
	int visited[21][21] = { 0, };
	visited[gamer.x][gamer.y] = 1;
	queue<node>q;
	q.push(gamer);

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (arr[cur.x][cur.y]&&arr[cur.x][cur.y] < cur.level)
		{
			cur.exp++;
			arr[cur.x][cur.y] = 0;
			if (cur.level == cur.exp)
			{
				cur.level++;
				cur.exp = 0;
			}
			gamer = cur;
			ret = 1;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] <= cur.level)
			{
				visited[nx][ny] = 1;
				q.push({ nx,ny,cur.level,cur.exp,cur.time + 1 });
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

	cin >> n;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				gamer = { i,j,2,0,0 };
				arr[i][j] = 0;
			}
		}


	while (ret)
	{
		ret = 0;
		bfs();
		cout << gamer.x << " " << gamer.y << " " << gamer.level << " " <<gamer.exp << " " << gamer.time << "\n";
	}

	cout << gamer.time;
}
