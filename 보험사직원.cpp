#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct node
{
	int timestamp, caseid, cityid, priority;
};

struct comp
{
	bool operator() (const node& a, const node& b)const
	{
		if (a.priority != b.priority)
			return a.priority > b.priority;
		return a.timestamp < b.timestamp;
	}
};

set<node,comp> Case;
set<node,comp>::iterator itr[100000];

vector<int> cancellist;

int cur_node, cur_time,flag;
int n, arr[351][351];
int dist[351][351];

vector<int> child[351];
vector<int>path;
int root[351];

void dfs(int now)
{
	path.push_back(now);

	for (int i = 0; i < path.size()-1; i++)
	{
		dist[now][path[i]] = root[now];
		dist[path[i]][now] = path[i + 1];
	}
	dist[now][now] = now;
	for (auto it : child[now])
	{
		dist[now][it] = it;
		dfs(it);
	}
	path.pop_back();
}

void init(int N, int _parent[]) {
	memset(arr, 0, sizeof(arr));
	memset(root, 0, sizeof(root));
	memset(dist, -1, sizeof(dist));
	Case.clear();
	cancellist = vector<int>(100000);
	n = N;

	for (int i = 0; i <= n - 1; i++)
	{
		root[i] = _parent[i];
	}

	for (int i = 0; i < n; i++)
	{
		child[i].clear();
		for (int j = 0; j < n; j++)
		{
			if (root[j] == i)
				child[i].push_back(j);
		}
	}
	dfs(0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (dist[i][j] == -1)
				dist[i][j] = root[i];

	cur_node = 0; cur_time = -1;  flag = 0;
}

int move(int goal)
{
	cur_time++;

	if (!flag && cur_node == goal)
	{
		flag = 1;
		return flag;
	}
	cur_node = dist[cur_node][goal];
	return 0;
}

void execute(int timeStamp)
{
	while (!Case.empty() && cur_time < timeStamp)
	{
		node now = *Case.begin();

		int id = now.caseid;
		if (cancellist[id])
		{
			Case.erase(itr[id]);
			continue;
		}
		if (move(now.cityid))
		{
			Case.erase(itr[id]);
			flag = 0;
		}
	}
	cur_time = timeStamp;
}
void occur(int timeStamp, int caseID, int cityID, int priority) {
	execute(timeStamp);
	itr[caseID] = Case.insert({ timeStamp,caseID,cityID,priority }).first;
}
void cancel(int timeStamp, int caseID) {
	execute(timeStamp);
	cancellist[caseID] = 1;
}
int position(int timeStamp) {

	execute(timeStamp);
	return cur_node;
}