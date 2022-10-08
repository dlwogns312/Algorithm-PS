#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <cstring>

using namespace std;

#define INF 9999

int d, w, k;
int cell[14][21];
int ret;

int check_done(int arr[14][21])
{
	for (int i = 0; i < w; i++)
	{
		int now_num=arr[0][i], num = 1;
		int flag = 0;
		for (int j = 1; j < d; j++)
		{
			if (now_num == arr[j][i])
			{
				num++;
				if (num >= k)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				now_num = arr[j][i];
				num = 1;
			}
		}
		if (!flag)
			return 0;
	}

	return 1;
}

void dfs(int level,int arr[14][21],int now)
{
	if (level > k)
		return;

	if (check_done(arr)||k==1)
		ret = min(ret, level);

	if (level >= ret)
		return;

	for (int i = now; i < d; i++)
	{
		int tmp[21];
		for (int j = 0; j < w; j++)
		{
			tmp[j] = arr[i][j];
			arr[i][j] = 0;
		}
		dfs(level + 1, arr, i+1);
		for (int j = 0; j < w; j++)
			arr[i][j] = 1;
		dfs(level + 1, arr, i+1);
		for (int j = 0; j < w; j++)
			arr[i][j] = tmp[j];
	}
	
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		//Initialize
		cin >> d >> w >> k;
		ret = INF;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++)
				cin >> cell[i][j];

		dfs(0,cell,0);

		cout << "#" << i << " " << ret << "\n";
	}
}