#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <cstring>

using namespace std;
int v, e;

vector<vector<int>> graph;
int visited[20001];

void bfs(int cur)
{
	if (!visited[cur])
	{
		visited[cur] = 1;
	}

	queue<pair<int, int>>q;
	q.push({ cur,1 });
	
	while (!q.empty())
	{
		int now = q.front().first;
		int now_color = q.front().second;
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			if (!visited[graph[now][i]])
			{
				if (now_color == 1)
				{
					visited[graph[now][i]] = 2;
					q.push({ graph[now][i],2 });
				}
				else
				{
					visited[graph[now][i]] = 1;
					q.push({ graph[now][i], 1 });
				}
			}
		}
	}
}

bool check()
{
	for (int cur = 1; cur <= v; cur++)
	{
		for (int i = 0; i < graph[cur].size(); i++)
		{
			if (visited[cur] == visited[graph[cur][i]])
				return false;
		}
	}
	return true;
}

int main()
{
	int k;
	cin >> k;
	while (k--)
	{
		cin >> v >> e;
		memset(visited, 0, sizeof(visited));
		graph.assign(v + 1, vector<int>(0, 0));

		for (int i = 0; i < e; i++)
		{
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		for (int i = 1; i <= v; i++)
		{
			if (!visited[i])
				bfs(i);
		}
		if (check())
			cout << "YES\n";
		else
			cout << "NO\n";
	}


}