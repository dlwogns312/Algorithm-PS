#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
int n, k;
int arr[101][11] = { 0, };
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
vector<pair<int,int>> v;
int cnt;

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}
void pop_num()
{
	int tmp = v.size();
	for (int i = 0; i < tmp; i++)
		arr[v[i].first][v[i].second] = 0;
}

int bfs(int i, int j)
{
	v.clear();
	queue<pair<int, int>> q;
	int visited[101][11] = { 0, };
	int comp = arr[i][j];
	q.push({ i,j });
	cnt = 1;
	v.push_back({ i,j });
	visited[i][j] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int t= 0; t < 4; t++)
		{
			int nx = x + dx[t];
			int ny = y + dy[t];

			if (nx >= 0 && nx < n && ny >= 0 && ny < 10 && !visited[nx][ny] && arr[nx][ny] == comp)
			{
				visited[nx][ny] = 1;
				cnt++;
				q.push({ nx,ny });
				v.push_back({ nx,ny });
			}
		}
	}

	if (cnt >= k)
	{
		pop_num();
		//cout << "\n";
		//print();
		return 1;
	}
	else
		return 0;
}

void clear()
{
	//0 정렬
	for (int i = 0; i < 10; i++)
	{
		int swp = n - 1;

		for (int j = n - 1; j >= 0; j--)
		{
			if (!arr[j][i])
				continue;
			else
			{
				if (swp > j)
				{
					arr[swp][i] = arr[j][i];
					arr[j][i] = 0;

				}
				swp--;
			}
		}
	}
}
int main()
{
	//버퍼 분리
	//ios_base::sync_with_stdio(false);

	//stream 분리 flush의 빈도 줄임
	//cin.tie(); cout.tie();

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 10; j++)
			scanf("%1d", &arr[i][j]);

	int ret = 1;
	while (ret)
	{
		ret = 0;
		for (int i = 0; i < n/2; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (arr[i][j])
				{
					if (bfs(i, j)&&!ret)
						ret = 1;
				}
				if (arr[n - 1 - i][j])
				{
					if (bfs(n-1-i, j) && !ret)
						ret = 1;
				}
			}
		}
		if (ret)
			clear();
	}


	//cout << "\n";
	print();
}
