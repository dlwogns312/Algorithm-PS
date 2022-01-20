#include<iostream>
#include<string>
#include<memory.h>
#include<vector>

using namespace std;

#define max(a,b) a>b?a:b
int dp[101][1001];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(dp, 0, sizeof(dp));

		int n, k;
		cin >> n >> k;
		
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (j - v[i - 1].first >= 0)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].first] + v[i - 1].second);
				}
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		cout << "#" << test_case << " " << dp[n][k] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}