#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int n, arr[17][17];
int result = 0;

void dfs(int i, int j, int now)
{
	if (i == n - 1 && j == n - 1)
	{
		result++;
		return;
	}
	if (now == 0)
	{
		if (!arr[i][j + 1])
		{
			dfs(i, j + 1, 0);
			if (!arr[i + 1][j + 1] && !arr[i + 1][j])
				dfs(i + 1, j + 1, 1);
		}		
	}
	else if (now == 1)
	{
		if (!arr[i][j + 1])
			dfs(i, j + 1, 0);
		if (!arr[i + 1][j])
			dfs(i + 1, j, 2);
		if (!arr[i + 1][j + 1] && !arr[i + 1][j] && !arr[i][j + 1])
			dfs(i + 1, j + 1, 1);
	}
	else
	{
		if (!arr[i + 1][j])
		{
			dfs(i + 1, j, 2);
			if (!arr[i + 1][j + 1] && !arr[i][j + 1])
				dfs(i + 1, j + 1, 1);
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//memset(dp, 0, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i <= n; i++)
	{
		arr[i][n] = 1;
		arr[n][i] = 1;
	}
	dfs(0, 1, 0);

	cout << result << "\n";
}