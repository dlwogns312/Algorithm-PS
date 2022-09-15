#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>


using namespace std;

int n, m;
int start, dest;
//위상정렬 위해 entry
int entry[10001], cost[10001];
int visited[10001] = { 0, };
int road_num = 0;
vector<pair<int, int>> road[10001], r_road[10001];

void bfs(int s)
{
	queue<pair<int, int>>q;
	q.push({ s,0 });

	while (!q.empty())
	{
		int cur = q.front().first;
		int cur_time = q.front().second;
		q.pop();

		int tmp = road[cur].size();
		for (int i = 0; i < tmp; i++)
		{
			int next = road[cur][i].first;
			int next_time = road[cur][i].second;

			cost[next] = max(cost[next], cur_time + next_time);
			entry[next]--;

			if (!entry[next])
				q.push({ next,cost[next] });
		}
	}
}

void road_count(int e)
{
	queue<int> q;
	q.push(e);
	visited[e] = 1;
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		int tmp = r_road[cur].size();
		for (int i = 0; i < tmp; i++)
		{
			int prev = r_road[cur][i].first;
			int prev_time = r_road[cur][i].second;

			if (cost[cur] - prev_time == cost[prev])
			{
				road_num++;
				if (!visited[prev])
				{
					visited[prev] = 1;;
					q.push(prev);
				}
			}
		}
	}
}

int main()
{
	//버퍼 분리
	ios_base::sync_with_stdio(false);

	//stream 분리 flush의 빈도 줄임
	cin.tie(); cout.tie();

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		r_road[b].push_back({ a,c });
		entry[b]++;
	}
	cin >> start >> dest;

	bfs(start);
	road_count(dest);

	cout << cost[dest] << "\n"<<road_num;
}
