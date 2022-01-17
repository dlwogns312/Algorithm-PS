
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

#define mod 1000000007

long long dp[10000][16];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		
		long long count = 0;
		memset(dp, 0, sizeof(dp));

		int temp = 1 << (str[0] - 'A');

		for (int i = 1; i < 16; i++)
			if (i & temp && i & 1)
				dp[0][i] = 1;

		for (int start = 1; start < str.size(); start++)
		{
			temp = 1 << (str[start] - 'A');

			for (int i = 1; i < 16; i++)
			{
				if (dp[start - 1][i])
				{
					for(int j=1;j<16;j++)
						if (i & j && j & temp)
						{
							dp[start][j] += dp[start - 1][i];
							dp[start][j] %= mod;
						}
				}
			}
		}
		for (int i = 1; i < 16; i++)
		{
			count += dp[str.size() - 1][i];
			count %= mod;
		}
		printf("#%d %llu\n", test_case, count);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}