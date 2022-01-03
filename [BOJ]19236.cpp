#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>
using namespace std;

typedef struct fish {
	int i;
	int j;
	int dir;
	int check;
};
int map[4][4];

fish arr[17];

vector <pair<int, int>> dir;
int s_result;

void f_move(int s_i,int s_j)
{
	int x, y, temp_dir;
	for (int i = 1; i <= 16; i++)
	{
		if (arr[i].check)
		{
			x = arr[i].i;
			y = arr[i].j;
			temp_dir = arr[i].dir;
			while (1)
			{
				if (temp_dir > 8)
					temp_dir = 1;
				if (x + dir[temp_dir].first == s_i && y + dir[temp_dir].second == s_j)
					temp_dir++;
				else if (x + dir[temp_dir].first < 0 || y + dir[temp_dir].second < 0 || x + dir[temp_dir].first>3 || y + dir[temp_dir].second >3)
					temp_dir++;
				else
					break;
			}



			int temp_x = dir[temp_dir].first + x;
			int temp_y = dir[temp_dir].second + y;
			int temp = map[temp_x][temp_y];

			map[x][y] = temp;
			map[temp_x][temp_y] = i;
			arr[i].i = temp_x;
			arr[i].j = temp_y;
			arr[i].dir = temp_dir;
			arr[temp].i = x;
			arr[temp].j = y;

		}
	}
}
void dfs(int i, int j,int max)
{

	if (i == 0 && j == 0)
		arr[map[i][j]].check = 0;
	if (s_result < max + map[i][j])
		s_result = max + map[i][j];
	fish f_copy[17];
	int m_copy[4][4];

	for (int x = 0; x <= 3; x++)
		for (int y = 0; y <= 3; y++)
			m_copy[x][y] = map[x][y];
	for (int x = 1; x <= 16; x++)
		f_copy[x] = arr[x];

	f_move(i,j);
	int temp_dir = arr[map[i][j]].dir;
	for (int z = 1; z <= 3; z++)
	{
		if (i + z * dir[temp_dir].first >= 0 && i + z * dir[temp_dir].first <= 3 && j + z * dir[temp_dir].second >= 0 && j + z * dir[temp_dir].second <= 3&& arr[map[i + z * dir[temp_dir].first][j + z * dir[temp_dir].second]].check)
		{
			arr[map[i + z * dir[temp_dir].first][j + z * dir[temp_dir].second]].check = 0;
			dfs(i + z * dir[temp_dir].first, j + z * dir[temp_dir].second, max + map[i][j]);
			arr[map[i + z * dir[temp_dir].first][j + z * dir[temp_dir].second]].check = 1;
		}
	}

	for (int x = 0; x <= 3; x++)
		for (int y = 0; y <= 3; y++)
			map[x][y] = m_copy[x][y];
	for (int x = 1; x <= 16; x++)
		arr[x] = f_copy[x];
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	dir.push_back(make_pair(0, 0));
	dir.push_back(make_pair(-1, 0));
	dir.push_back(make_pair(-1, -1));
	dir.push_back(make_pair(0, -1));
	dir.push_back(make_pair(1, -1));
	dir.push_back(make_pair(1, 0));
	dir.push_back(make_pair(1, 1));
	dir.push_back(make_pair(0, 1));
	dir.push_back(make_pair(-1, 1));

	int a, b;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			cin >> a >> b;
			arr[a] = { i,j,b,1 };
			map[i][j] = a;
		}
	
	int s_i = 0, s_j = 0,s_dir=arr[map[0][0]].dir;
	
	s_result = 0;
	
	dfs(0, 0,s_result);
	printf("%d\n", s_result);
}