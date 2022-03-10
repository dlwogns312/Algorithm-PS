#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int t, n;
bool visit[10001];
int parent[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			visit[i] = false;
			parent[i] = i;
		}

		int a, b;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> a >> b;
			parent[b] = a;
		}

		cin >> a >> b;
		visit[a] = true;

		while (a != parent[a])
		{
			a = parent[a];
			visit[a] = true;
		}

		while (1)
		{
			if (visit[b])
			{
				cout << b << '\n';
				break;
			}
			b = parent[b];
		}
	}

		
}