#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

#define MAXN 11
#define INF 9999

using namespace std;

typedef struct
{
	int x, y;
	int cost;
}node;

struct comp
{
	bool operator()(node a, node b)
	{
		return a.cost > b.cost;
	}
};

int  n, m;
int arr[MAXN][MAXN];

//섬 이름
int island_num = 2;

//섬 edge
vector<pair<int,int>> island_edge[10];
int bridge[MAXN][MAXN];
priority_queue<node, vector<node>, comp>dist;

//union-find;
int parent[10];

int ret = 0;

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

inline bool move(int x, int y)
{
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int find_parent(int x)
{
	if (parent[x] < 0)
		return x;
	else return parent[x] = find_parent(parent[x]);
}

bool Union(int a, int b)
{
	a = find_parent(a); b = find_parent(b);

	if (a == b)
		return false;

	if (a < b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
	else
	{
		parent[b] += parent[a];
		parent[a] = b;
	}

	return true;
}
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });

	int min_x = x, max_x = x;
	int min_y = y, max_y = y;

	while (!q.empty())
	{
		int edge_check = 0;
		int i = q.front().first, j = q.front().second;
		q.pop();

		arr[i][j] = island_num;

		for (int k = 0; k < 4; k++)
		{
			int nx = i + dx[k], ny = j + dy[k];

			if (move(nx, ny))
			{
				if(arr[nx][ny] == 1)
					q.push({ nx,ny });
				if(arr[nx][ny]==0)
					edge_check++;
			}
		}

		if (edge_check)
			island_edge[island_num].push_back({ i,j });

	}

	island_num++;
}

void find_dist(int island)
{
	int island_dist = INF;
	int tmp = island_edge[island].size();

	for (int i = 0; i < tmp; i++)
	{
		int x = island_edge[island][i].first;
		int y = island_edge[island][i].second;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			int len = 0;
			while (arr[nx][ny] != island && move(nx, ny))
			{
				if (arr[nx][ny])
				{
					if (len >= 2)
						bridge[island][arr[nx][ny]] = min(bridge[island][arr[nx][ny]], len);
					break;
				}
				nx += dx[k]; ny += dy[k];
				len++;
			}
		}
	}

	for (int i = 2; i < island_num; i++)
	{
		if (i != island)
			dist.push({ island,i,bridge[island][i] });
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}

	//섬 number 매기기 & edge 좌표 구하기
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 1)
				bfs(i, j);

	for (int i = 2; i < island_num; i++)
		for (int j = 2; j < island_num; j++)
			bridge[i][j] = INF;
	//edge간의 거리구하기&&각 섬간의 거리
	for (int i = 2; i < island_num; i++)
		find_dist(i);

	//parent 초기화
	for (int i = 0; i < 10; i++)
		parent[i] = -1;

	
	while(!dist.empty())
	{
		if (-parent[2] == island_num-2)
			break;
		node temp = dist.top();
		dist.pop();

		if (temp.cost == INF)
		{
			ret = -1;
			break;
		}
		if (Union(temp.x, temp.y))
			ret += temp.cost;
	}
	

	cout << ret;
}