#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 10000
int dx[9] = { 0,1,-1,0,0,-1 ,-1,1,1};
int dy[9] = { 1,0,0,-1,0, -1,1,1,-1};
char arr[5][5];
int visited[5][5][5][5] = { 0, };
int n;

typedef struct
{
	int an_x, an_y;
	int el_x, el_y;
	int result;
}node;

int dist(int a, int b, int c, int d)
{
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}
int main()
{
	queue<node> q;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	q.push({c,d,a,b,0});
	visited[c][d][a][b] = 1;
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();

		if (tmp.an_x == tmp.el_x && tmp.an_y == tmp.el_y)
		{
			cout << tmp.result;
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			int an_x = tmp.an_x + dx[i];
			int an_y = tmp.an_y + dy[i];

			if (an_x >= 0 && an_x < n && an_y >= 0 && an_y < n && arr[an_x][an_y] == '_')
			{
				for (int j = 0; j < 9; j++)
				{
					if (j >= 5 && dist(tmp.el_x, tmp.el_y, tmp.an_x, tmp.an_y) <= 2)
						break;
					int el_x = tmp.el_x + dx[j];
					int el_y = tmp.el_y + dy[j];

					if (el_x >= 0 && el_x < n && el_y >= 0 && el_x < n && arr[el_x][el_y] == '_' && !visited[an_x][an_y][el_x][el_y])
					{
						visited[an_x][an_y][el_x][el_y] = 1;
						q.push({ an_x,an_y,el_x,el_y,tmp.result + 1 });
					}
				}
			}
		}
	}
	cout << " sec";
}
