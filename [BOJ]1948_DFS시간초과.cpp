#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>

using namespace std;

int n, m;
int start, dest;
vector<pair<int,pair<int,int>>> v[10001];
int max_time, num;
int visited[10001] = { 0, };
int road_num = 0;
int temp_arr[100001]={ 0, };
unordered_set<int> result;

void dfs(int now, int cost, int level)
{
	if (now == dest)
	{
		if(max_time==cost)
			for (int i = 0; i < level; i++)
				result.insert(temp_arr[i]);
		if (max_time < cost)
		{
			max_time = cost;
			result.clear();
			for (int i = 0; i < level; i++)
				result.insert(temp_arr[i]);
		}
	}
	
	int tmp = v[now].size();
	for(int i=0;i<tmp;i++)
		if (!visited[v[now][i].second.first])
		{
			visited[v[now][i].second.first] = 1;
			temp_arr[level] = v[now][i].first;
			dfs(v[now][i].second.first,cost+v[now][i].second.second,level+1);
			visited[v[now][i].second.first] = 0;
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
		v[a].push_back({ road_num++,{ b,c } });
	}
	cin >> start >> dest;
	visited[start] = 1;
	max_time = 0;
	num = 0;

	dfs(start, 0,0);
	
	cout << max_time << "\n" << result.size();
	
}
