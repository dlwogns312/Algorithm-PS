#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

int arr[51][51];
int n, m;
int result =0;
int num = 0;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int bx[4] = {1,0,-1,0};
int by[4] = {0,-1,0,1};

int now_i, now_j, dir;

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == now_i && j == now_j)
				cout << 3 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}
void dfs()
{

	int cont_num;

	int terminate = 0;
	while (!terminate)
	{
		int nx;
		int ny;

		if (arr[now_i][now_j] == 0)
		{
			arr[now_i][now_j] = 2;
			result++;
		}

		for (cont_num = 0; cont_num < 4; cont_num++)
		{
			nx = now_i + dx[dir];
			ny = now_j + dy[dir];
			if (!arr[nx][ny])
			{
				arr[nx][ny] = 2;
				now_i = nx;
				now_j = ny;
				dir = (dir + 3) % 4;
				result++;
				break;
			}
			else {
				dir = (dir + 3) % 4;

				nx = now_i + bx[dir];
				ny = now_j + by[dir];
				if (arr[nx][ny] != 1)
				{
					now_i = nx;
					now_j = ny;
					break;
				}
			}
		}
		
		if (cont_num == 4)
		{
			nx = now_i + bx[dir];
			ny = now_i + by[dir];
			if (arr[nx][ny] == 1)
				terminate = 1;
			else
			{
				now_i = nx;
				now_j = ny;
			}
		}
		print();
	}

	
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> n >> m;
	cin >> now_i >> now_j >> dir;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (!arr[i][j])
				num++;
		}

	//arr[now_i][now_j] = 2;
	dfs();

	cout << result << "\n";
}