#include<iostream>
#include<string>
#include<memory.h>
using namespace std;

#define max(a,b) a>b?a:b
int dp[1001][1001];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(dp, 0, sizeof(dp));

		string a, b;

		cin >> a >> b;

	
		for (int i = 1; i <= a.length(); i++)
		{
			for (int j = 1; j <= b.length(); j++)
			{
				if (a[i-1] == b[j-1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1] );
			}
		}

		cout << "#" << test_case <<" "<< dp[a.length()][b.length()] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}