#include <iostream>
using namespace std;
int arr[14][14] = { 0, };
int row[14] = { 0, };
int n;
int ret = 0;

int check_dir(int i, int j)
{
	int temp_i = i-1, temp_j = j-1;
	while (temp_i >= 0 && temp_j >= 0)
	{
		if (arr[temp_i--][temp_j--])
			return 1;
	}
	temp_i = i - 1; temp_j = j + 1;
	while (temp_i >= 0 && temp_j < n)
	{
		if (arr[temp_i--][temp_j++])
			return 1;
	}
	return 0;
}
void dfs(int depth)
{
	if (depth == n)
	{
		ret++;
		return;
	}

	if (depth == 0)
	{
		for (int i = 0; i < n; i++)
		{
			arr[0][i] = 1;
			row[i] = 1;
			dfs(depth + 1);
			row[i] = 0;
			arr[0][i] = 0;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!row[i] && !check_dir(depth, i))
			{
				arr[depth][i] = 1;
				row[i] = 1;
				dfs(depth + 1);
				row[i] = 0;
				arr[depth][i] = 0;
			}
		}
	}
}
int main()
{
	cin >> n;
	dfs(0);
	cout << ret;
}