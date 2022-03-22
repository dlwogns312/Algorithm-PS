#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
struct rot
{
	int r, c, s;
}node[6];

int order[6],Select[6];
int n, m, k;
int arr[51][51];
int result = INT_MAX;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ret[51][51];

void ret_rot(int r, int c, int s)
{

	int i = r - s, j = c - s;
	int len, next_i, next_j,dir,now;
	len = 2 * s + 1;
	now = 0;
	dir = 0;
	int temp = arr[i][j];
	while (1)
	{
		if (now == len - 1)
		{
			dir++;
			now = 0;
		}

		if (dir == 4)
		{
			ret[i][j + 1] = temp;
			i++; j++;
			temp = ret[i][j];
			dir = 0;
			len -= 2;
		}
		if (len<=1)
			break;
		next_i = dx[dir] + i;
		next_j = dy[dir] + j;
		ret[i][j] = ret[next_i][next_j];
		now++;

		i = next_i; j = next_j;
	}
}


void dfs(int num)
{
	if (num == k)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				ret[i][j] = arr[i][j];

		for (int i = 0; i < k; i++)
			ret_rot(node[order[i]].r, node[order[i]].c, node[order[i]].s);
		int temp;
		for (int i = 1; i <= n; i++)
		{
			temp = 0;
			for (int j = 1; j <= m; j++)
			{
				temp += ret[i][j];
			}
			result = min(result, temp);
		}
		return;
	}

	for (int i = 0; i < k; i++)
	{
		if (Select[i])
			continue;
		Select[i] = 1;
		order[num] = i;
		dfs(num + 1);

		Select[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m>>k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		node[i].r = a;
		node[i].c = b;
		node[i].s = c;
	}
	
	memset(Select, 0, sizeof(Select));

	dfs(0);

	cout << result << "\n";
}