#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

#define MAXN 5

using namespace std;

typedef struct
{
	int x, y;
	int level, ate;
	string route;
}shark;

int fish_num = 0;
string route;
int m, s;
int arr[MAXN][MAXN] = { 0, };

//물고기 저장
int bowl[MAXN][MAXN][8] = { 0, };
int new_bowl[MAXN][MAXN][8] = { 0, };

//물고기 수
int bowl_cnt[MAXN][MAXN] = { 0, };
int new_bowl_cnt[MAXN][MAXN] = { 0, };

int ret = 0;

//상어 위치
int sh_x, sh_y;
int visited[5][5] = { 0, };

//상어이동
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

//물고기 이동
int fish_dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int fish_dy[8] = { -1,-1,0,1,1,1,0,-1 };

inline bool move(int i, int j)
{
	return i > 0 && i <= 4 && j > 0 && j <= 4;
}

void fish_move(int x, int y, int f,int fish_map[][MAXN])
{
	int i = 8, temp = f;
	int flag = 0;

	while (i--)
	{
		int nx = x + fish_dx[f], ny = y + fish_dy[f];

		if (move(nx, ny) && !arr[nx][ny])
		{
			new_bowl[nx][ny][f]+=bowl[x][y][temp];
			new_bowl_cnt[nx][ny]+=bowl[x][y][temp];
			flag = 1;
			fish_map[nx][ny] += bowl[x][y][temp];
			break;
		}

		f = (f + 7) % 8;

	}
	if (!flag)
	{
		new_bowl[x][y][f] += bowl[x][y][temp];
		new_bowl_cnt[x][y]+=bowl[x][y][temp];
		fish_map[x][y]+=bowl[x][y][temp];
	}
}

void shark_move(int x, int y, int level, string save_route, int ate,int fish_map[][MAXN])
{
	if (level == 3)
	{
		if (ate > fish_num)
		{
			fish_num = ate;
			route = save_route;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];

		if (move(nx, ny))
		{
			int tmp = fish_map[nx][ny];
			fish_map[nx][ny] = 0;
			shark_move(nx, ny, level + 1, save_route + (char)('0' + i), ate + tmp,fish_map);
			fish_map[nx][ny] = tmp;
		}
	}

	return;
}

void magic()
{
	//new_bowl 초기화
	memset(new_bowl, 0, sizeof(new_bowl));
	memset(new_bowl_cnt, 0, sizeof(new_bowl_cnt));

	int fish_map[MAXN][MAXN] = { 0, };

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (!bowl_cnt[i][j])
				continue;

			for (int k = 0; k < 8; k++)
			{
				if (!bowl[i][j][k])
					continue;
				fish_move(i, j, k,fish_map);
			}
		}
	}

	fish_num = -1; route = "";
	memset(visited, 0, sizeof(visited));
	
	shark_move(sh_x, sh_y, 0, "", 0,fish_map);

	if (arr[sh_x][sh_y] < 0)
		arr[sh_x][sh_y] = 0;

	for (int i = 0; i < 3; i++)
	{
		sh_x += dx[route[i] - '0'];
		sh_y += dy[route[i] - '0'];
		if (!new_bowl_cnt[sh_x][sh_y])
			continue;

		new_bowl_cnt[sh_x][sh_y]=0;
		arr[sh_x][sh_y] = 3;
	}


	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
		{
			if (arr[i][j] > 0)
				arr[i][j]--;
			if (!new_bowl_cnt[i][j])
				continue;

			for (int k = 0; k < 8; k++)
				bowl[i][j][k] += new_bowl[i][j][k];

			bowl_cnt[i][j] += new_bowl_cnt[i][j];
		}	
	
	if (arr[sh_x][sh_y] == 0)
		arr[sh_x][sh_y] = -1;

}

int main()
{
	cin >> m >> s;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		bowl[a][b][c - 1]++;
		bowl_cnt[a][b]++;
	}
	cin >> sh_x >> sh_y;
	arr[sh_x][sh_y] = -1;

	while (s--)
	{
		magic();
	}

	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			if (!bowl_cnt[i][j])
				continue;
			else
				ret += bowl_cnt[i][j];

	cout << ret;
}