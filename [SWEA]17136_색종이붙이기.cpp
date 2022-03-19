#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int result = 987654321;
int arr[10][10];
int num = 0;
int chance[5]={0,};

void fill_zero(int i, int j, int n, int f)
{
	for (int x = i; x <= i+n; x++)
		for (int y = j; y <= j+n; y++)
			arr[x][y] = f;
}

int check(int i, int j, int n)
{
	for (int x = i; x <= i+n ; x++)
		for (int y = j; y <= j+n ; y++)
			if (!arr[x][y])
				return 0;
	return 1;
}

void dfs(int i, int j, int cnt)
{
	while (!arr[i][j])
	{
		if (++j >= 10)
		{
			if (++i >= 10)
			{
				result = min(result, cnt);
				return;
			}
			j = 0;
		}
	}

	if (result <= cnt)
		return;

	for (int x = 4; x >= 0; x--)
	{
		if (i + x >= 10 || j + x >= 10 || chance[x] == 5)
			continue;

		if (check(i, j, x ))
		{
			fill_zero(i, j, x , 0);
			chance[x]++;
			dfs(i, j, cnt + 1);

			fill_zero(i, j, x , 1);
			chance[x]--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
				num++;
		}

	
	if (!num)
	{
		cout << 0 << "\n";
		return 0;
	}
	else if (num == 100)
	{
		cout << 4 << "\n";
		return 0;
	}

	
	dfs(0, 0, 0);

	if (result==987654321)
		cout << -1 << "\n";
	else
		cout << result << "\n";
}