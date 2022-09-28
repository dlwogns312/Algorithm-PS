#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <cstring>

using namespace std;
int n;
int flag = 0;
int parent[200001] = { 0 };
int query[400001][3] = { 0, };
int ans[200001];
int root[200001];

int find(int x)
{
	if (root[x] == x)
		return x;
	else
		return root[x]= find(root[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	root[y] = x;
	
}
int main()
{
	int q;
	cin >> n >> q;
	int tmp;

	for (int i = 0; i <= 200000; i++)
		root[i] = i;

	for (int i = 2; i <= n; i++)
	{
		int par;
		cin >> par;
		parent[i] = par;
	}
	int test = q + n - 1;
	for(int i=0;i<test;i++)
	{
		cin >> query[i][0];
		if (query[i][0])
			cin >> query[i][1] >> query[i][2];
		else
			cin >> query[i][1];
	}

	int anscnt = 0;

	for (int i = n - 2 + q; i >= 0; i--)
	{
		if (query[i][0])
		{
			ans[anscnt] = (find(query[i][1]) == find(query[i][2]));
			anscnt++;
		}
		else
			Union(query[i][1], parent[query[i][1]]);
	}

	for (int i = anscnt - 1; i >= 0; i--)
	{
		if (ans[i])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

}