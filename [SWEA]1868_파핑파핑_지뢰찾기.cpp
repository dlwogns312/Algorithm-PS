#include<iostream>
#include<vector>

using namespace std;

int n;
int num[301][301];
int visited[301][301];
char arr[301][301];
int temp;
int dx[8] = {0, -1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1, 1,1,0,-1};
int result;
int show;

int check_bomb(int i, int j)
{
	int ret = 0;

	for (int x = 0; x < 8; x++)
	{
		int temp_x = i + dx[x];
		int temp_y = j + dy[x];
		if (temp_x >= 0 && temp_y >= 0 && temp_x < n && temp_y < n)
			if (arr[temp_x][temp_y] == '*')
				ret++;
	}

	return ret;

}

void dfs(int i, int j)
{
	temp++;

	visited[i][j] = 1;
	if (num[i][j] != 0)
		return;
	for (int x = 0; x < 8; x++)
	{
		int temp_x = i + dx[x];
		int temp_y = j + dy[x];
		if (temp_x >= 0 && temp_y >= 0 && temp_x < n && temp_y < n&&!visited[temp_x][temp_y])
			dfs(temp_x, temp_y);
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		
		vector<pair<int, int>>v;
		result = 0;
		show = 0;
		temp = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				visited[i][j] = 0;
			}
			
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == '.')
				{
					show++;
					num[i][j] = check_bomb(i, j);
					if (!num[i][j])
						v.push_back({ i,j });
				}
				else
					num[i][j] = -1;
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			int temp_x = v[i].first;
			int temp_y = v[i].second;
			if (visited[temp_x][temp_y])
				continue;
			result++;
			dfs(temp_x, temp_y);
			
		}
		
		if (temp != show)
		{
			result += show - temp;
		}
	
		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}