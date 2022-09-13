#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int ret = 0;
int n;

vector<vector<int>>  dfs_up( vector<vector<int>> arr);
vector<vector<int>>  dfs_down(vector<vector<int>> arr);
vector<vector<int>>  dfs_left( vector<vector<int>> arr);
vector<vector<int>>  dfs_right(vector<vector<int>> arr);

void print(vector<vector<int>> arr)
{
	cout << "---------------------------------------\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}

}
//move numbers upside
vector<vector<int>>  dfs_up( vector<vector<int>> arr)
{
	int check = 0;

	int put = 0;
	//push up
	for (int i = 0; i < n; i++)
	{
		put = 0;
		for (int j = 0; j < n; j++)
			if (arr[j][i])
			{
				if (put < j)
				{
					arr[put][i] = arr[j][i];
					arr[j][i] = 0;
				}
				put++;
			}
	}
	//Merge same numbers
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] && (arr[i][j] == arr[i + 1][j]))
			{
				arr[i][j] += arr[i + 1][j];
				ret = max(ret, arr[i][j]);
				arr[i + 1][j] = 0;
				check = 1;
			}
	//push up again
	for (int i = 0; i < n; i++)
	{
		put = 0;
		for (int j = 0; j < n; j++)
			if (arr[j][i])
			{
				if (put < j)
				{
					arr[put][i] = arr[j][i];
					arr[j][i] = 0;
				}
				put++;
			}
	}

	/*cout << "--------------------------------\n";
	cout << num << " " << "up\n";
	print(arr);*/
	
	return arr;
}

//move numbers downside
vector<vector<int>> dfs_down( vector<vector<int>> arr)
{
	int check = 0;


	int put;

	//push down
	for (int i = 0; i < n; i++)
	{
		put = n - 1;
		for (int j = n - 1; j >= 0; j--)
			if (arr[j][i])
			{
				if (put > j)
				{
					arr[put][i] = arr[j][i];
					arr[j][i] = 0;
				}
				put--;
			}
	}
	//Merge same numbers
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < n; j++)
			if (arr[i][j] && (arr[i][j] == arr[i - 1][j]))
			{
				arr[i][j] += arr[i - 1][j];
				ret = max(ret, arr[i][j]);
				arr[i - 1][j] = 0;
				check = 1;
			}
	//push down again
	for (int i = 0; i < n; i++)
	{
		put = n - 1;
		for (int j = n - 1; j >= 0; j--)
			if (arr[j][i])
			{
				if (put > j)
				{
					arr[put][i] = arr[j][i];
					arr[j][i] = 0;
				}
				put--;
			}
	}

	/*cout << "--------------------------------\n";
	cout << num << " " << "down\n";
	print(arr);*/
	
	return arr;

}

//move numbers leftside
vector<vector<int>>  dfs_left( vector<vector<int>> arr)
{
	int check = 0;


	int put;
	//push left
	for (int i = 0; i < n; i++)
	{
		put = 0;
		for (int j = 0; j < n; j++)
			if (arr[i][j])
			{
				if (put < j)
				{
					arr[i][put] = arr[i][j];
					arr[i][j] = 0;
				}
				put++;
			}
	}

	//merge same numbers
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			if (arr[j][i] && (arr[j][i] == arr[j][i + 1]))
			{
				arr[j][i] += arr[j][i + 1];
				ret = max(arr[j][i], ret);
				arr[j][i + 1] = 0;
				check = 1;
			}

	//push left again
	for (int i = 0; i < n; i++)
	{
		put = 0;
		for (int j = 0; j < n; j++)
			if (arr[i][j])
			{
				if (put < j)
				{
					arr[i][put] = arr[i][j];
					arr[i][j] = 0;
				}
				put++;
			}
	}

	/*cout << "--------------------------------\n";
	cout << num << " " << "left\n";
	print(arr);*/
	return arr;
}

//move numbers rightside
vector<vector<int>> dfs_right(vector<vector<int>> arr)
{
	int check = 0;

	int put;
	//push right
	for (int i = 0; i < n; i++)
	{
		put = n - 1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (arr[i][j])
			{
				if (put > j)
				{
					arr[i][put] = arr[i][j];
					arr[i][j] = 0;
				}
				put--;
			}
		}
	}

	//merge same numbers
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < n; j++)
			if (arr[j][i] && (arr[j][i] == arr[j][i - 1]))
			{
				arr[j][i] += arr[j][i - 1];
				ret = max(arr[j][i], ret);
				arr[j][i - 1] = 0;
				check = 1;
			}

	//push right again
	for (int i = 0; i < n; i++)
	{
		put = n - 1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (arr[i][j])
			{
				if (put > j)
				{
					arr[i][put] = arr[i][j];
					arr[i][j] = 0;
				}
				put--;
			}
		}
	}

	/*cout << "--------------------------------\n";
	cout << num << " " << "right\n";
	print(arr);*/
	

	return arr;
}

void dfs(int level,vector<vector<int>> arr)
{
	if (level == 5)
		return;
	dfs(level + 1, dfs_up(arr));
	dfs(level + 1, dfs_down(arr));
	dfs(level + 1, dfs_left(arr));
	dfs(level + 1, dfs_right(arr));
}
int main()
{
	cin >> n;
	vector<vector<int>> arr(21,vector<int>(21,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			ret = max(ret, arr[i][j]);
		}

	dfs(0, arr);

	cout << ret << "\n";
}