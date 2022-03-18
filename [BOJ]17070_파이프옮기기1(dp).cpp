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
int dp[3][17][17];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	
	
	dp[0][1][1] = 1;
	dp[0][1][2] = 1;

	for(int i=1;i<=n;i++)
		for (int j = 3; j <= n; j++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (arr[i][j])
				{
					dp[x][i][j] = 0;
					continue;
				}
				if (x == 0)
				{
					dp[x][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
				}
				else if (x == 1)
				{
					dp[x][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
				}
				else
				{
					if (arr[i][j - 1] || arr[i - 1][j])
					{
						dp[x][i][j] = 0;
						continue;
					}
					dp[x][i][j] = dp[0][i-1][j - 1] + dp[1][i - 1][j-1] + dp[2][i - 1][j - 1];
				}
			}
		}
	
	cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n] << "\n";
}