#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct shark {
	int now_r, now_c, dir, s,i,update;
}node[10001];

int R, C,m,now;
int result = 0;
int arr[101][101];
vector<int> live = {};
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

void update()
{
	int r, c,s;
	for (int i = 0; i < live.size(); i++)
	{
		if (node[live[i]].update == -1)
			continue;
		arr[node[live[i]].now_r][node[live[i]].now_c] = 0;
	}

	for (int i = 0; i < live.size(); i++)
	{
		if (node[live[i]].update == -1)
			continue;
		int temp = live[i];
		int x = node[temp].now_r;
		int y = node[temp].now_c;
		int dir = node[temp].dir;
		int s = node[temp].s;

		if (dir == 1 || dir == 2)
		{
			int rot = (R - 1) * 2;
			if (s >= rot)
				s = s % rot;

			for (int j = 0; j < s; j++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 1)
				{
					dir = 2;
					nx += 2;
				}
				if (nx > R)
				{
					dir = 1;
					nx = nx - 2;
				}
				x = nx;
				y = ny;
			}
		}
		else
		{
			int rot = (C - 1) * 2;
			if (s >= rot)
				s = s % rot;

			for (int j = 0; j < s; j++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (ny < 1)
				{
					dir = 3;
					ny += 2;
				}
				if (ny > C)
				{
					dir = 4;
					ny = ny - 2;
				}
				x = nx;
				y = ny;
			}
		}

		node[temp].now_r = x;
		node[temp].now_c = y;
		node[temp].dir = dir;
		if (arr[x][y])
		{
			if (arr[x][y] > temp)
				node[temp].update = -1;
			else
			{
				node[arr[x][y]].update = -1;
				arr[x][y] = temp;
			}
		}
		else
			arr[x][y] = temp;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> m;

	memset(arr, 0, sizeof(arr));
	int r, c, s, d, z;
	for (int i = 0; i < m; i++)
	{
		cin >> r >> c >> s >> d >> z;
		node[z].now_r = r;
		node[z].now_c = c;
		node[z].s = s;
		node[z].dir = d;
		node[z].update = 0;
		arr[r][c] = z;
		live.push_back(z);
	}

	for (now = 1; now <= C; now++)
	{
		for (int i = 1; i <= R; i++)
		{
			if (arr[i][now])
			{
				result += arr[i][now];
				node[arr[i][now]].update = -1;
				arr[i][now] = 0;
				break;
			}
		}

		update();
	}
	
	cout << result << "\n";
	return 0;

}