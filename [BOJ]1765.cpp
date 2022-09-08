#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 1001
using namespace std;

int n, m;

vector<int> parent[MAX];
vector<int> enemy[MAX];
int visited[MAX];

void dfs(int num)
{
	visited[num] = 1;
	int temp = parent[num].size();

	for (int i = 0; i < temp; i++)
	{
		int nxt = parent[num][i];
		if (!visited[nxt])
			dfs(nxt);
	}
	temp = enemy[num].size();
	for (int i = 0; i < temp; i++)
	{
		int nxt = enemy[num][i];
		int temp_nxt = enemy[nxt].size();
		for (int j = 0; j < temp_nxt; j++)
		{
			int nnxt = enemy[nxt][j];
			if (!visited[nnxt])
				dfs(nnxt);
		}
	}
}

int main()
{
	cin >> n >> m;

	char c;
	int a, b;
	int ret = 0;

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < m; i++)
	{
		cin >> c >> a >> b;
		if (c == 'E')
		{
			enemy[a].push_back(b);
			enemy[b].push_back(a);
		}
		else
		{
			parent[a].push_back(b);
			parent[b].push_back(a);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			ret++;
		}
	}
	cout << ret;
}