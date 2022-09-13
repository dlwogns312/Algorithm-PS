#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
long long int ret = 0;

int check(int arr[5][5])
{
	for (int i = 0; i < m; i++)
	{
		int temp[201] = { 0, };
		for (int j = 0; j < n; j++)
		{
			if (!temp[arr[j][i] + 100])
				temp[arr[j][i] + 100]++;
			else
				return 0;
		}
	}
	return 1;
}
long long int cal(int arr[5][5])
{
	long long int result = 1;
	for (int i = 0; i < m; i++)
	{
		int tmp = 0;
		for (int j = 0; j < n; j++)
			tmp += arr[j][i];
		result *= tmp;
	}
	return result;
}

void dfs(int level,int arr[5][5])
{
	if (level == n)
	{
		ret = max(ret, cal(arr));
		return;
	}

	for (int i = 0; i < m; i++)
	{
		int tmp = arr[level][m-1];
		for (int j = m - 1; j > 0; j--)
			arr[level][j] = arr[level][j - 1];
		arr[level][0] = tmp;
		if (level == n - 1)
		{
			if (check(arr))
				dfs(level + 1, arr);
		}
		else
			dfs(level + 1, arr);
	}
}

int main()
{
	cin >> n>>m;

	int arr[5][5];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	dfs(0,arr);
	cout << ret;
}