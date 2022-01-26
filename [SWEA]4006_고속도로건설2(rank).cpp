#include<iostream>
#include<vector>
#include<memory>
#include<cmath>
#include<algorithm>

using namespace std;

int n,m;
vector< pair<int, pair<int, int>>> v;
int parent[50001];
int r[50001];

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.first < b.first;
}

int getparent(int node)
{
	if (parent[node] == node)
		return node;
	return parent[node] = getparent(parent[node]);
}

void unionparent(int x, int y)
{
	x = getparent(x);
	y = getparent(y);
	/*if (x < y)
	{
		parent[y] = x;
		return x;
	}
	else
	{
		parent[x] = y;
		return y;
	}*/

	if (r[x] > r[y])
	{
		parent[y] = x;
	}
	else if (r[x] == r[y])
	{
		parent[y] = x;
		r[x]++;
	}
	else
		parent[x] = y;
}


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		v.resize(m);
		int s, e, c;
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> c;
			v[i] = { c,{s,e} };
		}

		sort(v.begin(), v.end(), comp);
		int result = 0;
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			r[i] = 0;
		}

		for (int i = 0; i < v.size(); i++)
		{
			if (getparent(v[i].second.first) != getparent(v[i].second.second))
			{
				result += v[i].first;

				unionparent(v[i].second.first, v[i].second.second);
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}