#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
typedef struct _node
{
	int x, y;
}marble;

char arr[15][15];
int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { 1,0,-1,0 };
int n, m;

int move(queue<pair<int,pair<marble,marble>>>  &q,marble red, marble blue, int dir, int ret)
{
	int check = 0;
	marble temp_red=red;
	marble temp_blue = blue;
	int red_move = 0;
	int blue_move = 0;
	int red_find = 0;
	int blue_find = 0;
	while (!check)
	{
		check = 1;
		if (arr[temp_red.x + dir_x[dir]][temp_red.y + dir_y[dir]] == '.')
		{
			temp_red.x += dir_x[dir];
			temp_red.y += dir_y[dir];
			red_move++;
			check = 0;
		}
		else if (arr[temp_red.x + dir_x[dir]][temp_red.y + dir_y[dir]] == 'O')
		{
			temp_red.x += dir_x[dir];
			temp_red.y += dir_y[dir];
			red_move++;
			red_find = 1;
		}
		if (arr[temp_blue.x + dir_x[dir]][temp_blue.y + dir_y[dir]] == '.')
		{
			temp_blue.x += dir_x[dir];
			temp_blue.y += dir_y[dir];
			blue_move++;
			check = 0;
		}
		else if (arr[temp_blue.x + dir_x[dir]][temp_blue.y + dir_y[dir]] == 'O')
		{

			temp_blue.x += dir_x[dir];
			temp_blue.y += dir_y[dir];
			blue_move++;
			blue_find = 1;
		}
	}

	
	if (temp_red.x==temp_blue.x&&temp_red.y==temp_blue.y)
	{
		if (red_move > blue_move)
		{
			temp_red.x -= dir_x[dir];
			temp_red.y -= dir_y[dir];
		}
		else
		{
			temp_blue.x -= dir_x[dir];
			temp_blue.y -= dir_y[dir];
		}
	}
	if (temp_red.x == red.x && temp_red.y == red.y && temp_blue.x == blue.x && temp_blue.y == blue.y)
		return 0;
	if(!blue_find&&!red_find)
		q.push({ ret + 1,{temp_red,temp_blue} });

	if (blue_find)
		red_find = 0;
	return red_find;
}

int bfs( marble red, marble blue)
{
	queue<pair<int,pair<marble, marble>>> q;
	q.push({ 1,{ red, blue } });

	int ret = 1;

	while (!q.empty()&&ret<11)
	{
		marble tmp_red = q.front().second.first;
		marble tmp_blue = q.front().second.second;

		ret = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tmp = move(q, tmp_red, tmp_blue, i, ret);
			if (tmp == 1)
			{
				return ret;
			}
		}
	}
	
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	marble red, blue, hole;
	cin >> n >> m;
	for(int i =0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'B')
			{
				blue.x = i; blue.y = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'R')
			{
				red.x = i; red.y = j;
				arr[i][j] = '.';
			}
		}
	int ret=bfs( red, blue);

	cout << ret << "\n";

}