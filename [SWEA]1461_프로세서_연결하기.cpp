#include<iostream>
#include<vector>

using namespace std;

int n;
int c_num;
int max_d;
int cell[13][13];
int result;
int result_arr[100];

void dfs(int count, int done, vector<pair<int, int>> v)
{
	if (c_num == count)
	{
		int temp = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (cell[i][j] == 2)
					temp++;

		result_arr[done] = min(result_arr[done], temp);
		return;
	}

	int y = v[count].first;
	int x = v[count].second;

	if (y == 0 || y == n - 1 || x == 0 || x == n - 1)
		dfs(count + 1, done + 1, v);
	else
	{
		int flag = 1;

		for (int i = 0; i < y; i++)
		{
			if (cell[i][x] != 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			for (int i = 0; i < y; i++)
			{
				cell[i][x] = 2;
			}

			dfs(count + 1, done + 1, v);

			for (int i = 0; i < y; i++)
			{
				cell[i][x] = 0;
			}
		}

		flag = 1;
		for (int i = y + 1; i < n; i++)
		{
			if (cell[i][x] != 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			for (int i = y + 1; i < n; i++)
			{
				cell[i][x] = 2;
			}

			dfs(count + 1, done + 1, v);
			for (int i = y + 1; i < n; i++)
			{
				cell[i][x] = 0;
			}
		}

		flag = 1;
		for (int i = 0; i < x; i++)
		{
			if (cell[y][i] != 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			for (int i = 0; i < x; i++)
				cell[y][i] = 2;
			dfs(count + 1, done + 1, v);
			for (int i = 0; i < x; i++)
				cell[y][i] = 0;
		}

		flag = 1;
		for (int i = x + 1; i < n; i++)
		{
			if (cell[y][i] != 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			for (int i = x + 1; i < n; i++)
				cell[y][i] = 2;
			dfs(count + 1, done + 1, v);
			for (int i = x + 1; i < n; i++)
				cell[y][i] = 0;
		}

		dfs(count + 1, done, v);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		vector<pair<int, int>>core;
		c_num = 0; max_d = 0; result = 200;

		for (int i = 0; i < 100; i++)
			result_arr[i] = 100;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> cell[i][j];
				if (cell[i][j])
				{
					c_num++;
					core.push_back({ i,j });
				}
			}
		}

		dfs(0, 0, core);
		
		for (int i = c_num; i >= 0; i--)
		{
			if (result_arr[i] != 100)
			{
				result = result_arr[i];
				break;
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}