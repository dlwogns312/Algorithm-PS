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

#define INF 999999
using namespace std;

int visited[11], popul[11];
int Map[11][11] = { 0, };

int ret = INF;
int n;

int check(int now,int cost)
{
	int tmp[11] = { 0, };
	tmp[now] = 1;
	queue<int>q;
	q.push(now);
	int cnt = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cnt == cost)
			break;

		for (int i = 1; i <= n; i++)
		{
			if (Map[cur][i] && !tmp[i] && visited[i])
			{
				q.push(i);
				tmp[i] = 1;
				cnt++;
			}
		}
	}
	if (cnt != cost)
		return 0;

	cnt = 1;
	q = queue<int>();
	for(int i=1;i<=n;i++)
		if (!visited[i])
		{
			now = i;
			break;
		}

	q.push(now);
	tmp[now] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cnt == n - cost)
			break;

		for (int i = 1; i <= n; i++)
		{
			if (Map[cur][i] && !tmp[i] && !visited[i])
			{
				q.push(i);
				tmp[i] = 1;
				cnt++;
			}
		}
	}

	if (cnt == n - cost)
		return 1;
	return 0;
}

int calculate()
{
	int tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			tmp += popul[i];
		else
			tmp -= popul[i];
	}

	return abs(tmp);
}

void dfs(int now, int cost)
{
	if (cost >= 1)
	{
		if (check(now,cost))
		{
			ret = min(ret, calculate());
		}
	}

	for (int i = now; i <= n; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		dfs(i, cost + 1);
		visited[i] = 0;
	}
}

int main()
{
	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		cin >> popul[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		while (tmp--)
		{
			int t;
			cin >> t;
			Map[i][t] = 1;
			Map[t][i] = 1;
		}
	}

	dfs(1, 0);

	if (ret == INF)
		cout << "-1";
	else
		cout << ret;
}