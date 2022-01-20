#include<iostream>
#include<string>
#include<memory.h>
#include<vector>
#include<algorithm>

using namespace std;


int arr[3001];
int arr1[101];
int dp[3001][101][101][2];

bool compare(int a, int b)
{
	return a > b;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	int n,m;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> arr1[i];

		sort(arr1, arr1 + m, compare);

		memset(dp, 0, sizeof(dp));

		dp[0][0][1][1] = arr1[0];

		for (int i = 1; i <= m / 2; i++)
		{
			dp[0][i][i][0] = dp[0][i - 1][i - 1][0] + arr1[i - 1];
			dp[0][i][i + 1][1] = dp[0][i][i][0] + arr1[i];
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				for (int k = 0; k <= m - j; k++)
				{
					dp[i][j][k][1] = dp[i - 1][j][k][0] + arr[i - 1];
					if(j>0)
					{
						dp[i][j][k][1] = max(dp[i][j][k][1], max(dp[i - 1][j - 1][k][0], dp[i - 1][j - 1][k][1]) + arr[i - 1]);
					}
					if (k > 0)
					{
						dp[i][j][k][1] = max(dp[i][j][k][1], max(dp[i - 1][j][k - 1][0], dp[i - 1][j][k - 1][1]) + arr1[k - 1]);
					}
					dp[i][j][k][0] = max(dp[i - 1][j][k][0], dp[i - 1][j][k][1]);
				}
			}
		}

		int result = 0;
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= m - i; j++)
			{
				result = max(result, max(dp[n][i][j][0] + (i + j < m ? arr1[j] : 0), dp[n][i][j][1]));
			}
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}