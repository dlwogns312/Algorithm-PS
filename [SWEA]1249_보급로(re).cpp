#include<iostream>
#include<string>
#include<queue>

using namespace std;
int n;
int arr[101][101];
int visit[101][101];
int dp[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs()
{
	queue<pair<int, int>> q;
	visit[0][0] = 1;
	dp[0][0] = 0;

	q.push({ 0, 0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int temp_x = x + dx[i];
			int temp_y = y + dy[i];

			if (temp_x >= 0 && temp_y >= 0 && temp_x < n && temp_y < n)
			{
				if (!visit[temp_x][temp_y] || dp[temp_x][temp_y] > dp[x][y] + arr[temp_x][temp_y])
				{
					visit[temp_x][temp_y] = 1;
					dp[temp_x][temp_y] = dp[x][y] + arr[temp_x][temp_y];
					q.push({ temp_x,temp_y });
				}
			}
		}
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		string str;
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = str[j] - '0';
				visit[i][j] = 0;
			}
		}
		bfs();

		cout << "#" << test_case << " " << dp[n-1][n-1] << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}